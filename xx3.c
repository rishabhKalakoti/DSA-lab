#include<stdio.h>
#include<stdlib.h>

typedef struct nd
{
	int val;
	struct nd *next;
}node;


node* createNode(int n)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->val=n;
	temp->next=NULL;
	return temp;
}

void delFromFirst(node* head)
{
	node* tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp=head->next;
	head->next=tmp->next;
	printf("deleted %d\n", tmp->val);
	free(tmp);
}
void addAtFirst(node* head, int n)
{
	node* tmp;
	
	tmp=(node*)malloc(sizeof(node));
	tmp=createNode(n);
	if(head->next!=NULL)
	{
		tmp->next=head->next;
	}
	head->next=tmp;
}
void addAtLast(node* head, int n)
{
	node* tmp;
	tmp=(node*)malloc(sizeof(node));
	node* tmpX;
	tmpX=(node*)malloc(sizeof(node));
	
	tmp=createNode(n);
	tmpX=head;
	while(tmpX->next!=NULL)
	{
		tmpX=tmpX->next;
	}
	tmpX->next=tmp;
}

void main()
{
	node* head;
	head=(node*)malloc(sizeof(node));
	head->val= 0;
	head->next=NULL;
	
	// stack.
	addAtFirst(head, 4);	//push
	addAtFirst(head, 5);	//push
	addAtFirst(head, 10);	//push
	delFromFirst(head);		//pop
	
	// print stack
	do
	{
		head=head->next;
		printf("%d\n", head->val);
	}while(head->next!=NULL);
	
	// insert at first
	// delete at first
	
	head->val=0;
	head->next=NULL;
	
	printf("\n\n");
	// queue.
	// insert at last
	addAtLast(head, 4);		//push
	addAtLast(head, 5);		//push
	addAtLast(head, 5);		//push
	// delete at first
	delFromFirst(head);		//pop
	// print queue
	do
	{
		head=head->next;
		printf("%d\n", head->val);
	}while(head->next!=NULL);
	
	
}
