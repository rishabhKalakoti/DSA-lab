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

int checkPath(char x, char y)
{
	
	node* temp;
	temp=(node*)malloc(sizeof(node));
    // bfs inplementation

	temp=start;
	while(temp!=NULL)
	{
		temp->visited=0;
		temp=temp->next;
	}
	
    int c=-1;
    node* Q[N];
    temp=searchVertex(x);
    temp->visited=1;
    
    edge* tempE;
	tempE=(edge*)malloc(sizeof(edge));
			
    Q[c+1]=temp;
    if(temp->data==y)
    	return 1;
	c++;
	while(c>-1)
	{
		temp=Q[0];
		int j;
		for(j=0; j<c;j++)
			Q[j]=Q[j+1];
		Q[c]=NULL;
		c--;
		// add all
		// while queuing, check, visited=1, x++
		if(temp->path!=NULL)
		{
			tempE=temp->path;
			// chk
			if(tempE->data==y)
				return 1;
			if(searchVertex(tempE->data)->visited!=1)
			{
				searchVertex(tempE->data)->visited=1;
				Q[c+1]=searchVertex(tempE->data);
				c++;
			}
			while(tempE->next!=NULL)
			{
				tempE=tempE->next;
				// chk
				if(tempE->data==y)
					return 1;
				if(searchVertex(tempE->data)->visited!=1)
				{
					searchVertex(tempE->data)->visited=1;
					Q[c+1]=searchVertex(tempE->data);
					c++;
				}
			}
		}
	}
	return 0;
}

void main()
{
	printf("\n");
	
	// add or remove vertex
	addVertex('A');
	addVertex('B');
	addVertex('C');
	addVertex('D');
	addVertex('E');
	addVertex('F');
	removeVertex('F');
	printVertex();
	
	// add or remove edge
	addEdge('A', 'B');
	addEdge('B', 'C');
	addEdge('C', 'A');
	addEdge('C', 'D');
	addEdge('A', 'D');
	addEdge('A', 'C');
	removeEdge('A', 'C');
	
	printEdge('A');
	printEdge('B');
	printEdge('C');
	printEdge('D');
	
	// check path
	char x = 'A';
	char y = 'D';
	if(checkPath(x,y)==1)
	{
		printf("Path exists from %c to %c.\n", x, y);
	}
	else
	{
		printf("Path does not exists from %c to %c.\n", x, y);
	}
	
	printf("All good!\n\n");
}
