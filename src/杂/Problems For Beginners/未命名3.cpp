#include<iostream>
using namespace std;

int main()
{
	int a;
	cin>>a;
	cout<<a<<'*'<<a<<'*'<<a<<'='<<a*a*a<<'=';
	for(int i=0;i<a;i++)
	{
		cout<<a*a-a+1+2*i;
		if(i<a-1)
		{
			cout<<'+';
		}
	}
	return 0;
}
	
