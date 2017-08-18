#include<stdio.h>

long unsigned int factorial(int N)
{
	if(N==0)
		return 1;
	else
		return N*factorial(N-1);
}

void main()
{
	printf("Enter N\n");
	int N, N1;
	scanf("%d", &N);
	int i;
	for(i=11; i<=N; i++)
	{
		long unsigned int sum; 
		sum=0;
		N1=i;
		while(N1>0)
		{
			sum=sum+factorial(N1 % 10);
			N1=N1/10;
		}
		if(sum%i==0)
		{
			printf("%d ", i);
		}
		//printf("%d ", i);
	}
	printf("\n");
}
