#include <bits/stdc++.h>
using namespace std;

void input (int *arr, int &n);
void output (int *arr, int &n);
void linearSearch (int *arr, int &n);
void sel_sort(int *arr, int &n);
void binarySearch(int *arr, int &n);

void linearSearch(int *arr, int &n)
{
	int found=0, pos=-1, num;
	cout<< "\nEnter the number to be searched: ";
	cin>> num;
	for (int i=0; i<n; i++)
	{
		if (arr[i] == num)
		{
			found 	= 1;
			pos		= i;
			cout<<"\n"<<num<<" is found at position "<<i+1;
			break;
		}
	}
	if (found = 0)	cout<< "\nNot found";
}

void binarySearch(int *arr, int &n)
{
	int num, begin, end, mid;
	bool isFound = false;
	cout	<< "\nEnter the number to be searched: ";
	cin		>> num;
	begin 	= 0;
	end		= n-1;
	while (begin <= end)
	{
		mid = (begin+end)/2;
		if (arr[mid] == num)
		{
			cout	<<num<<" is found at position "<<mid+1;
			isFound	= true;
			break;
		}
		else if (arr[mid] > num)	end 	= mid-1;
		else						begin	= mid+1;
	}
	if (begin > end && isFound == false)	cout<< "Not found";
}

int smallest(int *arr, int k, int &n)
{
	int pos=k, small=arr[k];
	for (int i=k+1; i<n; i++)
	{
		if (arr[i] < small)
		{
			small 	= arr[i];
			pos		= i;
		}
	}
	return pos;
}

int sel_sort(int *arr, int &n)
{
	int pos, temp;
	for (int k=0; k<n; k++)
	{
		pos		= smallest(arr, k, n);
		temp	= arr[k];
		arr[k]	= arr[pos];
		arr[pos]= temp;
	}
}

void input (int *arr, int &n)
{
	srand(time(NULL)); 
    for(int *ptr=arr; ptr<arr+n; ptr++) 
    {
        *ptr = rand() % 1000;
    }
}

void output (int *arr, int &n)
{
	 for(int *ptr=arr; ptr<arr+n; ptr++) 
    {
        cout << *ptr << "  ";
    }
    cout << endl;
}





int option()
{
	cout<<	"\n\n\t=========================MENU=========================";
	cout<<	"\n1. Input";
	cout<<	"\n2. Output";
	cout<<	"\n3. Sort";
	cout<<	"\n4. Search by linear search";
	cout<<	"\n5. Search by binary search";
	cout<<	"\n0. Exit";
	cout<<	"\n Enter your choice: ";
	int	choice;
	cin>>	choice;
	return choice;		
}

int main()
{
	int opt;
	int arr[1000], n;
	do
	{
		opt = option();
		switch (opt)
		{
			case 1:
				cout<< "\nEnter the size of array:";
				cin>> n;
				input(arr, n);
				break;
			case 2:
				output(arr, n);
				break;
			case 3:
				sel_sort(arr, n);
				cout<< "\nThe array after sorting is: ";
				output(arr, n);
				break;
			case 4:
				linearSearch(arr, n);
				break;
			case 5:
				binarySearch(arr, n);
				break;
			case 0: 
				cout<< "\nGoodbye";
				exit(0);
			default:
				cout<< "\nWrong statement!";
		}
	}
	while (opt != 0);
}
