#include<stdio.h>
#include<stdlib.h>

typedef struct element1
{
	char data;
	struct element1 *next;
}edge;

typedef struct element
{
	char data;
	int visited;
	struct element1 *path;
	struct element *next;
}node;

node* start=NULL;
int N=0;

void addVertex(char data)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->visited=0;
	temp->path=NULL;
	temp->next=NULL;
	
	node* tempT;
	tempT=(node*)malloc(sizeof(node));
	if (start==NULL)
	{
		start=temp;
	}
	else
	{
		tempT=start;
		while(tempT->next!=NULL)
		{
			tempT=tempT->next;
		}
		tempT->next=temp;
	}
	N++;
}

void addEdge(char v, char u)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	
	edge* tempE;
	tempE=(edge*)malloc(sizeof(edge));
	
	temp=start;
	
	if(temp->data!=v)
	{
		while(temp->next->data!=v)
			temp=temp->next;
		temp=temp->next;
		
	}
	
	edge* e;
	e=(edge*)malloc(sizeof(edge));
	e->data=u;
	e->next=NULL;
	if(temp->path==NULL)
	{
		temp->path=e;
	}
	else
	{
		tempE=temp->path;
		while(tempE->next!=NULL)
			tempE=tempE->next;
		tempE->next=e;
	}
}


node* searchVertex(char data)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	
	temp=start;
	if(temp->data==data)
	{
		return temp;
	}
	else
	{
		while(temp->next->data!=data)
			temp=temp->next;
		temp=temp->next;
		return temp;
	}
}


int dfs(node* temp)
{
	temp->visited=1;
	if(temp->path!=NULL)
	{
		edge* tempE;
		tempE=(edge*)malloc(sizeof(edge));
		tempE=temp->path;
		while(tempE!=NULL)
		{
			if(searchVertex(tempE->data)->visited==0)
			{
				if(dfs(searchVertex(tempE->data))==1)
				{
					return 1;
				}
			}
			else if(searchVertex(tempE->data)->visited==1)
			{
				return 1;
			}
			tempE=tempE->next;
		}
	}
	temp->visited=2;
	return 0;
}

int checkCycle(node* temp)
{
    temp=start;
	while(temp!=NULL)
	{
		temp->visited=0;
		temp=temp->next;
	}
	temp=start;
    while(temp!=NULL)
    {
    	if(temp->visited==0)
    	{
			if(dfs(temp)==1)
			{
				return 1;
			}
		}
    	temp=temp->next;
    }
    return 0;
}
void main()
{
	addVertex('A');
	addVertex('B');
	addVertex('C');
	addVertex('D');
	
	// case 1
	/*
	addEdge('A', 'B');
	addEdge('A', 'C');
	addEdge('B', 'D');
	addEdge('D', 'C');
	addEdge('D', 'A');
	*/
	// case 2
	
	addEdge('A', 'B');
	addEdge('A', 'C');
	addEdge('D', 'C');
	addEdge('D', 'B');
	
	// check cycle
	if(checkCycle(start)==1)
		printf("Cycle Exists\n");
	else
		printf("Cycle does not exist\n");
}
