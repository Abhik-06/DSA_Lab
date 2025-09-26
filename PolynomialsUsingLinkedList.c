#include <stdio.h>
#include <stdlib.H>

struct term{
    int coeff;
    int exp;
    struct term* next;
};

void Choice(int* choice);
int EnterTerm();
int EnterPow();


int main(){
    int choice = 1;
    struct term* poly1 = (struct term*)malloc(sizeof(struct term));
    struct term* poly2 = (struct term*)malloc(sizeof(struct term));

    while(choice==1){
        printf("Enter function to perform\n1 for initiating/re-initiating the first polynomial\n2 for initiating/re-initiating the second polynomial\n3 for Addition\n4 for subtraction\n5 for multiplication\nChoice : ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                IniatePoly(&poly1);
                break;

            case 2:
                InitiatePoly(&poly2);
                break;
            
            case 3:
                AddPoly(poly1,poly2);
                break;
            
            case 4:
                MultiplyPoly(poly1,poly2);
                break;
    
            default:
                printf("\nWrong input ! \n");
                break;
        }

        Choice(&choice);
    }

    printf("\nThank you for using my program :)");
    return 0;
}

void Choice(int* choice){
    printf("\nDo you wish to rerun ?\n1 for yes\n0 for no\nChoice : ");
    scanf("%d",&choice);
}

int EnterTerm(){
    int term;

    printf("\nEnter the term :");
    scanf("%d",&term);

    return term;
}

int EnterPow(){
    int pow;

    printf("\nEnter the exponent of the term : ");
    scanf("%d",&pow);

    return pow;
}

