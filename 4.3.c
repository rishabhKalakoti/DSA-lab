#include<stdio.h>

void main()
{
	printf("Enter the no of terms\n");
	int N;
	scanf("%d", &N);
	printf("Enter the sorted terms:\n");
	int i;
	int list[N];
	for(i=0; i<N; i++)
	{
		scanf("%d", &list[i]);
	}
	
	int j=list[0];
	for(i=0; i<N; i++)
	{
		while(j<list[i] && j!=list[i])
		{
			printf("%d ", j);
			j++;
		}
		j++;
	}
	
	printf("\n");
}
