#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL;
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nDoubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL)
        head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAfter(int key, int data) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}
void deleteAtEnd() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
}
void deleteSpecific(int key) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}
int main() {
    int choice, data, key;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete a Specific Node\n");
        printf("7. Display\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter data: "); scanf("%d", &data); insertAtBeginning(data); break;
            case 2: printf("Enter data: "); scanf("%d", &data); insertAtEnd(data); break;
            case 3: printf("Enter node value: "); scanf("%d", &key); printf("Enter data: "); scanf("%d", &data); insertAfter(key, data); break;
            case 4: deleteAtBeginning(); break;
            case 5: deleteAtEnd(); break;
            case 6: printf("Enter data to delete: "); scanf("%d", &key); deleteSpecific(key); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}