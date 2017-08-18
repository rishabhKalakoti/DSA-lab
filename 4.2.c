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
	
	int k=0, temp;
	while(k<N-1)
	{
		for(i=k; i>=0; i--)
		{
			temp=list[i+1];
			if(temp<list[i])
			{
				temp=list[i];
				list[i]=list[i+1];
				list[i+1]=temp;
			}
		}
		k++;
	}
	
	printf("Sorted list:\n");
	for(i=0; i<N; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}
