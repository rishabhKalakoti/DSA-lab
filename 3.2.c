#include<stdio.h>

int isPrime(int num)
{
	if(num==2)
	{
		return 1;
	}
	else
	{
		int i;
		for(i=2; i<num/2+1; i++)
		{
			if(num%i==0)
			{
				return 0;
			}
		}
		return 1;
	}
}

void main()
{
	int n;
	printf("Enter number of primes to insert:\n");
	scanf("%d", &n);
	
	int arr[n];
	int num=1;
	int count=0;
	while(count<n)
	{
		num++;
		if(isPrime(num))
		{
			arr[count]=num;
			count++;
		}
	}
	
	// print
	printf("The output array is:\n");
	for(count=0; count<n; count++)
	{
		printf("%d ", arr[count]);
	}
	printf("\n");
}
