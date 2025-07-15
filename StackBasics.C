#include <stdio.h>

void push(int stack[], int *top);
void pop(int stack[], int *top);
void peak(int stack[], int *top);

int main() {
    int temp;
    int stack[5];
    int choice;
    int play = 1;
    int top = 0;

    while(play == 1) {
        printf("\nEnter the function to perform:\n1 for push\n2 for pop\n3 for peak\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            if(top == 5) {
                printf("Stack overflow!\n");
                printf("Do you wish to rerun? 1 for yes, 2 for no: ");
                scanf("%d", &temp);
                if(temp == 2){
                    play = 0;
                }
            } else {
                push(stack, &top);
            }
        }

        else if(choice == 2) {
            if(top == 0) {
                printf("Stack underflow!\n");
                printf("Do you wish to rerun? 1 for yes, 2 for no: ");
                scanf("%d", &temp);
                if(temp == 2){
                    play = 0;
                    break;
                }
            } else {
                pop(stack, &top);
            }
        }

        else if(choice == 3) {
            if(top == 0) {
                printf("Stack is empty!\n");
                printf("Do you wish to rerun? 1 for yes, 2 for no: ");
                scanf("%d", &temp);
                if(temp == 2){
                    play = 0;
                    break;
                }
            } else {
                peak(stack, &top);
            }
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

void push(int stack[], int *top) {
    int temp;
    printf("Enter the element to insert: ");
    scanf("%d", &temp);
    stack[*top] = temp;
    (*top)++;
}

void pop(int stack[], int *top) {
    (*top)--;
    printf("The element removed is %d\n", stack[*top]);
}

void peak(int stack[], int *top) {
    printf("Top element is: %d\n", stack[*top - 1]);
}
