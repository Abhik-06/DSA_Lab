#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 200

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; 
            i--; 
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            pop(); 
        }
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }
    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; 

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
