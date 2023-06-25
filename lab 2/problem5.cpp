#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int coeff;
	int num;
	struct node *next;
}NODE;

NODE *start1	=	NULL;
NODE *start2	=	NULL;
NODE *rs1		=	NULL;
NODE *rs2		=	NULL;
NODE *start		=	NULL;

NODE *create(NODE *);
NODE *show(NODE *);
NODE *add_poly(NODE *, NODE *, NODE *);
NODE *sub_poly(NODE *, NODE *, NODE *);
NODE *add_node(NODE *, int	,	int);

int main()
{
	int choice;
	do
	{
		cout<<	"\n\t========================MENU=============================";
		cout<<	"\n1. Put the 1st polynomial";
		cout<<	"\n2. Display the 1st polynomial";
		cout<<	"\n3. Put the 2nd polynomial";
		cout<<	"\n4. Display the 2nd polynomial";
		cout<<	"\n5. Add polynomials";
		cout<<	"\n6. Display the result of the Addition";
		cout<<	"\n7. Subtract polynomials";
		cout<<	"\n8. Display the result of the Subtraction";
		cout<<	"\n0. Exit";
		cout<<	"\n\tEnter your choice: ";
		cin>>	choice;
		switch (choice)
		{
			case 1:
				start1	=	create(start1);
				break;
			case 2:
				start1	=	show(start1);
				break;
			case 3:
				start2	= 	create(start2);
				break;
			case 4:
				start2	=	show(start2);
				break;
			case 5:
				rs1		=	add_poly(start1, start2, rs1);
				break;
			case 6:
				rs1		=	show(rs1);
				break;
			case 7:
				rs2		=	sub_poly(start1, start2, rs2);
				break;
			case 8:
				rs2		=	show(rs2);
				break;	
			case 0:
				cout<<	"Goodbye...";
				exit(1);
			default:
				cout<<	"Wrong number. Please, enter again!!!";
				break;
		} 
		
		
	}while (choice != 0);
	
}

NODE *create(NODE *start)
{
	NODE *node, *ptr;
	int num, coeff;
	cout<<	"Enter the coefficient: ";
	cin>>	coeff;
	cout<<	"Enter its power: ";
	cin>>	num;
	
	while (coeff != -1)
	{
		if (start == NULL)
		{
			node		=	new NODE;
			node->num	=	num;
			node->coeff	=	coeff;
			node->next	=	NULL;
		}
		else
		{
			ptr			=	start;
			while (ptr->next != NULL) ptr	=	ptr->next;
			node		=	new NODE;
			node->coeff	=	coeff;
			node->num	=	num;
			node->next	=	NULL;
			ptr->next	=	node;
		}
		cout<<	"Enter the coefficient: ";
		cin>>	coeff;
		if (coeff == -1) break;
		cout<<	"Enter its power: ";
		cin>>	num;
	}
	return start;
}

NODE *show(NODE *start)
{
	NODE *ptr;
	ptr		=	start;
	while (ptr != NULL)
	{
		cout<<	ptr->coeff<<"x^"<<ptr->num;
	}
	return start;
}

NODE *add_poly(NODE *start1, NODE *start2, NODE *rs1)
{
	NODE *ptr1, *ptr2;
	int sum, num;
	ptr1		=	start1;
	ptr2		=	start2;
	
	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->num == ptr2->num)
		{
			sum		=	ptr1->coeff + ptr2->coeff;
			rs1		=	add_node(rs1, sum, ptr1->num);
			ptr1	=	ptr1->next;
			ptr2	=	ptr2->next;
		}
		else if (ptr1->num > ptr2->num)
		{
			rs1		=	add_node(rs1, ptr1->coeff, ptr1->num);
			ptr1	=	ptr1->next;
		}
		else
		{
			rs1		=	add_node(rs1, ptr2->coeff, ptr2->num);
			ptr2	=	ptr2->next;
		}
	}
	while (ptr1 != NULL)
	{
		rs1		=	add_node(rs1, ptr1->coeff, ptr1->num);
		ptr1	=	ptr1->next;
	}
	while (ptr2 != NULL)
	{
		rs1		=	add_node(rs2, ptr2->coeff, ptr2->num);
		ptr2	=	ptr2->next;
	}
	return rs1;
}

NODE *sub_poly(NODE *start1, NODE *start2, NODE *rs2)
{
	NODE *ptr1, *ptr2;
	int sub, num;
	ptr1		=	start1;
	ptr2		=	start2;
	
	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->num == ptr2->num)
		{
			sub		=	ptr1->coeff - ptr2->coeff;
			rs2		=	add_node(rs2, sub, ptr1->num);
			ptr1	=	ptr1->next;
			ptr2	=	ptr2->next;
		}
		else if (ptr1->num > ptr2->num)
		{
			rs2		=	add_node(rs2, ptr1->coeff, ptr1->num);
			ptr1	=	ptr1->next;
		}
		else
		{
			rs2		=	add_node(rs2, ptr2->coeff, ptr2->num);
			ptr2	=	ptr2->next;
		}
	}
	while (ptr1 != NULL)
	{
		rs2		=	add_node(rs2, ptr1->coeff, ptr1->num);
		ptr1	=	ptr1->next;
	}
	while (ptr2 != NULL)
	{
		rs2		=	add_node(rs2, ptr2->coeff, ptr2->num);
		ptr2	=	ptr2->next;
	}
	return rs2;
}

NODE *add_node (NODE *start, int coeff, int num)
{
	NODE *ptr, *node;
	if (start == NULL)
	{
		node 		=	new NODE;
		node->coeff	=	coeff;
		node->num	=	num;
		node->next	=	NULL;
		start		=	new NODE;
	}
	else
	{
		ptr			=	start;
		while (ptr->next != NULL) ptr	=	ptr->next;
		node		=	new NODE;
		node->coeff	=	coeff;
		node->num	=	num;
		node->next	=	NULL;
		ptr->next	=	new NODE;
	}
	return start;
}




