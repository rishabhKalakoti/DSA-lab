#include<stdio.h>
#include<stdlib.h>

struct element
{
	int data;
	int a;
	int b;
	struct element *next;
};
void main()
{
	int N;
	printf("Enter no of elements\n");
	scanf("%d", &N);
	printf("Enter elements one by one\n");
	int A[25];
	int i,j;
	for(i=0; i<N; i++)
	{
		scanf("%d", &A[i]);
	}
	int s;
	
	struct element *sum[100];
	for(i=0; i<100; i++)
	{
		sum[i]=NULL;
	}
	printf("Elements satsfying a+b=c+d:\n");
	
	struct element *temp;
	temp=(struct element*)malloc(sizeof(struct element));
	for(i=0; i<N-1; i++)
	{
		for(j=i+1; j<N; j++)
		{
			s=A[i]+A[j];
			if(sum[s%100]==NULL)
			{
				struct element *temp1;
				temp1=(struct element*)malloc(sizeof(struct element));
				temp1->next=NULL;
				temp1->data=s;
				temp1->a=A[i];
				temp1->b=A[j];
				sum[s%100]=temp1;
			}
			else
			{
				//printf("b");
				temp=sum[s%100];
				while(temp!=NULL)
				{
					if(temp->data==s)
						printf("%d + %d = %d + %d\n", sum[s%100]->a, sum[s%100]->b, A[i], A[j]);
					temp=temp->next;
				}
				struct element *temp1;
				temp1=(struct element*)malloc(sizeof(struct element));
				temp1->next=NULL;
				temp1->data=s;
				temp1->a=A[i];
				temp1->b=A[j];
				temp=temp1;
			}

		}

	}
}
