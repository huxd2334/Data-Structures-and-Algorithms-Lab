#include <bits/stdc++.h>
using namespace std;

#define MAX 10
int top	= -1;
int st[MAX];
void push (char);
char pop();

int main()
{
	char exp[MAX], temp;
	int i, flag = 1;
	cout<<	"\n\tPARENTHESES CHECKER\n\nPut an expression: ";
	gets(exp);
	for (i=0; i<strlen(exp); i++)
	{
		if ( exp[i]=='(' or exp[i]=='{' or exp[i]=='[' )
			push(exp[i]);
		if ( exp[i]==')' or exp[i]=='}' or exp[i]==']' )
		{
			if (top == -1)
				flag = 0;
			else
			{
				temp = pop();
				if (exp[i]==')' and (temp=='{' or temp=='['))	flag=0;
				if (exp[i]=='}' and (temp=='(' or temp=='['))	flag=0;
				if (exp[i]==']' and (temp=='(' or temp=='{'))	flag=0;
			}
		}
	}
	if (top >= 0)	flag=0;
	if (flag == 1)	cout<<"\nValid";
	else			cout<<"\nInvalid";
}

void push (char c)
{
	if (top == (MAX-1))		cout<<"\nStack overflow";
	else
	{
		top			+=	1;
		st[top]	=	c;
	}
}

char pop()
{
	if (top == -1)			cout<<"\nStack underflow";
	else					return (st[top--]);
}



