#include<string.h>
#include<stdio.h>

void main()
{
	char s[50];
	printf("\nInput the infix expression:\n");
	scanf("%s", s);
	
	int i;
	char stack[25];
	char stackX[25];
	int top=-1;
	int topX=-1;
	char op;
	int l=strlen(s);
	printf("\nPrefix expression:\n");
	i=l;
	int flag=0;
	/*while(flag==0)
	{
		for(i=l; i>=0; i--)
		{
			if()
		}
	}*/
	
	for(i=0; i<l; i++)
	{
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
		{
			topX++;
			stackX[topX]=s[i];
		}
		
		else if(s[i]=='+' || s[i]=='-')
		{
			if(top==-1 || stack[top]=='(')
			{
				top++;
				stack[top]=s[i];
			}
			else
			{
				op=stack[top];
				printf("%c", op);
				stack[top]=s[i];
				op=stackX[topX-1];
				printf("%c", op);
				op=stackX[topX];
				printf("%c", op);
				topX=topX-2;
				
			}
		}
		else if(s[i]=='*' || s[i]=='/')
		{
			if(top==-1 || (stack[top]=='+' || stack[top]=='-') || stack[top]=='(')
			{
				top++;
				stack[top]=s[i];
			}
			else
			{
				op=stack[top];
				printf("%c", op);
				stack[top]=s[i];
				op=stackX[topX-1];
				printf("%c", op);
				op=stackX[topX];
				printf("%c", op);
				topX=topX-2;
				
			}
		}
		
		
	}
	
	
	while(top>-1)
	{
		op=stack[top];
		printf("%c", op);
		top--;
	}
	for(i=0; i<=topX; i++)
	{
		op=stackX[i];
		printf("%c", op);
		
	}
	printf("\n");
}

