#include <iostream>
using namespace std;

int f( int p)
{
	p = p + 5;
	return (p+5);
}

int main()
{
	cout<< f(10);
	return 0;
}
