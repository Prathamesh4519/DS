#include <stdio.h>
#include <stdlib.h>

// Define the binary tree node structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Utility function to find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive helper function to build the tree
struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    // Pick current node from preorder traversal
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = newNode(rootVal);

    // If the node has no children
    if (inStart == inEnd)
        return root;

    // Find the index of this node in inorder
    int inIndex = search(inorder, inStart, inEnd, rootVal);

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Main function to build the tree
struct TreeNode* buildTree(int preorder[], int inorder[], int length) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, length - 1, &preIndex);
}

// Utility function for inorder traversal (for testing)
void printInorder(struct TreeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->val);
        printInorder(root->right);
    }
}
