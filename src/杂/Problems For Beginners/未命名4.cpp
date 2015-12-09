#include<iostream>
using namespace std;

void Sort(int &a,int &b,int &c,int &d)
{
	int temp;
	if(a>b)
	{
		temp=a;a=b;b=temp;
	}
	if(b>c)
	{
		temp=b;b=c;c=temp;
	}
	if(c>d)
	{
		temp=c;c=d;d=temp;
	}
	if(a>b)
	{
		temp=a;a=b;b=temp;
	}
	if(b>c)
	{
		temp=b;b=c;c=temp;
	}
	if(a>b)
	{
		temp=a;a=b;b=temp;
	}
}

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	Sort(a,b,c,d);
	cout<<a<<' '<<b<<' '<<c<<' '<<d;
	return 0;
}
	
