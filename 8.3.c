#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
    int data;
    struct element *lChild;
    struct element *rChild;
}node;


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

struct Node *leftRotate(node *x)
{
    node *y = x->rChild;
    node *T2 = y->lChild;
 
    y->lChild = x;
    x->rChild = T2;

    return y;
}

struct Node *rightRotate(node *y)
{
    node *x = y->rChild;
    node *T2 = x->rChild;
 
    x->rChild = y;
    y->lChild = T2;

    return x;
}
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node* balance(node* Node)
{
 	int bal = getBalance(Node);
 	data=Node->data;
    if (bal > 1 && data < Node->left->data)
        return rightRotate(Node);

    if (bal < -1 && data > Node->right->data)
        return leftRotate(Node);

    if (bal > 1 && data > Node->left->data)
    {
        node->left =  leftRotate(Node->left);
        return rightRotate(Node);
    }

    if (bal < -1 && data < Node->right->data)
    {
        node->right = rightRotate(Node->right);
        return leftRotate(Node);
    }
    balance(Node->lChild);
    balance(Node->rChild);
}


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
    balance(root);
}

void preOrder(node* temp)
{
    printf("%d\n", temp->data);
    if(temp->lChild!=NULL)
        preOrder(temp->lChild);
    if(temp->rChild!=NULL)
    preOrder(temp->rChild);
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
    //deleteNode(70, root);
    
    
    printf("\nPreorder:\n");
    preOrder(root);

}
