#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int temp;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);

    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0;i<n;i++){
        printf("Enter an element : ");
        scanf("%d",&arr[i]);
    }

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("The sorted array, via insertion sort is ");
    for(int i = 0;i<n;i++){
        printf("%d",arr[i]);
    }

    return 0;
}