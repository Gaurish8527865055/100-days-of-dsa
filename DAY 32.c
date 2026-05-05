#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, i;

    // Read number of elements
    scanf("%d", &n);

    // Push elements into stack
    for(i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        stack[++top] = value;
    }

    // Read number of pops
    scanf("%d", &m);

    // Perform pop operations
    for(i = 0; i < m; i++) {
        if(top == -1) {
            printf("Stack Underflow\n");
            break;
        }
        top--;
    }

    // Print remaining elements from top to bottom
    while(top != -1) {
        printf("%d ", stack[top]);
        top--;
    }

    return 0;
}