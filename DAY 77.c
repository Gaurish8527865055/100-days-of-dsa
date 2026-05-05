#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int *adj[MAX];
int adjSize[MAX];
int visited[MAX];

// Add edge
void addEdge(int u, int v) {
    adj[u] = realloc(adj[u], (adjSize[u] + 1) * sizeof(int));
    adj[u][adjSize[u]++] = v;
}

// DFS
void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        adjSize[i] = 0;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    // Run DFS from node 1
    dfs(1);

    // Check if all nodes visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}