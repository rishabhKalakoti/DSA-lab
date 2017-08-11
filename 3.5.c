#include<stdio.h>
#include<string.h>

void main()
{
	char str[100];
	
	printf("Enter the string:\n");
	scanf("%[^\n]s", str);
	
	// ascii values
	/*
		a=97
		z=122
		A=65
		Z=90
	*/
	int i, j, flag=0;
	int length = strlen(str);
	for(i=65; i<=90; i++)
	{
		flag=0;
		for(j=0; j<length; j++)
		{
			if(str[j]==i || str[j]==i+32)
			{
				flag=1;
				break;
			}
		}
		if(flag!=1)
		{
			break;
		}
	}
	if(flag!=1)
	{
		printf("FAIL\n");
	}
	else
	{
		printf("SUCCESS\n");
	}
}
