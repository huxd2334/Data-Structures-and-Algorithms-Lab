#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int coeff;
	int num;
	struct node *next;
}NODE;

void insert(NODE **, int coeff, int num);
void display(NODE *);
NODE *add(NODE *poly1, NODE *poly2);
NODE *sub(NODE *poly1, NODE *poly2);

int main()
{
	NODE *poly1	=	NULL;
	insert(&poly1, 5, 4);
	insert(&poly1, 8, 2);
	insert(&poly1, 3, 0);
	
	NODE *poly2	=	NULL;
	insert(&poly2, 9, 2);
	insert(&poly2, 4, 1);
	
	cout<<"1st polynomial:\t\t"; display(poly1);
	cout<<"2nd polynomial:\t\t"; display(poly2);
	
	NODE *rs1	=	add(poly1, poly2);
	cout<<"\nAfter adding:\t\t"; display(rs1);
	
	NODE *rs2	=	sub(poly1, poly2);
	cout<<"After subtracting:\t"; display(rs2);
}

void insert(NODE **poly, int coeff, int num)
{
	NODE *node	=	new NODE;
	node->coeff	=	coeff;
	node->num	=	num;
	node->next	=	NULL;
	
	if (*poly	==	NULL)
	{
		*poly	=	node;
		return;
	}
	
	NODE *pre	=	*poly;
	while (pre->next	!=	NULL)
		pre		=	pre->next;
	pre->next	=	node;
}

void display(NODE *poly)
{
	if (poly == NULL)
	{
		cout<<"0\n";
		return;
	}
	NODE *pre	=	poly;
	while (pre != NULL)
	{
		cout<<	pre->coeff<<"x^"<<pre->num;
		if(pre->next != NULL)
			cout<<	" + ";
		pre		=	pre->next;
	}
	cout<<endl;
}

NODE *add(NODE *poly1, NODE *poly2)
{
	NODE *rs	=	NULL;
	while (poly1 != NULL & poly2 != NULL)
	{
		if (poly1->num == poly2->num)
		{
			insert (&rs, poly1->coeff+poly2->coeff, poly1->num);
			poly1	=	poly1->next;
			poly2	=	poly2->next;
		}
		else if (poly1->num > poly2->num)
		{
			insert (&rs, poly1->coeff, poly1->num);
			poly1	=	poly1->next;
		}
		else
		{
			insert (&rs, poly2->coeff, poly2->num);
			poly2	=	poly2->next;
		}
	}
	while (poly1 != NULL)
	{
		insert (&rs, poly1->coeff, poly1->num);
		poly1	=	poly1->next;
	}
	while (poly1 != NULL)
	{
		insert (&rs, poly2->coeff, poly2->num);
		poly2	=	poly2->next;
	}
	return rs;
}

NODE *sub(NODE *poly1, NODE *poly2)
{
	NODE *rs	=	NULL;
	while (poly1 != NULL & poly2 != NULL)
	{
		if (poly1->num == poly2->num)
		{
			insert (&rs, poly1->coeff-poly2->coeff, poly1->num);
			poly1	=	poly1->next;
			poly2	=	poly2->next;
		}
		else if (poly1->num > poly2->num)
		{
			insert (&rs, poly1->coeff, poly1->num);
			poly1	=	poly1->next;
		}
		else
		{
			insert (&rs, poly2->coeff, poly2->num);
			poly2	=	poly2->next;
		}
	}
	while (poly1 != NULL)
	{
		insert (&rs, poly1->coeff, poly1->num);
		poly1	=	poly1->next;
	}
	while (poly1 != NULL)
	{
		insert (&rs, poly2->coeff, poly2->num);
		poly2	=	poly2->next;
	}
	return rs;
}
