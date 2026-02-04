#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}
void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("\nCircular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}
void insertAfterNode(int key, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        if (temp->data == key) {
            struct Node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with data %d not found.\n", key);
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *last = head;
    while (last->next != head)
        last = last->next;
    head = head->next;
    last->next = head;
    free(temp);
}
void deleteSpecific(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *curr = head, *prev = NULL;
    do {
        if (curr->data == key) {
            if (curr == head && curr->next == head) { 
                head = NULL;
                free(curr);
                return;
            }
            if (curr == head) { 
                struct Node *last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
                free(curr);
                return;
            }
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    printf("Node with data %d not found.\n", key);
}
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}
int main() {
    int choice, data, key;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete a Specific Node\n");
        printf("6. Delete at End\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter new data: ");
                scanf("%d", &data);
                insertAfterNode(key, data);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                deleteSpecific(key);
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}