#include <stdio.h>
#include <stdlib.h>

// Tree structure
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

// Create new node
struct TreeNode {
struct TreeNode* newNode(int val): {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
};

// Mirror function
void mirror(struct TreeNode* root) {
    if (root == NULL) return;

    // Swap left and right
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}