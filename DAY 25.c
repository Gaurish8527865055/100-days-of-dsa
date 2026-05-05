#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value, key;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    // Input number of nodes
    scanf("%d", &n);
    
    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        
        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    // Input key to count
    scanf("%d", &key);
    
    // Count occurrences
    int count = 0;
    temp = head;
    
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    
    // Output result
    printf("%d", count);
    
    return 0;
}