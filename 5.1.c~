#include<string.h>
#include<stdio.h>

void main()
{
	char s[50];
	printf("\nInput the infix expression:\n");
	scanf("%s", s);
	
	int i;
	char stack[25];
	int top=-1;
	char op;
	int l=strlen(s);
	printf("%d", l);
	printf("\nPostfix expression:\n");
	for(i=0; i<l; i++)
	{
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
		{
			printf("%c", s[i]);
		}
		else if(s[i]=='(')
		{
			top++;
			stack[top]=s[i];
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
			}
		}
		else if(s[i]==')')
		{
			while(stack[top]!='(')
			{
				op=stack[top];
				printf("%c", op);
				top--;
			}
			top--;
		}
		
	}
	while(top>-1)
	{
		op=stack[top];
		printf("%c", op);
		top--;
	}
	printf("\n");
}
