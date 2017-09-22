#include<stdio.h>

void hanoi(int n ,char src,char des,char in)
{
	if(n==1)
	{
		printf("disk1: tower%c -> tower%c\n", src, des);
	}
	else
	{
		hanoi(n-1, src, in, des);
		printf("disk%d: tower%c -> tower%c\n", n, src, des);
		hanoi(n-1, in, des, src);
		
	}
}

void main()
{
	printf("-------------------TOWER OF HANOI--------------\n");
	printf("Enter the tower size:\n");
	int size;
	scanf("%d", &size);
	printf("------------------\n");
	hanoi(size,'A', 'C','B');
	printf("------------------\n");
	printf("Transfer from towerA to towerC using towerB complete.");
}
