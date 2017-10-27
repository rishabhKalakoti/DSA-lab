#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
    int data;
    int visited;
    struct element *lChild;
    struct element *rChild;
}node;

node* root=NULL;

node* createNode(int val)
{
    node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=val;
	temp->visited=0;
	temp->lChild=NULL;
    temp->rChild=NULL;
	return temp;
}

void addNode(int val)
{
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp=createNode(val);
    if(root==NULL)
    {
        temp=createNode(val);
        root=temp;
    }
    else
    {   
        temp=root;
        while(1)
        {
            if(val < temp->data)
            {
                if(temp->lChild==NULL)
                {
                    temp->lChild = createNode(val);
                    break;
                }
                else
                {
                    temp=temp->lChild;
                }
            }
            else if(val > temp->data)
            {
                if(temp->rChild==NULL)
                {
                    temp->rChild = createNode(val);
                    break;
                }
                else
                {
                    temp=temp->rChild;
                }
            }
            else
            {
                break;
            } 
        }
    }
}

void main()
{
    int n;
	printf("enter no of nodes to enter\t");
	scanf("%d", &n);
	int i;
	printf("enter nodes one by one\n");
	for(i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		addNode(x);
	}
    
    node* Q[n];
    int x;
    x=-1;
    printf("------ BST traveral -------\n");
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp=root;
    temp->visited=1;
    Q[x+1]=temp;
    printf("%d\n", temp->data);
	x++;
	while(x>-1)
	{
		temp=Q[0];
		int j;
		for(j=0; j<x;j++)
			Q[j]=Q[j+1];
		Q[x]=NULL;
		x--;
		
		if(temp->lChild!=NULL && temp->lChild->visited == 0)
		{
			Q[x+1]=temp->lChild;
			temp->lChild->visited=1;
			printf("%d\n", temp->lChild->data);
			x++;
		}
		if(temp->rChild!=NULL && temp->rChild->visited == 0)
		{
			Q[x+1]=temp->rChild;
			temp->rChild->visited=1;
			printf("%d\n", temp->rChild->data);
			x++;
		}
	}
}
