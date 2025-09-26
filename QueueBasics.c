#include <stdio.h>

#define MAX 5

void Enqueue(int queue[], int *front, int *rear);
int Dequeue(int queue[], int *front, int *rear);
int Check(int front, int rear);
void Peek(int queue[], int front);
void Display(int queue[], int front, int rear);
int Choice();

int main() {
    int queue[MAX];
    int front = -1, rear = -1, choice = 1;

    while (choice == 1) {
        int option;
        printf("\nEnter the function to perform:\n");
        printf("1 for Enqueue\n2 for Dequeue\n3 for checking if queue is empty\n");
        printf("4 for checking if queue is full\n5 for Peek\n6 for Display\nChoice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Enqueue
                if (rear == MAX - 1) {
                    printf("Queue Overflow!\n");
                } else {
                    Enqueue(queue, &front, &rear);
                }
                break;

            case 2: // Dequeue
                if (front == -1 || front > rear) {
                    printf("Queue Underflow!\n");
                } else {
                    Dequeue(queue, &front, &rear);
                }
                break;

            case 3: // Is Empty
                if (front == -1 || front > rear)
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;

            case 4: // Is Full
                if (rear == MAX - 1)
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;

            case 5: // Peek
                if (front == -1 || front > rear)
                    printf("Queue is empty (Underflow).\n");
                else
                    Peek(queue, front);
                break;

            case 6: // Display
                if (front == -1 || front > rear)
                    printf("Queue is empty (Underflow).\n");
                else
                    Display(queue, front, rear);
                break;

            default:
                printf("Wrong input. Terminating.\n");
        }

        choice = Choice();
    }

    return 0;
}

void Enqueue(int queue[], int *front, int *rear) {
    int temp;
    printf("Enter the element you wish to enqueue: ");
    scanf("%d", &temp);

    if (*front == -1) *front = 0;
    (*rear)++;
    queue[*rear] = temp;
}

int Dequeue(int queue[], int *front, int *rear) {
    int temp = queue[*front];
    printf("The element removed is %d\n", temp);
    (*front)++;
    if (*front > *rear) {
        *front = *rear = -1; // Reset the queue
    }
    return temp;
}

void Peek(int queue[], int front) {
    printf("The front element is: %d\n", queue[front]);
}

void Display(int queue[], int front, int rear) {
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int Choice() {
    int temp;
    printf("Do you wish to rerun the program?\n1 for yes\n0 for no\nChoice: ");
    scanf("%d", &temp);
    return temp;
}
