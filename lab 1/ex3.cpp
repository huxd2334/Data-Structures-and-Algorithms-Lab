#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b)
{
	if (b == 0) 
        return a;
    else 
        return findGCD(b, a % b);
    
}

int findLCM(int a, int b)
{
	return (a*b/findGCD(a,b));
}

int main()
{
	int n, m; 
	cout<<"Enter 2 integer number: ";
	cin>>n>>m;
	cout<<"GCD("<<n<<","<<m<<"): "<<findGCD(n, m)<<endl;
	cout<<"LCM("<<n<<","<<m<<"): "<<findLCM(n, m)<<endl;
	return 0;
}
