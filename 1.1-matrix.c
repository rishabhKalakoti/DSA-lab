/*
	Developer: Rishabh Kalakoti
*/
#include<stdio.h>

void main()
{
	// variables initialized...
	int n = 3;
	int i, j, k;
	int matA[n][n];
	printf("Please, just 3 X 3 matrices\n");
	
	// user inputs matrix A
	printf("Enter matrix A\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &matA[i][j]);
		}
	}
	
	int matB[n][n];
	//user inputs matrix B
	printf("Enter matrix B\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &matB[i][j]);
		}
	}				
	int matC[n][n];
	
	// let's go!!!
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			int sum = 0;
			// the hectic work...
			for(k=0; k<n; k++)
			{
				sum = sum + matA[i][k] * matB[k][j];
			}	
			matC[i][j] = sum;
		}
	}
	
	// print the matrix C
	printf("matrix C is:\n");
	for(i = 0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d ", matC[i][j]);
		}
		printf("\n");
	}
}
