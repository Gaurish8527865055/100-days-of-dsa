#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
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

// Add directed edge u -> v
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* temp = newNode(v);
    temp->next = adj[u];
    adj[u] = temp;
}

// DFS for topological sort
void topoDFS(int node, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        if (!visited[temp->data]) {
            topoDFS(temp->data, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX] = {NULL};
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Run DFS from all unvisited nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoDFS(i, adj, visited, stack, &top);
        }
    }

    // Print topological order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}