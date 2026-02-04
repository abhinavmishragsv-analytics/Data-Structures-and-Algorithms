#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1, size;
void create() {
    printf("Enter size of stack (max 100): ");
    scanf("%d", &size);
    if (size > 100 || size <= 0) {
        printf("Invalid size! Setting to 100.\n");
        size = 100;
    }
    top = -1;
    printf("Stack created with size %d.\n", size);
}
void push() {
    int val;
    if (top == size - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter element to push: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("%d pushed.\n", val);
    }
}
void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("%d popped.\n", stack[top--]);
}
void peek() {
    if (top == -1)
        printf("Stack is empty.\n");
    else
        printf("Top element: %d\n", stack[top]);
}
void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n1.Create  2.Push  3.Pop  4.Peek  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}