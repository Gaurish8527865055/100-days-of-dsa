#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find intersection
void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;

    while (temp1 != NULL) {
        struct Node* temp2 = head2;

        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                printf("%d", temp1->data);
                return;
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

    findIntersection(head1, head2);

    return 0;
}