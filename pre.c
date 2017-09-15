//infix to prefix
#include<stdio.h>
#include<string.h>

char * rev(char string[])
{
	int n=strlen(string);
	int i=0;
	char temp;
	for(i=0;i<=n/2;i++){
		temp=string[i];
		string[i]=string[n-1-i];
		string[n-1-i]=temp;
	}
	for(i=0;i<=n;i++){
		if(string[i]=='(')
			string[i]=')';
		else if(string[i]==')')
			string[i]='(';
	}
	return string;
}
int isOperator(char ch)
{
	switch(ch){
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
			return 1;
		default:
			return 0;
	}
}
int presi(char ch){
	switch(ch){
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		case '(':
		case ')':
		case '#':
			return 1;
		}
}		


void convert(char infix[],char postfix[]){
	char stack[25],ch;
	int top=-1,i=0,j=0;
	void push(int ch){
		stack[++top]=ch;
	}
	int pop(){
		return stack[top--];
	}
	stack[++top]='#';
	for(i=0;i<strlen(infix);i++){
		ch=infix[i];
		if(!isOperator(ch)){
			postfix[j]=ch;
			j++;
		}
		else if(ch=='('){
			push(ch);
			}
		else if(ch==')'){
			while(stack[top]!='('){
				postfix[j]=pop();
				j++;
			}
			pop();
			}
		else if(presi(ch)>presi(stack[top])){
			push(ch);
		}
		else{
			while(presi(ch)<=presi(stack[top])){
				postfix[j]=pop();
				j++;
			}
			push(ch);
		}
			
	}
	for(i=0;stack[top]!='#';i++){
		postfix[j]=pop();
		j++;
	}


}

void main()
{	
	
	char infix[25]="A+(B*C-(D/E-F)*G)*H";	
	char postfix[25];
	char prefix[25];
	strcpy(infix,rev(infix));
	convert(infix,postfix);
	strcpy(postfix,rev(postfix));
	printf("prefix is : %s\n",postfix);
}
