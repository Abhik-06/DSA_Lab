#include <stdio.h>

void sort(int arr[], int n);
int removeDuplicates(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int n1 = 5;
    int n2 = 5;

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 3, 5, 7, 9};

    int arr[10];
    int pos = 0;

    sort(arr1, n1);
    sort(arr2, n2);

    for(int i = 0; i < n1; i++) {
        arr[pos++] = arr1[i];
    }
    for(int i = 0; i < n2; i++) {
        arr[pos++] = arr2[i];
    }

    sort(arr, pos);
    int newSize = removeDuplicates(arr, pos);

    printf("The union of the two sets is: ");
    printArray(arr, newSize);

    return 0;
}

void sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1; // new size
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
