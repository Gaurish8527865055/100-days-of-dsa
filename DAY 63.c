#include <stdio.h>
#include <stdlib.h>

// DFS function
void dfs(int node, int** adj, int* adjSize, int* visited) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, adjSize, visited);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)malloc(n * sizeof(int));

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        int k; // number of neighbors
        scanf("%d", &k);

        adjSize[i] = k;
        adj[i] = (int*)malloc(k * sizeof(int));

        for (int j = 0; j < k; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s; // starting vertex
    scanf("%d", &s);

    int* visited = (int*)calloc(n, sizeof(int));

    // Perform DFS
    dfs(s, adj, adjSize, visited);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(visited);

    return 0;
}