#include<stdio.h>

struct Node 
{
	int key;
	struct Node *left,*right;
	int height;
};

int max(int a,int b)
{
	return (a>b)?a:b;
}	

int height(struct Node *n)
{
	return (n==NULL)?0:n->height;
}

struct Node* newnode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key=key;
	node->left=node->right=NULL;
	node->height=1;
	return node;
}

struct Node* minValueNode(struct Node* node)
{
	struct Node* current = node;
	while(current->left!=NULL)
	current=current->left;
	return current;
}

struct Node* leftRotate(struct Node* x)
{
	struct Node* y = x->right;
	struct Node* t2 = y->left;
	y->left=x;
	x->right=t2;
	x->height=max(height(x->left),height(x->right)) + 1;
	y->height=max(height(y->left),height(y->right)) + 1;
	return y;
}

int getBalance(struct Node* n)
{
	return (n==NULL) ? 0 : height(n->left)-height(n->right);
}

struct Node* rightRotate(struct Node* y)
{
	struct Node* x = y->left;
	struct Node* t2 = x->right;
	x->right=y;
	y->left=t2;
	y->height=max(height(y->left),height(y->right)) + 1;
	x->height=max(height(x->left),height(x->right)) + 1;
	return x;
}
