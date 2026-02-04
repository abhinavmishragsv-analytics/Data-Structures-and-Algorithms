#include <stdio.h>
#define MAX 5

int pq[MAX];
int size = 0;
void enqueue(int val) {
    if (size == MAX) {
        printf("\nQueue Overflow! Cannot insert %d\n", val);
        return;
    }
    pq[size++] = val;
    printf("Inserted %d into priority queue.\n", val);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            printf("Comparing %d and %d\n", pq[j], pq[j + 1]);
            if (pq[j] > pq[j + 1]) {
                int temp = pq[j];
                pq[j] = pq[j + 1];
                pq[j + 1] = temp;
                printf("Swapped %d and %d\n", pq[j], pq[j + 1]);
            }
        }
        printf("Pass %d completed.\n", i + 1);
    }
}
void dequeue() {
    if (size == 0) {
        printf("\nQueue Underflow! No element to dequeue.\n");
        return;
    }
    printf("Dequeued element with highest priority: %d\n", pq[0]);
    for (int i = 1; i < size; i++)
        pq[i - 1] = pq[i];
    size--;
}
void display() {
    if (size == 0) {
        printf("\nPriority Queue is empty.\n");
        return;
    }
    printf("\nPriority Queue elements (Lowest number = Highest priority): ");
    for (int i = 0; i < size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}
int main() {
    int choice, val;
    printf("=== PRIORITY QUEUE IMPLEMENTATION ===\n");
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
