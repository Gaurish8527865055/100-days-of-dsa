#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;

/* Check if deque is empty */
int empty() {
    return (front == -1);
}

/* Return size */
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

/* Push front */
void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front > 0) {
        deque[--front] = x;
    }
    else {
        printf("Deque overflow\n");
    }
}

/* Push back */
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

/* Pop front */
void pop_front() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }

    printf("Removed %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

/* Pop back */
void pop_back() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }

    printf("Removed %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

/* Get front element */
int get_front() {
    if (empty()) return -1;
    return deque[front];
}

/* Get back element */
int get_back() {
    if (empty()) return -1;
    return deque[rear];
}

/* Clear deque */
void clear() {
    front = rear = -1;
}

/* Reverse deque */
void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

/* Sort deque */
void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

/* Display deque */
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    printf("Deque: ");
    display();

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());

    pop_front();
    pop_back();

    printf("After pop: ");
    display();

    printf("Size: %d\n", size());

    reverse();
    printf("After reverse: ");
    display();

    sort();
    printf("After sort: ");
    display();

    clear();
    printf("After clear: ");
    display();

    return 0;
}