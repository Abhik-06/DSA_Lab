#include <stdio.h>

int main()
{
	int n;
	int rot;
	int dir;
	int temp;
	
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	
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
			temp = arr[i];
			for(int i = 1;i<n;i++)
			{
				arr[i-1] = arr[i];
			}
			arr[n-1] = temp;
		}
	}
	
	else
	{
		for(int i = 0;i<rot;i++)
		{
			temp = arr[n-1];
			for(int i = 0;i<n-1;i++)
			{
				arr[i-1] = arr[i];
			}
			arr[1] = temp;
		}
	}
	
	printf("The array, rotated %d times is : ");
	for(int i = 0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}	
		
		
		
		
		
		
