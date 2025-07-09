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

    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("The array in the sorted format, via BUBBLE SORT is ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}