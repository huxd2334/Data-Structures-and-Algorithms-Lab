#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int coeff;
	int num;
	struct node *next;
}NODE;
void input(int, int, NODE **);
void output(NODE *);
void add(NODE *, NODE	*, NODE *);
void sub(NODE *, NODE	*, NODE *);

int main()
{
	
	NODE *poly1		=	NULL ;
	NODE *poly2		=	NULL ;
	NODE *polyAdd	=	NULL ;
	NODE *polySub	=	NULL;
	

	// 6x^2+5x+8
	input(6, 2, &poly1);
	input(5, 1, &poly1);
	input(8, 0, &poly1);
	//7x+3
	input(7, 1, &poly2);
	input(3, 0, &poly2);

	
	cout<<	"\nThe first polynomial:\t\t";
	output(poly1);
	cout<<	"\nThe second polynomail:\t\t";
	output(poly2);
	
	polyAdd		= 	new NODE;
	add(poly1, poly2, polyAdd);
	cout<<	"\n\nAddition on 2 polynomials:\t";
	output(polyAdd);
	
	polySub		=	new NODE;
	sub(poly1, poly2, polySub);
	cout<<	"\nSubtraction on 2 polynomials:\t";
	output(polySub);
	
	return 0;
}

void input(int x, int y, NODE **temp)
{
	NODE *c;
	NODE *d;
	d				=	*temp;
	if (d == NULL)
	{
		c			=	new NODE;
		c->coeff	=	x;
		c->num		=	y;
		*temp		=	c;
		c->next		=	new NODE;
		c			=	c->next;
		c->next		=	NULL;
	}
	else
	{
		c->coeff	=	x;
		c->num		=	y;
		c->next		= 	new NODE;
		c			=	c->next;
		c->next		=	NULL;
	}
}

void add(NODE *poly1, NODE *poly2, NODE *poly)
{
	while (poly1->next && poly2->next)
	{
		if( poly1->num > poly2->num)
		{
			poly->num		=	poly1->num;
			poly->coeff		=	poly1->coeff;
			poly1			=	poly1->next;
		}
		else if(poly1->num < poly2->num)
		{
			poly->num		=	poly2->num;
			poly->coeff		=	poly2->coeff;
			poly2			=	poly2->next;
		}
		else
		{
			poly->num		=	poly1->num;
			poly->coeff		=	poly1->coeff + poly2->coeff;
			poly1			=	poly1->next;
			poly2			=	poly2->next;
		}
		poly->next			=	new NODE;
		poly				=	poly->next;
		poly->next			=	NULL;
	}
	while (poly1->next || poly2->next)
	{
		if (poly1->next)
		{
		poly->num			=	poly1->num;
		poly->coeff			=	poly1->coeff;
		poly1				=	poly1->next;
		}
		if (poly2->next)
		{
			poly->num		=	poly2->num;
			poly->coeff		=	poly2->coeff;
			poly2			=	poly2->next;
		}
		poly->next			=	new NODE;
		poly				=	poly->next;
		poly->next			=	NULL;
	}
}

void sub(NODE *poly1, NODE *poly2, NODE *poly)
{
	while (poly1->next && poly2->next)
	{
		if( poly1->num > poly2->num)
		{
			poly->num		=	poly1->num;
			poly->coeff		=	poly1->coeff;
			poly1			=	poly1->next;
		}
		else if(poly1->num < poly2->num)
		{
			poly->num		=	poly2->num;
			poly->coeff		=	poly2->coeff;
			poly2			=	poly2->next;
		}
		else
		{
			poly->num		=	poly1->num;
			poly->coeff		=	poly1->coeff - poly2->coeff;
			poly1			=	poly1->next;
			poly2			=	poly2->next;
		}
		poly->next			=	new NODE;
		poly				=	poly->next;
		poly->next			=	NULL;
	}
	while (poly1->next || poly2->next)
	{
		if (poly1->next)
		{
		poly->num			=	poly1->num;
		poly->coeff			=	poly1->coeff;
		poly1				=	poly1->next;
		}
		if (poly2->next)
		{
			poly->num		=	poly2->num;
			poly->coeff		=	poly2->coeff;
			poly2			=	poly2->next;
		}
		poly->next			=	new NODE;
		poly				=	poly->next;
		poly->next			=	NULL;
	}
}

void output(NODE *node)
{
	while(node->next != NULL)
	{
		cout<<	 node->coeff <<"x^"<< node->num;
		node				=	node->next;
		if (node->coeff >= 0)
		{
			if (node->next != NULL)
				cout<< " + ";
		}
	}
}




