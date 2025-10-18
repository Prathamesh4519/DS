#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insertBST(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);  
    }

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }
   
    return root;
}
void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}



int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertBST(root, value);
    }

    printf("BST Inorder Traversal (Sorted): ");
    inorder(root);

    return 0;
}

