// tree traversal and creation for binary tree.
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
    addNode(40);
    addNode(20);
    addNode(60);
    addNode(10);
    addNode(30);
    addNode(70);
    addNode(50);
    
    printf("\nPreorder:\n");
    preOrder(root);
    printf("\nInorder:\n");
    inOrder(root);
    printf("\nPostorder:\n");
    postOrder(root);
}
