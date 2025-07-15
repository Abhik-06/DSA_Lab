#include <stdio.h>
 
int main()
{
	int n;
	printf("Enter the nuumber of elements in the array : ");
	scanf("%d",&n);
	
	int arr[n];
	
	int temp;
	int mean;
	int median;
	int mode;
	
	for(int i = 0;i<n;i++)
	{
		printf("Enter an element : ");
		scanf("%d",&arr[i]);
	}
	
	//Sorting
	for(int i = 1;i<n;i++)
	{
		for(int j = i-1; j >= 0;j--)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	//Calculating the mean
	for(int i = 0;i<n;i++)
	{
		temp+=arr[i];
	}
	mean = temp/n;
	printf("The mean of the list is %d\n",mean);
	
	//Calculating the mode
	median = arr[n/2];
	printf("The median of the list is %d\n",median);
	
	//Calculating the mode
	if(n>arr[n-1])
	{
		int hash[n];
	}
	else
	{
		int hash[arr[n-1]];
	}
	
	for(int i = 0;i<n;i++)
	{
		hash[arr[i]]+=1;
	}
	
	temp = 0;
	for(int i = 0;i<hash[0]/int;i++)
	{
		if(temp>hash[i])
		{
			mode = i;
			temp = hash[i];
		}
	}
	printf("The mode is %d",mode);
	
	return 0;
}
		
	
	
	
	
	
	
