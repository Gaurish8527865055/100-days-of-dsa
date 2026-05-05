#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue Node (for BFS with horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    struct QNode arr[2000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->rear++;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Map using array (offset for negative index)
    int map[4000][200];   // store nodes per HD
    int count[4000] = {0};

    int offset = 2000; // to handle negative HD
    int minHD = 0, maxHD = 0;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int idx = hd + offset;
        map[idx][count[idx]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            enqueue(&q, curr->left, hd - 1);
        if (curr->right)
            enqueue(&q, curr->right, hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}