#include<stdio.h>

int Choice();
void Enque(int queue[], int *front, int *rear, int max);
void Deque(int queue[],int *front, int *rear, int max);
void Peek(int queue[], int *front, int *rear, int max);
void Display(int queue[], int *front, int *rear, int max);


int temp;

int main(){
    int queue[5];

    int front = -1;
    int rear = -1;
    int max = sizeof(queue)/sizeof(queue[0]);

    int choice = 1;

    while(choice==1){
        printf("Enter the function to perform\n1 for enque\n2 for deque\n3 for peek\n4 for checking if full\n5 for checking if empty\n6 for display\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice){

        case 1:
            if((rear+1)%max==front){
                printf("The queue is full !\n");
            }
            else{
                Enque(queue,&front,&rear,max);
            }
            break;

        case 2:
            if((front==-1 && front==rear) || (rear%max==front && front!=0)){
                printf("The queue is empty !\n");
            }
            else{
                Deque(queue,&front,&rear,max);
            }
            break;
            
        case 3:
            if((front==-1 && front==rear) || (rear%max==front && front!=0)){
                printf("The queue is empty !\n");
            }
            else{
                Peek(queue,&front,&rear,max);
            }
            break;

        case 4:
            if((rear+1)%max==front){
                printf("The queue is full !\n");
            }
            else{
                printf("The queue is not full!\n");
            }
            break;

        case 5:
            if((front==-1 && front==rear) || (rear%max==front && front!=0)){
                printf("The queue is empty !\n");
            }
            else{
                printf("The queue is not empty !\n");
            }
            break;

        case 6:
            if((front==-1 && front==rear) || (rear%max==front && front!=0)){
                printf("The queue is empty !\n");
            }
            else{
                Display(queue,&front,&rear,max);
            }
            break;
        default:
            break;
        }

        choice = Choice();
    }

    return 0;
}

int Choice(){
    printf("Do you wish to continue ?\n1 for yes\n0 for no\nChoice : ");
    scanf("%d",&temp);

    return temp;
}

void Enque(int queue[],int *front,int *rear, int max){
    printf("Enter the value you wish to enque : ");
    scanf("%d",&temp);

    if(*front == -1 && *rear == -1){
        *front = *rear = 0;
    }
    else{
        *rear = (*rear+1)%max;
    }
    queue[*rear]=temp;
}

void Deque(int queue[], int *front, int *rear, int max){
    printf("The element %d is dequed\n",queue[*front]);

    if(*front == *rear && *rear == 0){
        *front = *rear = -1;
    }
    else{
        *front = ((*front+max)+1)%max;
    }
}

void Peek(int queue[], int *front, int *rear, int max){
    printf("The leftmost element is %d.\nThe rightmost element is %d\n",queue[*front],queue[*rear]);
}

void Display(int queue[], int *front, int *rear, int max){
    int i = *front;
    while(1){
        printf("%d ", queue[i]);
        if(i == *rear){
            break;
        }
        i = (i + 1) % max;
    }
    printf("\n");   
}