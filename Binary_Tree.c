#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct queue{
    struct qnode* front;
    struct qnode* rear;
};
struct qnode{
    struct node* treenode;
    struct qnode* next;
}

void Choice(int* choice);
int EnterData();
struct node* InsertIntoTree(struct node* root,int data);

int main(){
    struct node* root;
    struct qnode* q;
    int* choice = 1;

    while(choice>0){
        printf("Enter the operation to perform\n1 for enter value\n2 for delete");

        switch (*choice){
            case 1:
                int data = EnterData();
                InsertIntoTree(&root,data);
                break;
            
            case 2:
                int data = EnterData();
                DeleteFromTree(&root,data);
                break;

            default:
                printf("\nInvalid input !\n");
                break;
        
        Choice(&choice);
        }
    }

    printf("Thank you for using my program :)");
    return 0;
}

struct qnode* CreateQnode(struct qnode* q){
    q = malloc(sizeof(struct qnode));
    q->next = NULL;

    return q;
}

int Choice(int* choice){
    printf("Do you wish to rerun ?\n1 for yes\n2 for no\nChoice : ");
    scanf("%d",choice);
}

int EnterData(){
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);

    return data;
}

struct node* InsertIntoTree(struct node* root,int data){
    if(root==NULL){
        root = malloc(sizeof(struct node));

        root->data = data;
        root->left = NULL;
        root->right = NULL;

        printf("\nDone !\n");
        return root;
    }

    if(data < root->data){
        root->left = InsertIntoTree(root->left,data);
    }
    else if(data > root->data){
        root->right = InsertIntoTree(root->right,data);
    }

    return root;
}

struct node* DeleteFromTree(struct node* root,int data){
    if(root==NULL){
        printf("\nNo such value in tree/Tree empty !\n");
        return NULL;
    }

    if(data < root->data){
        root = DeleteFromTree(root->left,data);
    }
    else if(data > root->data){
        root = DeleteFromTree(root->right,data);
    }
    else{
        //Case 1 : There exists no child of the node
        if(root->left == NULL && root->right == NULL){
            free(root);
            printf("\nDone !\n");
            return;
        }

        //Case 2 : There exists right child, but not the left child
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            
            printf("\nDone !\n");
            return temp;
        }

        //Case 3 : There exists left chile, but not the right child
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);

            printf("\nDone !\n");
            return temp;
        }

        //Case 4 : There exists both the children
        else{
            struct node* temp = root->right;
            free(root);

            printf("\nDone !\n");
            return temp;
        }
    }
}

struct node* InOrder(struct node* root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

struct node* PreOrder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

struct node* PostOrder(struct node* root){
    if(root!=NULL){
        PreOrder(root->left);
        Preorder(root->right);
        PostOrder("%d ",root->data);
    }
}

void LevelOrder(struct node* root,struct qnode* q){
    if(root==NULL){
        return;
    }
    struct qnode* q = CreateQnode(q);
    Enque(q,root->data);

    while(!isEmpty(q)){
        struct node* current = deque(q);
        printf("%d ",current->data);

        if(current->left==NULL){
            Enque(q,current->left);
        }
        if(current->right==NULL){
            Enque(q,current->right);
        }
    }
}

void Enque(struct queue* q,struct node* node){
    struct qnode* temp = (struct node*)malloc(sizeof(struct qnode));
    temp->treenode = node;
    temp->next = NULL;

    if(q->rear==NULL){
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    return;
}

void Deque(struct queue* q,struct node* node){
    if(q->front==NULL){
        return;
    }

    struct qnode* temp = q->front;
    struct node* treenode = temp->treenode;
    
}