#include<stdio.h>

int findExp(int a, int b)
{
	if(b==1)
	{
		return a;
	}
	else
	{
		return a * findExp(a, b-1);
	}
}

void main()
{
	int a, b;
	printf("Enter the numbers as (a,b):\n");
	scanf("%d,%d", &a, &b);
	
	printf("Output:\n");
	printf("%d\n", findExp(a, b));	
}
