#include <stdio.h>
#include <stdlib.h>
struct StackNode {
    int data;
    struct StackNode *next;
};
struct StackNode *top = NULL;
void push(int data) {
    struct StackNode *newNode = malloc(sizeof(struct StackNode));
    if (!newNode) return;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
void pop() {
    if (!top) { printf("Stack Underflow!\n"); return; }
    struct StackNode *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}
void displayStack() {
    struct StackNode *t = top;
    if (!t) { printf("Stack empty.\n"); return; }
    printf("Stack: ");
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}
struct QueueNode {
    int data;
    struct QueueNode *next;
};
struct QueueNode *front = NULL, *rear = NULL;
void enqueue(int data) {
    struct QueueNode *newNode = malloc(sizeof(struct QueueNode));
    if (!newNode) return;
    newNode->data = data;
    newNode->next = NULL;
    if (!rear) front = rear = newNode;
    else { rear->next = newNode; rear = newNode; }
}
void dequeue() {
    if (!front) { printf("Queue Underflow!\n"); return; }
    struct QueueNode *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    if (!front) rear = NULL;
    free(temp);
}
void displayQueue() {
    struct QueueNode *t = front;
    if (!t) { printf("Queue empty.\n"); return; }
    printf("Queue: ");
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}
int main() {
    int choice, data;
    while (1) {
        printf("\n1.Push  2.Pop  3.Display Stack\n");
        printf("4.Enqueue  5.Dequeue  6.Display Queue\n7.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter data: "); scanf("%d", &data); push(data); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: printf("Enter data: "); scanf("%d", &data); enqueue(data); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: exit(0);
            default: printf("Invalid!\n");
        }
    }
}
