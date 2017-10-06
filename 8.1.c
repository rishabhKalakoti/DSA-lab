
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

void deleteNode(int val, node* start)
{
    node* temp;
    temp=(node*)malloc(sizeof(node));
    if(start==NULL)
    {
        printf("Not Found to delete!!!\n");
    }
    else
    {
        temp=start;
        while(1)
        {
            if(val < temp->data)
            {
                temp=temp->lChild;
                
            }
            else if(val > temp->data)
            {
                temp=temp->rChild;
                
            }
            else if(val == temp->data)
            {
            	node* x;
            	x=(node*)malloc(sizeof(node));
            	x=temp;
            	// find prev
            	node* prev;
            	prev=(node*)malloc(sizeof(node));
            	prev=root;
            	int flag;
            	flag=0;
            	while(1)
            	{
            		
            		if(val==prev->lChild->data)
            		{
            			//flag=-1;
            			break;
            		}
            		if(val==prev->rChild->data)
            		{
            			//flag=1;
            			break;
            		}
            		if(val < prev->data)
            		{
            			prev=prev->lChild;
            		}
            		else if(val > prev->data)
            		{
            			prev=prev->rChild;
            		}
            		else if(val==prev->data)
            		{
            			flag=1;
            			break;
            		}
            	}
            	
            	if(x->lChild==NULL && x->rChild==NULL)
            	{
            		printf("prev-%d", prev->data);
            		printf("x-%d", x->data);
            		//free(x);
            		if(prev->lChild->data==x->data)
            		{
            			prev->lChild=NULL;
            			
            		}
            		else if(prev->rChild->data==x->data)
            			prev->rChild=NULL;
            		free(x);
            	}
            	else if(x->lChild==NULL && x->rChild!=NULL)
            	{
            		if(prev->lChild==x)
            			prev->lChild=x->rChild;
            		else if(prev->rChild==x)
            			prev->rChild=x->rChild;
            		free(x);
            	}
            	else
            	{
            		node* y;
            		y=(node*)malloc(sizeof(node));
            		y=x->lChild;
            		while(y->rChild!=NULL)
            			y=y->rChild;
            		x->data=y->data;
            		
            		printf("delete-%d", y->data);
            		deleteNode(y->data, x->lChild);
            	}
            	if(flag==1)
            	{
            		root=prev;
            	}
            	//temp->data=0;
            	
            	//free(temp);
            	return;
            }
            else
            {
            	printf("Not Found to delete!!!\n");
                break;
            } 
        }
    }
}

void preOrder(node* temp)
{
    printf("%d\n", temp->data);
    if(temp->lChild!=NULL)
        preOrder(temp->lChild);
    if(temp->rChild!=NULL)
    preOrder(temp->rChild);
}

void inOrder(node* temp)
{
    if(temp->lChild!=NULL)
        inOrder(temp->lChild);
    printf("%d\n", temp->data);
    if(temp->rChild!=NULL)
        inOrder(temp->rChild);
}

void postOrder(node* temp)
{
    if(temp->lChild!=NULL)
        postOrder(temp->lChild);
    if(temp->rChild!=NULL)
        postOrder(temp->rChild);
    printf("%d\n", temp->data);
}

void main()
{
    insertNode(3);
    insertNode(2);
    insertNode(0);
    insertNode(1);
    insertNode(5);
    insertNode(4);
    insertNode(8);
    //insertNode(5);
    deleteNode(2, root);
    
    
    printf("\nPreorder:\n");
    preOrder(root);
    printf("\nInorder:\n");
    inOrder(root);
    printf("\nPostorder:\n");
    postOrder(root);
}
