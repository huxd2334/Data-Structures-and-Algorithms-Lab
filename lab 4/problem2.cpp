#include <bits/stdc++.h>
using namespace std;

typedef struct student
{
	char	name[30];
	char	id[12];
	char 	clas[10];
	float	mMath;
	float	mPhysic;
	float 	avg()
	{
		return (mMath + mPhysic)/2;
	}
}STUDENT;

STUDENT A[50];
int n;

void input(STUDENT A[50], int &n)
{
	for (int i=0; i<n; i++)
	{
		cout<< "\nStudent "<<i+1;
		fflush(stdin);
		cout<<	"\nID: ";
		gets(A[i].id);
		cout<<	"Name: ";
		gets(A[i].name);
		cout<<	"Class: ";
		gets(A[i].clas);
		cout<<	"Math: ";
		cin>> 	A[i].mMath;
		cout<<	"Physic: ";
		cin>> 	A[i].mPhysic;
	}
	
}

void output(STUDENT A[50])
{
	cout<< "\nStudent List:";
	for (int i=0; i<n; i++)
	{
		cout<<"\nID: "<<A[i].id<<"|\t\t"<<"Name: "<<A[i].name<<"|\t"<<"Class: "<<A[i].clas<<"|\t"<<"Math: "<<A[i].mMath<<"|\t"<<"Physic: "<<A[i].mPhysic;
	}
}



void find (STUDENT A[50], int &n)
{
	char id[12];
	cout<<"\nEnter the student's ID:";
	fflush(stdin);
	gets(id);
	bool isFound = false;
	
	for (int i=0; i<n; i++)
	{
		if ( stricmp(A[i].id, id) == 0)
		{
			isFound	=	true;
			cout<<"\nID: "<<A[i].id<<"|\t\t"<<"Name: "<<A[i].name<<"|\t"<<"Class: "<<A[i].clas<<"|\t"<<"Math: "<<A[i].mMath<<"|\t"<<"Physic: "<<A[i].mPhysic;
		}
	}
	if (isFound == false)
		cout<< "Not found";
}

void sort (STUDENT A[50], int &n)
{
	STUDENT temp;
	for (int i=n; i!=0;  --i)
	{
		for (int j=n; j>(n-i); j-- )
		{
			if (A[j].avg() > A[j-1].avg())
			{
				temp 	= A[j];
				A[j] 	= A[j-1];
				A[j-1] 	= temp;
			}
		}
		
	}
	cout<<	"\nThe student list after sorting is: ";
	for (int i=0; i<n; i++)
	{
		cout<<"\nID: "<<A[i].id<<"|\t\t"<<"Name: "<<A[i].name<<"|\t"<<"Class: "<<A[i].clas<<"|\t"<<"Average: "<<A[i].avg();
	}
}



char option()
{
	cout<<	"\n\n\t=========================MENU=========================";
	cout<<	"\n1. Input students'information";
	cout<<	"\n2. Print out the student list";
	cout<<	"\n3. Find the student by ID";
	cout<<	"\n4. Sort the list is desc order based on average";
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
				cout<< "\nEnter the number of student: ";
				cin>> n;
				input(A, n);
				break;
			case '2':
				output(A);
				break;
			case '3':
				find(A, n);
				break;
			case '4':
				sort(A, n);
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
