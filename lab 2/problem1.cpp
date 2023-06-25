#include <bits/stdc++.h>
using namespace std;

typedef struct student
{
	char	name[50];
	int 	year;
	float	math;
	float	physic;
	float	language;
	float 	average()
	{
		return (physic + language + math)/3;
	}
}STUDENT;

typedef struct node
{
	STUDENT	data;
	struct node	*next;
}NODE;

NODE *start	=	NULL;

void input(STUDENT &st)
{
	fflush(stdin);
	cout<<"\nName: ";
	gets(st.name);
	cout<<"\nYear of birth: ";
	cin>> st.year;
	cout<<"\nMath: ";
	cin>> st.math;
	cout<<"\nPhysic: ";
	cin>> st.physic;
	cout<<"\nLanguage: ";
	cin>> st.language;
}

void output(NODE *ptr)
{
	cout<<ptr->data.name<<"\t|\t"<<ptr->data.year<<"\t|\t"<<ptr->data.math<<"\t|\t"<<ptr->data.physic<<"\t|\t"<<ptr->data.language;
}

NODE *createList (NODE *start)
{
	NODE *node, *ptr;
	cout<<	"Put the number of students: ";
	int n;
	cin>>	n;
	STUDENT s;
	for (int i=0; i<n; i++)
	{
		input(s);
		node		=	new NODE;
		node->data	=	s;	
		if (start == NULL)
		{
			node->next	=	NULL;
			start		=	node;
		}
		else
		{
			ptr			=	start;
			while (ptr->next != NULL) 
				ptr		=	ptr->next;
			ptr->next	=	node;
			node->next	=	NULL;
		}
	}
	return start;
}

NODE *add(NODE *start)
{
	NODE *ptr, *node;
	STUDENT s;
	input(s);
	node		=	new NODE;
	node->data	=	s;
	node->next	=	NULL;
	ptr			=	start;
	while (ptr->next != NULL)
		ptr		=	ptr->next;
	ptr->next	=	node;
	return start;
}



NODE *display(NODE *start)
{
	NODE *ptr;
	ptr	=	start;

	cout<< 	"Name\t|\tYear\t|\tMath\t|\tPhysic\t|\tLanguage\n";
	
	while (ptr != NULL)
	{
		output(ptr);
		cout<<	endl;
		ptr	=	ptr->next;
	}
	return start;
}

NODE *delete_std(NODE *start)
{
	NODE *ptr, *preptr;
	ptr	=	start;
	cout<<	"\nEnter the student's name to delete: ";
	char name[50];
	fflush(stdin);
	gets(name);
	
	if (ptr == NULL)
		cout<<	"NOT FOUND";
	while (ptr != NULL)
	{
	
		if (stricmp(ptr->data.name, name) == 0)
		{
			start		=	start->next;
			delete ptr;
			return start;
		}
		else
		{
			while (stricmp(ptr->data.name, name) != 0)
			{
				preptr	=	ptr;
				ptr		=	ptr->next;
			}
			preptr->next	=	ptr->next;
			delete ptr;
			return start;
		}
	}	
	
}

NODE *count(NODE *start)
{
	NODE *ptr;
	ptr			=	start;
	int num		=	0;
	int y;
	cout<<	"Put the year of birth: ";
	cin>>	y;
	if (ptr == NULL)
		cout<<	"NOT FOUND";
	while (ptr != NULL)
	{
		if (y == ptr->data.year)
			num++;
		ptr		=	ptr->next;
	}
	cout<< num <<" student(s)";
	return start;	
}

NODE *search (NODE *start)
{
	NODE 	*ptr;
	int 	count = 0;
	char name[50];
	cout<<	"\nPut the name's student: ";
	fflush(stdin);
	gets(name);
	ptr		=	start;
	cout<< 	"Name\t|\tYear\t|\tMath\t|\tPhysic\t|\tLanguage\n";
	while (ptr != NULL)
	{
		if (stricmp(name, ptr->data.name) == 0)
		{
			count++;
			output(ptr);
		}
		ptr =	ptr->next;
	}	
		if (count == 0)
			cout<<	"NOT FOUND";
	return start;
}

NODE *findMaxAverage (NODE *start)
{
	NODE *ptr, *max;
	int	count;
	ptr	=	start;
	max	=	ptr;
	if (ptr == NULL)
		cout<<	"NOT FOUND";
	while (ptr != NULL)
	{
		if (ptr->data.average() > max->data.average())
		{
			max 	=	ptr;
			count	=	0;
		}
		if (ptr->data.average() == max->data.average())
		{
			max		=	ptr;
			count++;
		}
		ptr			=	ptr->next;
	}
	if (count = 0)
		output(max);
	else
	{
		NODE *node	=	start;
		while (node != NULL)
		{
			if (node->data.average() == max->data.average())
				cout<<	"\nStudent:\t"<<node->data.name<<"\nAverage score:\t"<<node->data.average();
			node 	=	node->next;
		}
	}
	return start;
}

NODE *math_under_5(NODE *start)
{
	int count	=	0;
	NODE *ptr	=	start;
	cout<< 	"Name\t|\tYear\t|\tMath\t|\tPhysic\t|\tLanguage\n";
	while (ptr != NULL)
	{
		if (ptr->data.math < 5)
		{
			count++;
			output(ptr);
			cout<<endl;
		}
		ptr		=	ptr->next;
	}
	if (count == 0)
		cout<<	"No student whose math is under 5";
	return start;
}

char option()
{
	cout<<	"\n\t=========================MENU=========================";
	cout<<	"\n1. Input students'information";
	cout<<	"\n2. Print out the student list";
	cout<<	"\n3. Add a new student";
	cout<<	"\n4. Count the number of students in a given year of birth";
	cout<<	"\n5. Check if a student exist in the list or not";
	cout<<	"\n6. Delete a student by name";
	cout<<	"\n7. Find the student having the biggest average of 3 subjects";
	cout<<	"\n8. Print out the list of students whose math mark is less than 5";
	cout<<	"\n0. Exit";
	cout<<	"\n Enter your choice: ";
	char 	choice;
	cin>>	choice;
	return choice;		
}

int main()
{
	char opt;
	do
	{
		opt = option();
		switch (opt)
		{
			case '1':
				start	=	createList(start);
				break;
			case '2':
				start	=	display(start);
				break;
			case '3':
				start	=	add(start);
				break;
			case '4':
				start	=	count(start);
				break;
			case '5':	
				start	=	search(start);
				break;
			case '6':
				start	=	delete_std(start);
				break;
			case '7':
				start	=	findMaxAverage(start);
				break;
			case '8':
				start	=	math_under_5(start);
				break;
			case '0': 
				cout<<	"Goodbye...";
				exit(1);
			default:
				cout<<	"Wrong number. Please, Enter again!";
		}
	}
	while (opt != 0);
}
