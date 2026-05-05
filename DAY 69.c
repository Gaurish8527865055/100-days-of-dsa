#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 1000
#define INF INT_MAX

// ---------- Adjacency List ----------
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

Node* adj[MAXV];

// Add directed edge u -> v with weight w
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// ---------- Min Heap ----------
typedef struct HeapNode {
    int vertex, dist;
} HeapNode;

typedef struct MinHeap {
    int size;
    HeapNode arr[MAXV * MAXV];
} MinHeap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->arr[parent].dist <= heap->arr[idx].dist) break;
        swap(&heap->arr[parent], &heap->arr[idx]);
        idx = parent;
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < heap->size &&
            heap->arr[left].dist < heap->arr[smallest].dist)
            smallest = left;

        if (right < heap->size &&
            heap->arr[right].dist < heap->arr[smallest].dist)
            smallest = right;

        if (smallest == idx) break;

        swap(&heap->arr[idx], &heap->arr[smallest]);
        idx = smallest;
    }
}

void push(MinHeap* heap, int vertex, int dist) {
    heap->arr[heap->size].vertex = vertex;
    heap->arr[heap->size].dist = dist;
    heapifyUp(heap, heap->size);
    heap->size++;
}

HeapNode pop(MinHeap* heap) {
    HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

// ---------- Dijkstra ----------
void dijkstra(int V, int source) {
    int dist[MAXV];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    MinHeap heap = {0};
    push(&heap, source, 0);

    while (heap.size > 0) {
        HeapNode curr = pop(&heap);
        int u = curr.vertex;

        if (curr.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        printf("Distance from %d to %d = %d\n", source, i, dist[i]);
    }
}

// ---------- Driver ----------
int main() {
    int V = 5;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);
    addEdge(3, 2, 4);
    addEdge(2, 3, 6);

    dijkstra(V, 0);

    return 0;
}