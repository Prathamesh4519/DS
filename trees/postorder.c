#include <stdio.h>
#include <stdlib.h>

// Define the binary tree node structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find the index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive helper to build tree
struct TreeNode* buildTreeHelper(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    // If it's a leaf node
    if (inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, rootVal);

    // Build right subtree before left
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Main function to build tree
struct TreeNode* buildTree(int inorder[], int postorder[], int length) {
    int postIndex = length - 1;
    return buildTreeHelper(inorder, postorder, 0, length - 1, &postIndex);
}

// Inorder traversal to test
void printInorder(struct TreeNode* root) {
    if (root) {
        printInorder(root->left);
        printf("%d ", root->val);
        printInorder(root->right);
    }
}
