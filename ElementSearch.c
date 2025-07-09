#include <stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[],int,int,int);

int main(){
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);

    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0;i<n;i++){
        printf("Enter an element : ");
        scanf("%d",&arr[i]);
    }

    int q;
    printf("Enter the index of the number you want to search : ");
    scanf("%d",&q);

    printf("The index of the element %d is %d",q,BinarySearch(arr,q,0,n));

    return 0;
}

BinarySearch(int arr[],int q,int low,int n){
    printf("Now");
    int mid = n/2;
    if(q<arr[mid]){
        return BinarySearch(arr,q,0,mid);
    }
    else if(q>arr[mid]){
        return BinarySearch(arr,q,mid+1,n);
    }
    else{
        return mid;
    }
}