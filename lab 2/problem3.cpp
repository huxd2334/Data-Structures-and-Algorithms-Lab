#include<bits/stdc++.h>
using namespace std;

struct STUDENT
{
	char name[50];
	int year;
	float math;
	float physic;
	float language;
	float average()
	{
		return (math+physic+language)/3;
	}
};

typedef struct node
{
	STUDENT data;
	struct node *next;
}NODE;

struct LIST
{
	NODE *head;
	NODE *tail;
};

NODE *createNode(STUDENT);
void createList(LIST &);
void input(STUDENT &);
void output(STUDENT);
void init(LIST &);
void add(LIST &, NODE *);
void print(LIST);
char option();
void deleteStu(LIST);
void search(LIST);
void search_by_year(LIST);
void student_with_math_under_5(LIST);
void findMaxAve(LIST);

NODE *createNode(STUDENT s)
{
	NODE *node;
	node		=	new NODE;
	if (node == NULL)
		exit(1);
	node->data	=	s;
	node->next	=	NULL;
	return node;
}

void createList(LIST &list)
{
	list.head = list.tail = NULL;
}

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

void add(LIST &list, NODE *node)
{
	if (list.head == NULL)
		list.head = list.tail = node;
	else
	{
		list.tail->next	=	node;
		list.tail		=	node;
	}
}


void init(LIST &list)
{
	STUDENT student;
	cout<<	"\nEnter the number of student: ";
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		input(student);
		NODE *node = createNode(student);
		add(list, node);
	}
}

void output(STUDENT st)
{
	cout<<	st.name<<"\t"<< st.year<<"\t"<<st.math<<"\t"<<st.physic<<"\t"<<st.language<<endl;
}

void print (LIST list)
{
	NODE *node;
	node		=	list.head;
	while(node != NULL)
		{
			output(node->data);
			node	=	node->next;
		}	
}

void search_by_year(LIST list)
{
	NODE *node;
	int count = 0;
	int year;
	cout<<	"\nEnter the year of birth: ";
	cin>>	year;
	node	=	list.head;
	while (node != NULL)
	{
		if (year == node->data.year)
		{
			count++;
			output(node->data);
		}
			
		node 	=	node->next;
	}
	cout<<	count<<" student(s)";
}

void findMaxAve(LIST list)
{
	NODE *node, *max;
	int count;
	node		=	list.head;
	max			=	node;
	while(node != NULL)
	{
		if (node->data.average() > max->data.average())
		{
			max		=	node;
			count	=	0;
		}
		if (node->data.average() == max->data.average())
		{
			max		=	node;
			count++;
		}
		node		=	node->next;
	}
		cout<<"\nStudent(s) with the highest average score\n";
		if(count==0)
			output(max->data);
		else
		{
			NODE *node1	=	list.head;
			while(node1 != NULL)
			{
				if(node1->data.average() == max->data.average())
					cout<<	"Student:\t"<<node1->data.name<<"\nAverage Score:\t"<<node1->data.average();
				node1	=	node1->next;
			}
		}

}

void search(LIST list)
{
	NODE *node;
	int count = 0;
	char name[50];
	cout<<	"\nPut the student's name to find: ";
	fflush(stdin);
	gets(name);
	node	=	list.head;
	while (node != NULL)
	{
		if (stricmp(name, node->data.name) == 0)
		{
			output(node->data);
			count++;
		}	
			
		node	=	node->next;
	}
	
		if (count==0)
			cout<<	"Not found";
	
}

void student_with_math_under_5(LIST list)
{
	NODE *node;
	int count;
	node		=	list.head;
	while (node != NULL)
	{
		if (node->data.math < 5)
		{
			output(node->data);
			count++;
		}	
		node	=	node->next;
	}

	if (count == 0)
		cout<<	"No student with Math score under 5! or List==NULL";
	
	
}
void deleteStu (LIST list)
{
	NODE *preptr, *ptr;
	ptr		=	list.head;
	preptr 	= NULL;
	cout<<	"\nEnter the student's name to delete: ";
	char name[50];
	fflush(stdin);
	gets(name);
	
		if (stricmp(ptr->data.name, name) == 0)
		{
			ptr			=	list.head;
			list.head	=	list.head->next;
			delete ptr;
			if (list.head == NULL) list.tail == NULL;
			cout<<"Delete Successfully";
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
			cout<<"Delete Successfully";
		}
	


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
	LIST list;
	NODE *node1, *node2, *node3;
	STUDENT student;
	char choice;
	createList(list);
	do
	{
		choice = option();
		switch (choice)
		{
			case '1':
				init(list);
				break;
			case '2':
				cout<<	"\nName\tYear\tMath\tPhysic\tLanguage\n";
				print(list);
				break;
			case '4':
				search_by_year(list);
				break;
			case '5':
				search(list);
				cout<<	"\nName\tYear\tMath\tPhysic\tLanguage\n";
				break;
			case '6':
				deleteStu(list);
				break;
			case '7':
				findMaxAve(list);
				break;
			case '8':
				student_with_math_under_5(list);
				cout<<	"\nName\tYear\tMath\tPhysic\tLanguage\n";
				break;
			case '3':
				{
					STUDENT newst;
					cout<<	"\nPut this student's information";
					input(newst);
					NODE *node	=	createNode(newst);
					add(list, node);
					break;
				}
			case '0': 
				cout<<	"Goodbye...";
				exit(1);
			default:
				cout<<	"\nWrong number. Please, Enter again!";
		}
	}
	while (choice != 0);
}


