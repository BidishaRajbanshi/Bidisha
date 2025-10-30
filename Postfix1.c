#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int val) {
    stack[++top] = val;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char* exp) {
    int i;
    for (i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else if (exp[i] == ' ') {
            continue;
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}
int main() {
    char exp[MAX];
    printf("Enter postfix expression (single-digit operands, space separated): ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = 0; // Remove newline
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}
