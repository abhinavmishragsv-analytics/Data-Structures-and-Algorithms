#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input. Exiting.\n");
        exit(1);
    }
    if (data == -1)
        return NULL;
    struct Node* root = createNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = createTree();
    printf("Enter right child of %d:\n", data);
    root->right = createTree();
    return root;
}
int main() {
    struct Node* root = NULL;
    printf("Create the Binary Tree:\n");
    root = createTree();
    printf("\nBinary Tree Created Successfully!\n");
    return 0;
}
