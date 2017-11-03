#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct element
{
    int data;
    struct element *lChild;
    struct element *rChild;
}node;

node* root=NULL;

node* createNode(int val)
{
    node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=val;
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

   	int a, b;
   	printf("give two nodes to compare\n");
   	scanf("%d %d", &a, &b);
   	
   	int arrA[n], arrB[n];
   	int ptrA=-1;
   	int ptrB=-1;
   	
   	node* temp;
    temp=(node*)malloc(sizeof(node));
   	temp=root;
    while(1)
    {
    	if(a!=temp->data)
    	{
    		ptrA++;
        	arrA[ptrA]=temp->data;
        	if(a < temp->data)
		    { 	
		        temp=temp->lChild;
		    }
		    else if(a > temp->data)
		    {
		        temp=temp->rChild;
		    }
    	}
        else
        {
        	ptrA++;
        	arrA[ptrA]=temp->data;
        	
            break;
        } 
    }
    
    temp=root;
    while(1)
    {
    	if(b!=temp->data)
    	{
    		ptrB++;
        	arrB[ptrB]=temp->data;
        	if(b < temp->data)
		    { 	
		        temp=temp->lChild;
		    }
		    else if(b > temp->data)
		    {
		        temp=temp->rChild;
		    }
    	}
        else if(b==temp->data)
        {
        	ptrB++;
        	arrB[ptrB]=temp->data;
            break;
        } 
    }
    int diff=0;
    if(ptrA!=ptrB)
    {
    	diff=abs(ptrA-ptrB);
    }
    //printf("%d\n", diff);
    if(ptrA>ptrB)
    {
    	ptrA=ptrB;

    }
    while(arrA[ptrA]!=arrB[ptrA])
	{
		diff=diff + 2;
		ptrA--;
	}
    
    
   	printf("difference bwtween the nodes is: %d\n", diff);
}


