#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE *tree;
void create(NODE *);
NODE *insert(NODE *, int);
void preTraversal (NODE *);
void inTraversal (NODE *);
void postTraversal (NODE *);
NODE *findSmallest (NODE *);
NODE *findLargest (NODE *);
int nodeTotal(NODE *);
int internalNodeTotal (NODE *);
int height (NODE *);
NODE *remove (NODE *, int);

int main()
{
	int choice, val;
	NODE *ptr;
	create(tree);
	tree = insert(tree, 8);
	tree = insert(tree, 3);
    tree = insert(tree, 10);
    tree = insert(tree, 1);
    tree = insert(tree, 6);
    tree = insert(tree, 4);
    tree = insert(tree, 7);
    tree = insert(tree, 9);
    tree = insert(tree, 14);
    tree = insert(tree, 13);
	do
	{
		cout<<"\n";
		cout<<"\n====================MENU===================";
		cout<<"\n1. Insert a node";
		cout<<"\n\tTraverse the tree in";
		cout<<"\n2. Pre-order";
		cout<<"\n3. In-order";
		cout<<"\n4. Post-order";
		cout<<"\n5. Find the smallest element";
		cout<<"\n6. Find the largest one";
		cout<<"\n7. Find node total";
		cout<<"\n8. Find internal node total";
		cout<<"\n9. Find the height of tree";
		cout<<"\n10. Delete a node";
		cout<<"\nYour choice: ";
		cin>> choice;
		switch (choice)
		{
			case 1:
				cout<<"\nEnter the node's value: ";
				cin>> val;
				tree = insert(tree, val);
				break;
			case 2:
				preTraversal(tree);
				break;
			case 3: 
				inTraversal(tree);
				break;
			case 4:
				postTraversal(tree);
				break;
			case 5:
				ptr = findSmallest(tree);
				cout<< ptr->data;
				break;
			case 6:
				ptr = findLargest(tree);
				cout<< ptr->data;
				break;
			case 7:
				cout<< nodeTotal(tree);
				break;
			case 8: 
				cout<< internalNodeTotal(tree);
				break;
			case 9:
				cout<< height(tree);
				break;
			case 10:
				tree = remove(tree, val);
				break;
			default:
				cout<<"Wrong statement. Enter again!";
		}
	
	}
	while (choice != 11);
}

void create(NODE *tree)
{
	tree = NULL;
}

NODE *insert(NODE *tree, int val)
{
	NODE *ptr, *nodeptr, *parentptr;
	ptr	=	new NODE;
	ptr->data	= val;
	ptr->left	= NULL;
	ptr->right	= NULL;
	if (tree == NULL)
	{
		tree		=	ptr;
		tree->left	=	NULL;
		tree->right	=	NULL;
	}
	else
	{
		parentptr	=	NULL;
		nodeptr		=	tree;
		while (nodeptr != NULL)
		{
			parentptr = nodeptr;
			if ( val < nodeptr->data)	nodeptr = nodeptr->left;
			else						nodeptr = nodeptr->right;
		}
		if (val < parentptr->data)		parentptr->left		= ptr;
		else							parentptr->right 	= ptr;
	}
	return tree;
}

void preTraversal(NODE *tree)
{
	if (tree != NULL)
	{
		cout<<tree->data;
		preTraversal(tree->left);
		preTraversal(tree->right);
	}
}

void inTraversal(NODE *tree)
{
	if (tree != NULL)
	{
		inTraversal(tree->left);
		cout<<tree->data;
		inTraversal(tree->right);
	}
}

void postTraversal(NODE *tree){
	if (tree != NULL)
	{
		postTraversal(tree->left);
		postTraversal(tree->right);
		cout<< tree->data;
	}
}

NODE *findSmallest (NODE *tree)
{
	if (tree == NULL or tree->left == NULL)		return tree;
	else										return findSmallest(tree->left);
}

NODE *findLargest (NODE *tree)
{
	if (tree == NULL or tree->right == NULL)	return tree;
	else										return findLargest(tree->right);
}

NODE *remove (NODE *tree, int val)
{
	NODE *cur, *parent, *suc, *psuc, *ptr;
	if (tree->left == NULL)
	{
		cout<<"\nEmpty tree";
		return tree;
	}
	parent 	=	tree;
	cur		=	tree->left;
	while (cur != NULL and val != cur->data)
	{
		parent 	= cur;
		cur 	= (val < cur->data) ? cur->left : cur->right;	
	}
	if (cur == NULL)
	{
		cout<< "Not found";
		return tree;
	}
	if (cur->left == NULL)			ptr = cur->right;
	else if (cur->right == NULL)	ptr = cur->left;
	else
	{
		psuc	=	cur;
		suc		=	suc->left;
		while (suc->left != NULL)
		{
			psuc 	= suc;
			suc		= suc->left;
		}
		if (cur = psuc)		suc->left = cur->right;
		else
		{
			suc->left 	= cur->left;
			psuc->left	= suc->right;
			suc->right	= cur->right;
		}
		ptr = suc;
	}
	if (parent->left = cur)		parent->left 	= ptr;
	else						parent->right 	= ptr;
	delete cur;
	return tree;
}

int nodeTotal (NODE *tree)
{
	if (tree == NULL)		return 0;
	else					return (nodeTotal(tree->left) + nodeTotal(tree->right) + 1);
}

int internalNodeTotal (NODE *tree)
{
	if (tree == NULL)		return 0;
	else if (tree->left == NULL and tree->right == NULL) return 1;
	else 					return (internalNodeTotal(tree->left)+internalNodeTotal(tree->right));	
}

int height (NODE *tree)
{
	int leftside, rightside;
	if (tree == NULL)		return 0;
	else
	{
		leftside 	= height(tree->left);
		rightside	= height(tree->right);
		if (leftside > rightside)		return (1+leftside);
		else							return (1+rightside);
	}
}

