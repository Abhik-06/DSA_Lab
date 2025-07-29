#include <stdio.h>
#include "StackBasics.h"

int main(){
    int n;
    int stack[5];
    int play = 1;
    int choice;
    int temp;
    int top;

    while(play == 1){
        printf("\nEnter the function to perform:\n1 for push\n2 for pop\n3 for peak\n4 for Maximum element(current stack shall be reset)\nChoice: ");
        scanf("%d", &choice);

        if(choice==1){
            if(check(stack,top)==0){
                printf("Stack overflow ! ");
                choice = Choice();
            }
            else{
                push(stack,&top);
                choice = Choice();
            }
            continue;
        }

        if(choice==2){
            if(check(check,top)==-1){
                printf("Stack Underflow ! ");
                choice = Choice();
            }
            else{
                pop(stack,&top);if(check)
                choice = Choice();
            }
            continue;
        }

        if(choice==3){
            if(check(check,top)==-1){
                printf("Stack Underflow ! ");
                choice = Choice();
            }
            else{
                peak(stack,&top);
                choice = Choice();
            }
            continue;
        }

        if(choice==4){
            if(check(check,top)==-1){
                printf("Stack Underflow !");
                choice = Choice();
            }
            else{
                printf("The maximum element of the stack is %d",MaxElement(stack,&top));
                choice = Choice();
            }
            continue;
        }
    }

    return 0;
}