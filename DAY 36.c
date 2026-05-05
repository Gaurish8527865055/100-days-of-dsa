#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;   // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;   // maintain circular link
    }
}

void rotate() {
    if (front == NULL) return;

    front = front->next;
    rear = rear->next;
}

void display() {
    if (front == NULL) return;

    struct Node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        rotate();   // simulate dequeue and circular shift
    }

    display();

    return 0;
}