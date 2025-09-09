#include<stdio.h>


struct matrix{
    int row;
    int col;
    int value;
};
struct sparsematrix{
    int numValues;
    struct matrix matrices[100];
};

int main(){
    int choice = 1;
    while(choice==1){
        printf("Enter you choice : ");
        printf("1 for adding a new matrix");
        printf("2 for displaying a matrix");
        printf("3 for adding two matrices");
        printf("4 for subtracting two matrices");
        printf("5 for multiplying two matrices");
        printf("Choice : ");
        scanf("%d",&choice);

        if(choice==1){
            EnterMatrix(&sparsehome,count)
        }
    }

    return 0;
}