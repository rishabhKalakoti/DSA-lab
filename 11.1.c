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

void removeVertex(char data)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	
	temp=start;
	if(temp->data==data)
	{
		start=temp->next;
		free(temp);
	}
	else
	{
		while(temp->next->data!=data)
			temp=temp->next;
		node* temp1;
		temp1=(node*)malloc(sizeof(node));
		temp1=temp->next;
		temp->next=temp1->next;
		free(temp1);
	}
	N--;
}

void printVertex()
{
	printf("Vertices:\t");
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp=start;
	while(temp!=NULL)
	{
		printf("%c ", temp->data);
		temp=temp->next;
	}
	printf("\n");
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

void removeEdge(char v, char u)
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
	//
	if(temp->path!=NULL)
	{
		tempE=temp->path;
		if(tempE->data==u)
		{
			temp->path=tempE->next;
			free(tempE);
		}
		else
		{
			edge* tempE1;
			tempE1=(edge*)malloc(sizeof(edge));
		
			while(tempE->next->data!=u)
				tempE=tempE->next;
			tempE1=tempE->next;
			tempE->next=tempE1->next;
			free(tempE1);
		}
		
	}
}

void printEdge(char data)
{
	printf("%c:\t",data);
	node* temp;
	temp=(node*)malloc(sizeof(node));
	
	temp=start;
	while(temp->data!=data)
		temp=temp->next;
	if(temp->path!=NULL)
	{
		edge* tempE;
		tempE=(edge*)malloc(sizeof(edge));
		
		tempE=temp->path;
		while(tempE->next!=NULL)
		{
			printf("-%c", tempE->data);
			tempE=tempE->next;
		}
		printf("-%c", tempE->data);
	}
	printf("\n");
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
	// push all elements to stack one by one and implement dfs on them
	temp->visited=1;
	//printf("%c ", temp->data);
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
    // dfs inplementation
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
	//printf("\n");
	addVertex('A');
	addVertex('B');
	addVertex('C');
	addVertex('D');
	//printVertex();
	
	// case 1
	
	addEdge('A', 'B');
	addEdge('A', 'C');
	addEdge('B', 'D');
	addEdge('D', 'C');
	addEdge('D', 'A');
	// case 2
	
	//addEdge('A', 'B');
	//addEdge('A', 'C');
	//addEdge('D', 'C');
	//addEdge('D', 'B');
	
	//printEdge('A');
	
	// check cycle
	if(checkCycle(start)==1)
		printf("Cycle Exists\n");
	else
		printf("Cycle does not exist\n");
}
