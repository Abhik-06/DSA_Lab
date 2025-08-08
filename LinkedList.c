#include<stdio.h>
#include<stdlib.h>

void Choice(int *choice);
int EnterData();
void InsertAtFront(struct node** head);
void InsertAtEnd(struct node* head);
void InsertAtIndex(struct node* head);
void DeleteAtFront(struct node** head);
void DeleteAtEnd(struct node* head);
void DeleteAtIndex(struct node* head);

// The struct model
struct node{
    int data;
    struct node *next;
};

// Declaring the head as the pointer of the first node
struct node* head = NULL;
int temp;

int main(){
    int choice = 1;
    
    while(choice==1){
        printf("Enter the function to perform \n1 for ADD node\n2 for REMOVE node\nChoice : ");
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
            Choice(&choice);
            break;

        case 2:
            printf("Where do you wish to delete the node from \n1 for AT FRONT\n2 for AT END\n3 for AT INDEX\nChoice : ");
            scanf("%d",&choice );
            
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
    scanf("%d",&choice);
}

int EnterData(){
    printf("Enter the data you wish to enter : ");
    scanf("%d",&temp);
    return temp;
}

int EnterIndex(){
    printf("Enter the index : ");
    scanf("%d",&temp);

    return temp;
}

void InsertAtFront(struct node** head){
    int data = EnterData();
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = head;

    head = newnode;

    printf("Done !");
}

void InsertAtEnd(struct node* head){
    int data = EnterData();
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = data;
    newnode->next = NULL;

    while(head->next!=NULL){
        head++;
    }

    head->next = newnode;

    printf("Done !");
}

void InsertAtIndex(struct node* head){
    int data = EnterData();
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    int index = EnterIndex();

    for(int i = 0;i<index{
        if(head->data==NULL){
            printf("Out of bonds !");
            return;
        }
        head = head->next;
    }

    newnode->next = head->next;
    head->next = newnode;
    
    printf("Done !");
}

void DeleteAtFront(struct node** head){
    struct node* prevnode = *head;
    *head = (*head)->next;
    free(prevnode);

    printf("Done !");
}

void DeleteAtEnd(struct node* head){
    struct node* nextnode = head->next;

    while(nextnode!=NULL){
        nextnode = nextnode->next;
        head = head->next;
    }

    free(head);
    printf("Done !");
    
}

void DeleteAtIndex(struct node* head){
    int index = EnterIndex();

    for(int i = 0;i<index-1;i++){
        if(head==NULL){
            printf("Index OUT OF BOUNDS");
            return;
        }
        head = head->next;
    }

    struct node* ToDelete = head->next;
    head->next = ToDelete->next;
    free(ToDelete);

    printf("Done !");
}