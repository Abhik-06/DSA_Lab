#include <stdio.h>

int temp;
int max = 5;

int Check();
void Enque();
int Deque();
void IsEmpty();
void IsFull();
void Peek();
void Display(); //Optional

int main(){
    int queue[5];
    int front = -1;
    int rear = -1;
    int choice;

    while(choice==1){
        printf("Enter the function to perform\n1 for enque\n2 for deque\n3 for checking if queue is empty\n4 for checking if queue is full\n5 for peek\n6 for displaying all the elements of the queue from start to end\nChoice : ");
        scanf("%d",choice);

        switch (choice){
        //Enque
        case 1:
            if(Check(queue,&front,&rear)==1){
                print("Queue overflow !");
                choice = Choice(queue,front,rear);
            }
            else{
                Enque(queue,&front,&rear);
                choice = Choice();
            }
            break;
        //Deque
        case 2:
            if(Check(queue,front,rear)==-1){
                pritnf("Stack underflow !");
                choice = Choice(queue,front,rear);
            }
            else{
                Deque(queue,front,rear);
                choice = Choice();
            }
            break;
        //If stack is empty
        case 3:
            if(Check(queue,front,rear)==-1){
                printf("Stack is empty !");
                choice = Choice();
            }
            else{
                printf("Stack is not empty !");
                choice = Choice();
            }
            break;
        //If stack is full
        case 4:
            if(Check(queue,front,rear)==1){
                printf("Stack is full !");
                choice = Choice();
            }
            else{
                printf("Stack is not full !");
                choice = Choice();
            }
        //Peek
        case 5:
            if(Check(queue,front,rear)==-1){
                printf("Stack Underflow ! ");
                choice = Choice();
            }
            else{
                Peek();
                choice = Choice();
            }
            break;
        //Display
        case 6:
            if(Check(queue,front,rear)==-1){
                printf("Stack Underflow !");
            }
            else{
                Display();
                choice = Choice();
            }
            break;
        default:
            printf("Worng input, terminating !");
            break;
        }
    }

    return 0;
}

int Check(int queue[],int *front, int *rear){
    if(front>rear){
        return 0;
    }
    else if(front==-1 && rear==-1){
        return 0;
    }
    else if(fro)
}

void Enque(int queue[],int *front,int *rear){
    printf("Enter the element you wish to push into the array : ");
    scanf("%d",temp);

    if(front==-1 && rear==-1){
        front = 0;
        rear = 0;
    }
    else{
        rear+=1;
    }

    queue[*rear] = temp;
}

void Deque(int queue[],int *front, int *rear){
    temp = queue[front];

    if(rear==front){
        front = -1;
        rear = -1;
    }
    else{
        front+=1;
    }

    printf("The element removed is %d",temp);
}

void Peek(int queue[],int *front,int *)