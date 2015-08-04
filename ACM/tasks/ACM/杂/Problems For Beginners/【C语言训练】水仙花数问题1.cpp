#include<iostream>
using namespace std;

int main()
{
	 int n,a,b,c;
	 cin>>n;
	 a=n/100;
	 b=(n-100*a)/10;
	 c=(n-100*a-10*b);
	 if(n==a*a*a+b*b*b+c*c*c)
	 cout<<"1";
	 else
	 cout<<"0";
	 return 0;
}
