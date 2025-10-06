#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct stacknode{
    struct stacknode* next;
};

int main(){
    int choice = 1;
    struct stacknode stack; 
    struct node root;
    char expression[50];

    while(choice==1){
        printf("Enter the type of expression\n1 for infix\n2 for prefix\n3 for postfix\nChoice : ");
        fgets(expression,50,stdin);

        switch (choice){
        case  1:
            char* new = ConvertToPostfix(expression);
            InsertPostfix(new,&stack,&root);
            break;
        case 3:
            InsertPostfix(expression,&head,&root);
            break;
        default:
            printf("\nInvalid Input !\n");
            break;
        }

        choice = Choice(choice);
    }

    printf("Thank you for using my program :)");
    return;
}

int Choice(int choice){
    printf("Do you wish to rerun ?\n1 for yes\0 for no\nChoice : ");
    scanf("%d",&choice);

    return choice;
}

void InsertPostfix(char* expr,struct stacknode* head,struct node* root){
    int *top = 0;

    for(int i = 0;i!="\0";i++){
        if(isalnum(expr[i])){
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = expr[i];
            newnode->right = NULL;
            newnode->left = NULL;

            PushIntoStack(*stack,*newnode,top);
        }
        else{
            struct node* tempB = PopFromStack(top);
            struct node* tempA = PopFromStack(top);

            struct node* newnode = CreateNode(expr[i]);
            newnode->right = tempB;
            newnode->left = tempA;
        }
    }
}

struct node* CreateNode(char expr){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = expr;
    newnode->right = NULL;
    newnode->left = NULL;

    return newnode;
}

void InfixDisplay(struct node* root){
    if(root->data==NULL){
        return;
    }

    if(!isalnum(root->data) ){
        printf("(");

        InfixDisplay(root->left);
        printf("%c ",root->data);
        InfixDisplay(root->right);

        printf(")");
    }
}

void PrefixDisplay(struct node* root){
    if(root->data==NULL){
        return;
    }

    if(!isalnum(root->data) && root->left==NULL){
        printf("(");

        printf("%c ",root->data);
        PrefixDisplay(root->left);
        PrefixDisplay(root->right);

        printf(")");
    }
}

void PostfixDisplay(struct node* root){
    if(root->data==NULL){
        return;
    }

    if(!isalnum(root->data)){
        printf("(");

        PostfixDisplay(root->left);
        PostfixDisplay(root->left);
        printf("%c ",root->data);

        printf(")");
    }
}

void PushIntoStack(struct stacknode* stack,int* top)