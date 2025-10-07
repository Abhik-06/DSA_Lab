#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Node structure for expression tree
struct node {
    char data;
    struct node* left;
    struct node* right;
};

// Stack for expression tree nodes (used in building tree)
struct stacknode {
    struct node* data;
    struct stacknode* next;
};

// Function prototypes
struct node* CreateNode(char data);
void Push(struct stacknode** stack, struct node* newnode);
struct node* Pop(struct stacknode** stack);
struct node* BuildExpressionTreeFromPostfix(char* postfix);
void InfixDisplay(struct node* root);
void PrefixDisplay(struct node* root);
void PostfixDisplay(struct node* root);

void InfixToPostfix(char* infix, char* postfix);
void PrefixToPostfix(char* prefix, char* postfix);

// Helper functions for InfixToPostfix
int precedence(char op);
int isOperator(char c);

// Stack for InfixToPostfix operators
char operatorStack[MAX];
int opTop = -1;
void pushOp(char c);
char popOp();
char peekOp();

int main() {
    int choice = 1;
    char expression[MAX];
    char postfix[MAX];
    struct node* root = NULL;

    printf("Expression Tree Builder\n");

    while (choice == 1) {
        printf("\nEnter the type of expression:\n");
        printf("1 for infix\n2 for prefix\n3 for postfix\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            break;
        }
        getchar(); // consume newline after scanf

        printf("Enter the expression: ");
        fgets(expression, MAX, stdin);
        expression[strcspn(expression, "\n")] = 0; // remove newline

        // Convert expression to postfix if needed
        if (choice == 1) {
            // Infix to postfix conversion
            InfixToPostfix(expression, postfix);
            printf("Converted Postfix: %s\n", postfix);
        } else if (choice == 2) {
            // Prefix to postfix conversion
            PrefixToPostfix(expression, postfix);
            printf("Converted Postfix: %s\n", postfix);
        } else if (choice == 3) {
            // Postfix directly
            strcpy(postfix, expression);
        } else {
            printf("Invalid choice!\n");
            continue;
        }

        // Build expression tree from postfix
        root = BuildExpressionTreeFromPostfix(postfix);

        // Display traversals
        printf("Infix expression: ");
        InfixDisplay(root);
        printf("\n");

        printf("Prefix expression: ");
        PrefixDisplay(root);
        printf("\n");

        printf("Postfix expression: ");
        PostfixDisplay(root);
        printf("\n");

        printf("\nDo you wish to run again? (1 for yes / 0 for no): ");
        scanf("%d", &choice);
        getchar(); // consume newline
    }

    printf("Thank you for using the program!\n");
    return 0;
}

// Create new tree node
struct node* CreateNode(char data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Stack push/pop for expression tree nodes
void Push(struct stacknode** stack, struct node* newnode) {
    struct stacknode* newstacknode = (struct stacknode*)malloc(sizeof(struct stacknode));
    newstacknode->data = newnode;
    newstacknode->next = *stack;
    *stack = newstacknode;
}

struct node* Pop(struct stacknode** stack) {
    if (*stack == NULL) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    struct stacknode* temp = *stack;
    struct node* popped = temp->data;
    *stack = temp->next;
    free(temp);
    return popped;
}

// Build expression tree from postfix expression
struct node* BuildExpressionTreeFromPostfix(char* postfix) {
    struct stacknode* stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (c == ' ') continue; // skip spaces

        if (isalnum(c)) {
            // Operand: push as node
            Push(&stack, CreateNode(c));
        } else if (isOperator(c)) {
            // Operator: pop two nodes, create new node, push back
            struct node* right = Pop(&stack);
            struct node* left = Pop(&stack);
            struct node* newnode = CreateNode(c);
            newnode->left = left;
            newnode->right = right;
            Push(&stack, newnode);
        }
    }
    struct node* root = Pop(&stack);
    if (stack != NULL) {
        printf("Invalid Expression!\n");
        exit(1);
    }
    return root;
}

// Display functions

void InfixDisplay(struct node* root) {
    if (root == NULL) return;

    // If node is operator, print parentheses for clarity
    if (isOperator(root->data)) printf("(");

    InfixDisplay(root->left);
    printf("%c", root->data);
    InfixDisplay(root->right);

    if (isOperator(root->data)) printf(")");
}

void PrefixDisplay(struct node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    PrefixDisplay(root->left);
    PrefixDisplay(root->right);
}

void PostfixDisplay(struct node* root) {
    if (root == NULL) return;
    PostfixDisplay(root->left);
    PostfixDisplay(root->right);
    printf("%c", root->data);
}

// --- Infix to Postfix Conversion ---

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void pushOp(char c) {
    operatorStack[++opTop] = c;
}

char popOp() {
    if (opTop == -1) return '\0';
    return operatorStack[opTop--];
}

char peekOp() {
    if (opTop == -1) return '\0';
    return operatorStack[opTop];
}

void InfixToPostfix(char* infix, char* postfix) {
    opTop = -1; // reset operator stack
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (c == ' ') continue;

        if (isalnum(c)) {
            postfix[j++] = c; // operand goes directly
        } else if (c == '(') {
            pushOp(c);
        } else if (c == ')') {
            while (opTop != -1 && peekOp() != '(')
                postfix[j++] = popOp();
            popOp(); // remove '('
        } else if (isOperator(c)) {
            while (opTop != -1 && precedence(peekOp()) >= precedence(c))
                postfix[j++] = popOp();
            pushOp(c);
        } else {
            printf("Invalid character in expression: %c\n", c);
            exit(1);
        }
    }
    while (opTop != -1)
        postfix[j++] = popOp();

    postfix[j] = '\0';
}

// --- Prefix to Postfix Conversion ---

void PrefixToPostfix(char* prefix, char* postfix) {
    // Using stack of strings for operands
    char stack[MAX][MAX];
    int top = -1;

    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c == ' ') continue;

        if (isalnum(c)) {
            char operand[2] = {c, '\0'};
            strcpy(stack[++top], operand);
        } else if (isOperator(c)) {
            if (top < 1) {
                printf("Invalid prefix expression\n");
                exit(1);
            }
            char op1[MAX], op2[MAX], temp[MAX];
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            snprintf(temp, MAX, "%s%s%c", op1, op2, c);
            strcpy(stack[++top], temp);
        } else {
            printf("Invalid character in expression: %c\n", c);
            exit(1);
        }
    }

    if (top != 0) {
        printf("Invalid prefix expression\n");
        exit(1);
    }

    strcpy(postfix, stack[top]);
}
