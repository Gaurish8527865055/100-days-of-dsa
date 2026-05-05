#include <stdio.h>
#include <stdlib.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree
struct TreeNode* build(int inorder[], int postorder[],
                       int inStart, int inEnd, int* postIndex) {

    if (inStart > inEnd)
        return NULL;

    // Root from postorder
    int val = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(val);

    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == val)
            break;
    }

    // Build RIGHT first
    root->right = build(inorder, postorder, index + 1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct TreeNode* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}