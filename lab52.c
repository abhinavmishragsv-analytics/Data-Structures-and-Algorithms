#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("\nQueue Overflow! Cannot insert %d\n", val);
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;
    cqueue[rear] = val;
    printf("Enqueued %d at position %d\n", val, rear);
}
void dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow! No element to dequeue.\n");
        return;
    }
    printf("Dequeued %d from position %d\n", cqueue[front], front);

    if (front == rear)
        front = rear = -1; 
    else
        front = (front + 1) % MAX;
}
void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nCircular Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice, val;
    printf("=== CIRCULAR QUEUE IMPLEMENTATION ===\n");
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
