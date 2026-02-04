#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
char peek() {
    if (top == -1)
        return '\0';
    else
        return stack[top];
}
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
void reverse(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}
void infixToPrefix(char infix[], char prefix[]) {
    char temp[MAX];
    int j = 0;
    top = -1;
    reverse(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c))
            temp[j++] = c;
        else if (c == ')')
            push(c);
        else if (c == '(') {
            while (top != -1 && peek() != ')')
                temp[j++] = pop();
            pop(); 
        } else {
            while (top != -1 && precedence(peek()) > precedence(c))
                temp[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
    temp[j++] = pop();
    temp[j] = '\0';
    reverse(temp);
    strcpy(prefix, temp);
}
int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    gets(infix);
    infixToPrefix(infix, prefix);
    printf(" Prefix Expression: %s\n", prefix);
    return 0;
}