#include<stdio.h>
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

void insertNode(int val)
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


int height(node* temp)
{
	int l, r;
	if(temp->lChild != NULL && temp->rChild != NULL)
	{
		
		l=height(temp->lChild);
		r=height(temp->rChild);
		if(l>r)
			return l+1;
		else
			return r+1;
	}
	else if(temp->lChild != NULL && temp->rChild == NULL)
	{
		return height(temp->lChild) + 1;
	}
	else if(temp->lChild == NULL && temp->rChild != NULL)
	{
		return height(temp->rChild) + 1;
	}
	else
	{
		return 1;
	}
}

int complete(node* temp)
{
	int l,r;
	if(temp->lChild != NULL && temp->rChild != NULL)
	{
		
		l=height(temp->lChild);
		r=height(temp->rChild);
		if(l != r)
			return 0;
		else
		{
			complete(temp->lChild);
			complete(temp->rChild);
		}
	}
	else if(temp->lChild != NULL && temp->rChild == NULL)
	{
		return 0;
	}
	else if(temp->lChild == NULL && temp->rChild != NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void main()
{
	insertNode(40);
    insertNode(20);
    insertNode(60);
    insertNode(10);
    insertNode(30);
    insertNode(70);
    insertNode(50);
    insertNode(5);
    if(complete(root)==0)
    	printf("incomplete\n");
    else
    	printf("complete\n");
}
