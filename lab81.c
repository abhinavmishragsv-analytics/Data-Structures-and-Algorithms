#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* createBST() {
    struct Node *root = NULL, *newNode, *temp;
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = createNode(data);
        if (root == NULL)
            root = newNode;
        else {
            temp = root;
            struct Node *parent;
            while (temp != NULL) {
                parent = temp;
                if (data < temp->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if (data < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }
    }
    return root;
}
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    struct Node* root = createBST();
    printf("\nInorder traversal of created BST: ");
    inorder(root);
    printf("\n");
    return 0;
}