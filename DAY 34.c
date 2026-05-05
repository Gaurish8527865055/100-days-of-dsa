#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* exp) {
    char* token = strtok(exp, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        } 
        else {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expression[100];

    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;

    int result = evaluatePostfix(expression);
    printf("%d", result);

    return 0;
}