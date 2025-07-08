	#include <stdio.h>

int main()
{
	int n=0;
	int rot=0;
	int dir=0;
	int temp=0;
	
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	if(n==0)
	{
		printf("There is nothing to sort");
		return 0;
	}
	
	int arr[n];
	
	for(int i = 0;i<n;i++)
	{
		printf("Enter an element : ");
		scanf("%d",&arr[i]);
	}
	
	printf("Enter number of rotations : ");
	scanf("%d",&rot);
	
	printf("Enter direction of rotation; 0 for left ,1 for right: ");
	scanf("%d",&dir);
	
	if(dir==0)
	{
		for(int i = 0;i<rot;i++)
		{
			temp = arr[0];
			for(int j = 1;j<n;j++)
			{
				arr[j-1] = arr[j];
			}
			arr[n-1] = temp;
		}
	}
	
	else if(dir==1)
	{
		for(int i = 0;i<rot;i++)
		{
			temp = arr[n-1];
			for(int j = n-1;j>0;j--)
			{
				arr[j] = arr[j-1];
			}
			arr[1] = temp;
		}
	}
	
	printf("The array, rotated %d times is : ",rot);
	for(int i = 0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}	
