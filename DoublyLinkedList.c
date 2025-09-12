#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node*prev;
};

struct node* head = NULL;

void Choice(int *choice);
int EnterData();
int EnterIndex();
void InsertAtFront(struct node** head);
void InsertAtEnd(struct node** head);
void InsertAtIndex(struct node** head);
void DeleteAtFront(struct node** head);
void DeleteAtEnd(struct node** head);
void DeleteAtIndex(struct node** head);
void DisplayList(struct node* head);


int main(){
    int choice = 1;
    
    while(choice==1){
        printf("Enter the function to perform \n1 for ADD node\n2 for REMOVE node\n3 for Display the list\nChoice : ");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            printf("Where do you wish to enter teh node \n1 for AT FRONT\n2 for AT END\n3 for AT INDEX\nChoice : ");
            scanf("%d",&choice);

            switch (choice){
                case 1:
                    InsertAtFront(&head);
                    Choice(&choice);
                    break;
                case 2:
                    InsertAtEnd(&head);
                    Choice(&choice);
                    break;
                case 3:
                    InsertAtIndex(&head);
                    Choice(&choice);
                    break;
                default:
                    printf("Wrong input, terminating ! ");
                    Choice(&choice);
                    break;
            }
            break;

        case 2:
            printf("Where do you wish to delete the node from \n1 for AT FRONT\n2 for AT END\n3 for AT INDEX\nChoice : ");
            scanf("%d",&choice);
            
            switch (choice){
                case 1:
                    DeleteAtFront(&head);
                    Choice(&choice);
                    break;
                case 2:
                    DeleteAtEnd(&head);
                    Choice(&choice);
                    break;
                case 3:
                    DeleteAtIndex(&head);
                    Choice(&choice);
                    break;
                default:
                    printf("Wrong input, terminating");
                    Choice(&choice);
                    break;
            }
            break;

        case 3:
            DisplayList(head);
            Choice(&choice);
            break;

        default:
            printf("Wrong input, terminating !");
            Choice(&choice);
            break;
        }
    }

    printf("Thank you for using my program :)");
    return 0;
}

void Choice(int *choice){
    printf("Do you wish to rerun ?\n1 for yes\n0 fo rno\nChoice : ");
    scanf("%d",choice);
}

int EnterData(){
    int temp;

    printf("Enter the data you wish to enter : ");
    scanf("%d",&temp);

    return temp;
}

int EnterIndex(){
    int temp;

    printf("Enter the index : ");
    scanf("%d",&temp);

    return temp;
}

void InsertAtFront(struct node** head){
    int data = EnterData();
    if(*head==NULL){
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->data = data;

        *head = newnode;
        printf("\nDone\n");
        return;
    }
    
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode-> data = data;
    newnode->next = (*head);
    newnode->prev = NULL;
    *head = newnode;

    printf("\nDone\n");
    return;
}

void InsertAtEnd(struct node** head){
    if((*head)==NULL){
        InsertAtFront(head);
        return;
    }

    int data = EnterData();
    struct node* temp = (*head);


    while(temp->next!=NULL){
        temp = temp->next;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    temp->next = newnode;
    newnode->next = NULL;
    newnode->prev = temp;

    printf("\nDone\n");
    return;
}

void InsertAtIndex(struct node** head){
    int index = EnterIndex();
    if(index==0){
        InsertAtFront(head);
        return;
    }

    struct node* temp = (*head);
    
    for(int i=0;i<=index;i++){
        if(temp==NULL){
            printf("Index Out of Bounds !\n");
            return;
        }
        temp = temp->next;
    }

    int data = EnterData();
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    newnode->next = temp->next;
    newnode->prev = temp;
    
    temp->next = newnode;
    printf("\nDone\n");
    return;
}

void DeleteAtFront(struct node** head){
    if(*head==NULL){
        printf("Empty list !");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(temp);
    printf("\nDone\n");
    return;
}

void DeleteAtEnd(struct node** head){
    if(*head==NULL){
        printf("Empty List !");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        printf("\nDone\n");
        return;
    }

    struct node* temp = *head;

    while((temp->next->next)==NULL){
        temp = temp->next;
    }

    struct node*todelete = temp->next;
    temp->next = NULL;

    free(todelete);
    printf("\nDone\n");
    return;
}

void DeleteAtIndex(struct node** head){
    if(*head==NULL){
        printf("Empty list !");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        printf("\nDone\n");
        return;
    }

    int index = EnterIndex();
    int data = EnterData();

    struct node* temp = *head;

    for(int i = 0;i<=index;i++){
        if(temp==NULL){
            printf("Index Out of Bounds !");
            return;
        }
        temp = temp->next;
    }

    struct node* prevnode;
    prevnode = temp->prev;
    prevnode->next = temp->next;

    free(temp);
    printf("\nDone\n");
    return;
}

void DisplayList(struct node* head){
    if(head==NULL){
        printf("Empty List !");
        return;
    }

    struct node* temp = head;
    int index = 0;
    while(temp!=NULL){
        printf("Index : %d\n",index);
        printf("Data : %d\n",temp->data);
        index++;
        temp = temp->next;
    }

    printf("\nDone\n");
    return;
}

