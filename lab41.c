#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}
char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}
int isBalanced(char exp[]) {
    top = -1; 
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            char ch = pop();
            if ((exp[i] == ')' && ch != '(') ||
                (exp[i] == '}' && ch != '{') ||
                (exp[i] == ']' && ch != '['))
                return 0;
        }
    }
    return (top == -1);
}
int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    gets(exp);
    if (isBalanced(exp))
        printf(" Parentheses are Balanced.\n");
    else
        printf("Parentheses are NOT Balanced.\n");

    return 0;
}