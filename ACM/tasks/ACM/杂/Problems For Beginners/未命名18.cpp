#include<iostream>
using namespace std;

int main()
{
	int a[40];
	int n;
	cin>>n;
	a[0]=1;a[1]=1;
	int t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(t>40)return 0;
		if(t==1||t==2)
		{
			cout<<a[1]<<endl;
		}
		else
		{
			for(int j=2;j<t;j++)
			{
				 a[j]=a[j-1]+a[j-2];
			}
			cout<<a[t-1]<<endl;
		}
 }
 return 0;
} 
