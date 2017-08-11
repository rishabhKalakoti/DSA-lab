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
	
	// start
	int flag=0;
	for(i=0; i<n/2; i++)
	{
		if(!(arr[i]==arr[n-1-i]))
		{
			flag=1;
			break;
		}
	}
	
	// print
	if(flag==1)
	{
		printf("FAIL\n");
	}
	else
	{
		printf("SUCCESS\n");
	}
}
