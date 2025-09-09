#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

int isFull(Deque *dq) {
    return dq->size == MAX;
}

int isEmpty(Deque *dq) {
    return dq->size == 0;
}

void insertFront(Deque *dq, int x) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) { 
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = x;
    dq->size++;
}

void insertRear(Deque *dq, int x) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = x;
    dq->size++;
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted from front: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = 0;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    dq->size--;
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    dq->size--;
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);
    int choice, val;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(&dq, val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(&dq, val);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
