#include<iostream>
using namespace std;

int main()
{
	int a[1000];
	cin>>a[0];
	for(int i=1;a[i-1]!=-1;i++)
	{
		cin>>a[i];
	}
	int max=a[0];
	for(int i=0;a[i]!=-1;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	cout<<max;
	return 0;
}
