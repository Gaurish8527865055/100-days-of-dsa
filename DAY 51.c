#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        
        // both nodes in left subtree
        if (p < root->data && q < root->data)
            root = root->left;
        
        // both nodes in right subtree
        else if (p > root->data && q > root->data)
            root = root->right;
        
        // split point → LCA
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, x, p, q;
    struct Node* root = NULL;

    // Input
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &p, &q);

    // Find LCA
    struct Node* lca = findLCA(root, p, q);

    // Output
    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}