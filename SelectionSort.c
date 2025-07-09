#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);

    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0;i<n;i++){
        printf("Enter an element : ");
        scanf("%d",&arr[i]);
    }

    int min;
    int temp = 0;
    for(int i = 0;i<n;i++){
        temp = arr[i];
        min = i;
        for(int j = i;j<n;j++){
            if(arr[j]<temp){
                temp = arr[j];
                min = j;
            }
        }
        if(min!=i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("The sorted array, via selection sort is ");
    for(int i = 0;i<n;i++){
        printf("%d",arr[i]);
    }

    return 0;
}