// bubble sort

#include<stdio.h>

void main()
{
	int n;
	printf("Enter size of array:\n");
	scanf("%d", &n);
	
	int arr[n];
	int i;
	printf("Enter the elements of the array:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	i=0;
	int j, temp;
	int flag=0;
	
	do
	{
		flag=0;
		for(j=0; j<n-1-i; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
				flag=1;
			}
		}
		i++;
	}while(flag==1);
	
	// print
	printf("The output array is:\n");
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
