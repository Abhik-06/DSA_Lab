#include <stdio.h>
#include <string.h>

#define MAX 27

// Stack data
char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

// Pop function
char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Reverses the string using push and pop
void StringReverse(char word[], int length) {
    // Push all characters onto the stack
    for (int i = 0; i < length; i++) {
        push(word[i]);
    }

    // Pop characters back into the string (in reverse order)
    for (int i = 0; i < length; i++) {
        word[i] = pop();
    }
}

int main() {
    int letters;
    char word[MAX];

    printf("Enter the number of letters in the word: ");
    scanf("%d", &letters);

    if (letters >= MAX) {
        printf("Too many letters! Choose a number between 1 and 26\n");
        return 0;
    } else if (letters <= 1) {
        printf("Too few letters! Choose a number between 2 and 26\n");
        return 0;
    } else {
        printf("Enter the word: ");
        scanf("%s", word);
    }

    StringReverse(word, letters);

    printf("The reversed word is: %s\n", word);
    return 0;
}
