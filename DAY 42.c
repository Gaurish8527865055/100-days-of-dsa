#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int stack[MAX];
int top = -1;

void enqueue(int x){
    queue[++rear] = x;
}

int dequeue(){
    return queue[front++];
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        enqueue(x);
    }

    /* Step 1: Move queue elements to stack */
    while(front <= rear){
        push(dequeue());
    }

    /* Step 2: Move stack elements back to queue */
    while(top != -1){
        enqueue(pop());
    }

    /* Print reversed queue */
    while(front <= rear){
        printf("%d ", dequeue());
    }

    return 0;
}