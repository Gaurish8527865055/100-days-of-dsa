#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* temp = newNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

// DFS function
bool dfs(int node, int parent, bool visited[], struct Node* adj[]) {
    visited[node] = true;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }

        temp = temp->next;
    }
    return false;
}

// Cycle detection
bool hasCycle(int V, struct Node* adj[]) {
    bool visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}