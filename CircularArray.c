#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void Choice(int* choice);
int EnterData();
int CountNodes(struct node* head);
void InsertAtFront(struct node** head);
void InsertAtEnd(struct node** head);
void InsertAtIndex(struct node** head);
void DeleteAtFront(struct node** head);
void DeleteAtEnd(struct node** head);
void DeleteAtIndex(struct node** head);
void DisplayElements(struct node* head);

int main(){
    struct node* head = NULL;
    int choice = 1;

    while (choice == 1){
        printf("Enter your choice\n1 for Insert\n2 for Delete\n3 for Dislay Elements\nChoice : ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Where do you wish to insert ?\n1 for Front\n2 for End\n3 for Index\nChoice : ");
                scanf("%d", &choice);

                switch (choice){
                    case 1:
                        InsertAtFront(&head);
                        break;
                    case 2:
                        InsertAtEnd(&head);
                        break;
                    case 3:
                        InsertAtIndex(&head);
                        break;

                    default:
                        printf("\nInvalid ENTRY !\n");
                        break;
                }
                break;
                    
            case 2:
                printf("Enter your choice\n1 for Front\n2 for End\n3 for Index\nChoice : ");
                scanf("%d",&choice);

                switch (choice){
                    case 1:
                        DeleteAtFront(&head);                        
                        break;
                    case 2:
                        DeleteAtEnd(&head);
                        break;
                    
                    case 3:
                        DeleteAtIndex(&head);
                        break;
                
                    default:
                        printf("Invalid ENTRY !");
                        break;
                }
                break;

            case 3:
                DisplayElements(head);
                break;

            default:
                printf("Invalid ENTRY !");
                break;
        }

        Choice(&choice);
    }

    printf("Thank you for using my program :)");
    return 0;
}

void Choice(int* choice){
    printf("\nDo you wish to rerun ?\n1 for yes\n0 for no\nChoice : ");
    scanf("%d",choice);
    return;
}

int EnterData(){
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);

    return data;
}

int EnterIndex(){
    int index;
    printf("Enter the index : ");
    scanf("%d",&index);

    return index;
}

int CountNodes(struct node* head) {
    if (head == NULL) {
        return 0;
    }

    int count = 1;
    struct node* current = head->next;

    while (current != head) {
        count++;
        current = current->next;
    }
    
    return count;
}

void InsertAtFront(struct node** head){
    int data = EnterData();

    if((*head)==NULL){
        (*head) = malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = (*head);

        printf("\nDone !\n");
        return;
    }

    struct node* temp = (*head);
    while(temp->next!=(*head)){
        temp = temp->next;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;

    (*head) = newnode;
    temp->next = (*head);

    printf("\nDone !\n");
    return;
}

void InsertAtEnd(struct node** head){
    int data = EnterData();

    if(*head==NULL){
        InsertAtFront(head);
        return;
    }

    struct node* temp = (*head)->next;

    while(temp->next!=(*head)){
        temp = temp->next;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = (*head);
    temp->next = newnode;

    printf("\nDone !\n");
    return;
}

void InsertAtIndex(struct node** head) {
    int data = EnterData();
    int index = EnterIndex();

    if (*head == NULL) {
        InsertAtFront(head);
        return;
    }

    int count = CountNodes(*head);
    if (index < 0 || index > count) {
        printf("\nIndex Out of Bounds !\n");
        return;
    }

    if (index == 0) {
        InsertAtFront(head);
        return;
    }

    struct node* temp = *head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;

    printf("\nDone\n");
    return;
}

void DeleteAtFront(struct node** head){
    if(*head==NULL){
        printf("\nList is EMPTY !\n");
        return;
    }

    if((*head)->next==(*head)){
        free(*head);
        return;
    }

    struct node* temp1 = (*head);
    struct node* temp2 = (*head);

    while(temp1->next!=(*head)){
        temp1 = temp1->next;
    }

    (*head) = (*head)->next;
    temp1->next = (*head);

    free(temp2);
    temp2 = NULL;

    printf("\nDone !\n");
    return;
}

void DeleteAtEnd(struct node** head){
    if(*head==NULL){
        printf("\nArray is EMPTY !");
        return;
    }

    if((*head)->next==(*head)){
        free(*head);

        printf("\nDone !");
        return;
    }

    struct node* temp1 = (*head);
    struct node* temp2 = (*head)->next;

    while(temp2!=(*head)){
        temp2 = temp2->next;
        temp1 = temp1->next;
    }

    temp1->next = (*head);
    free(temp2);
    temp2 = NULL;

    printf("\nDone !\n");
    return;
}

void DeleteAtIndex(struct node** head){
    if((*head)==NULL){
        printf("\nArray is EMPTY !");
        return;
    }

    int index = EnterIndex();

    int count = CountNodes(*head);
    if(index<0 || index>count){
        printf("\nIndex OUT OF BOUNDS !");
        return;
    }

    struct node* temp1;
    struct node* temp2 = (*head)->next;

    for(int i = 0;i<=index;i++){
        if(temp2==NULL){
            printf("Index OUT OF BOUNDS !\n");
            return;
        }

        temp2 = temp2->next;
        temp1 = temp1->next;
    }

    temp1->next = (*head);
    free(temp2);
    temp2 = NULL;

    printf("\nDone !\n");
    return;
}

void DisplayElements(struct node* head){
    if(head==NULL){
        printf("\nArray is EMPTY !");
        return;
    }

    struct node* temp = head->next;

    printf("%d -> ",head->data);
    while(temp!=head){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("...");

    printf("\nDone !\n");
    return;
}