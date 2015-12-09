#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int num=0;
		while(n/3!=0)
		{
			int a=n%3;
			int b=n/3;
			n=a+b;
			num+=b;
		}
		if(n==2)num++;
		cout<<num<<endl;
	}
	return 0;
}
			
			
