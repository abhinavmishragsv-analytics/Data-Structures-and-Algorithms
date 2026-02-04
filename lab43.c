#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;
void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }
int evalPrefix(char prefix[]) {
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; ) {
        if (isdigit(prefix[i])) {
            int num = 0, place = 1;
            while (i >= 0 && isdigit(prefix[i])) {
                num = num + (prefix[i] - '0') * place;
                place *= 10;
                i--;
            }
            push(num);
        } else if (prefix[i] == ' ') {
            i--;
        } else {
            int a = pop();
            int b = pop();
            switch (prefix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
            i--;
        }
    }
    return pop();
}
int main() {
    char prefix[MAX];
    printf("Enter prefix expression:");
    fgets(prefix, MAX, stdin);
    prefix[strcspn(prefix, "\n")] = '\0';
    printf(" Result = %d\n", evalPrefix(prefix));
    return 0;
}