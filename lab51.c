#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert %d\n", val);
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = val;
    printf("Enqueued %d at position %d\n", val, rear);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No element to dequeue.\n");
        return;
    }
    printf("Dequeued %d from position %d\n", queue[front], front);
    front++;
}
void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    int choice, val;
    printf("=== LINEAR QUEUE IMPLEMENTATION ===\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
