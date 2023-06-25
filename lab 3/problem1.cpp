#include <bits/stdc++.h>
using namespace std;
int getPriority(char);
string infix_to_postfix(string);
float evaluate_postfix(string);

int main()
{
	string postfix, infix;
    cout<<"\nEnter an infix: ";
    cin>>infix;    
    postfix = infix_to_postfix(infix);
    cout<<"\nPostfix notation:\t\t\t"<<postfix;
    float value;
    value = evaluate_postfix(postfix);
    cout<<"\nValue of the postfix expression:\t"<<value;
    return 0;
}

int getPriority (char op){
    if(op == '+' || op =='-')			return 1;      
    else if(op == '*' || op =='/')		return 2;      
    else if(op == '^')					return 3;
    else return 0;
}

string infix_to_postfix(string infix)
{
    int i = 0;
    string postfix = "";
    stack <int> st;

    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))          
        {
            postfix += infix[i];
            i++;
        }
        else if(infix[i]=='(')
        {
            st.push(infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(st.top()!='('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
            i++;
        }
        else            
        {
            while (!st.empty() && getPriority(infix[i]) <= getPriority(st.top())){
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
            i++;
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

float evaluate_postfix(string postfix)
{
    stack<int> st;
    for (int i = 0; i < postfix.size(); ++i) {
         
        if (isdigit(postfix[i]))
            st.push(postfix[i] - '0');
 
        else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (postfix[i]) {
            case '+':
                st.push(op2 + op1);
                break;
            case '-':
                st.push(op2 - op1);
                break;
            case '*':
                st.push(op2 * op1);
                break;
            case '/':
                st.push(op2 / op1);
                break;
            }
        }
    }
    return st.top();
}


