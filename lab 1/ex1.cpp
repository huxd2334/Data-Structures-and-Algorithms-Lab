#include <bits/stdc++.h>
using namespace std;

void input(int* arr, int n);
void display(int* arr, int n);
void remove_odd(int* arr, int& n);

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int* arr = new int[n];
    input(arr, n);
    cout << "The original array is: ";
    display(arr, n);
    remove_odd(arr, n);
    cout << "The array after deleting the odd number is: ";
    display(arr, n);
    delete[] arr;
    return 0;
}

void input(int* arr, int n)
{
    srand(time(NULL)); 
    for(int* ptr=arr; ptr<arr+n; ptr++) 
    {
        *ptr = rand() % 100;
    }
}

void display(int* arr, int n)
{
    for(int* ptr=arr; ptr<arr+n; ptr++) 
    {
        cout << *ptr << " ";
    }
    cout << endl;
}

void remove_odd(int* arr, int& n)
{
    int num_even = 0;
    for(int* ptr=arr; ptr<arr+n; ptr++) 
    {
        if((*ptr)%2 == 0)
        {
            arr[num_even++] = *ptr;
        }
    }
    n = num_even;
}
