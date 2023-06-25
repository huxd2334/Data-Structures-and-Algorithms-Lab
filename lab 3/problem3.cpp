#include <bits/stdc++.h>
using namespace std;

typedef struct node 
{
	int person_id;
	struct node *next;
}NODE;

NODE *start, *ptr, *node;

int main()
{
	int n, k, i;
	cout<< "\nEnter the number of people: ";
	cin>> n;
	cout<< "\nEnter the number of people are skipped: ";
	cin>> k;
	
	start = new NODE;
	start->person_id = 1;
	ptr = start;
	for (i=2; i<=n; i++)
	{
		node			=	new NODE;
		ptr->next		=	node;
		node->person_id	=	i;
		node->next		=	start;
		ptr				=	node;
	}
	for (int count=n; count>1; count--)
	{
		for (i=0; i<k-1; ++i)	ptr = ptr->next;
		ptr->next		=	ptr->next->next;
	}
	cout<< "\nThe winner is person "<< ptr->person_id;
	return 0;	
}
