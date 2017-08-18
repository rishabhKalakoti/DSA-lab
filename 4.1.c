#include<stdio.h>

void main()
{
	printf("Enter the no of terms\n");
	int N;
	scanf("%d", &N);
	printf("Enter the terms:\n");
	int i;
	int list[N];
	for(i=0; i<N; i++)
	{
		scanf("%d", &list[i]);
	}
	int small, j;
	for(i=0; i<N; i++)
	{
		small=i;
		for(j=i; j<N; j++)
		{
			if(list[j]<list[small])
			{
				small=j;
			}
			int temp;
			temp=list[small];
			list[small]=list[i];
			list[i]=temp;
		}		
	}
	printf("Sorted list:\n");
	for(i=0; i<N; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}
