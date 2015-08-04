#include<iostream>
#include<cstring>
using namespace std;
int MAX(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int MIN(int a,int b)
{
	if(a<b)return a;
	return b;
}
long long MAX(long long a,long long b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int a[1000000];
int main()
{
	int T,k=1;
	cin>>T;
	while(T--)
	{
		memset(a,0,1000000);
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long x=0,y=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]-a[i-1]>0)
			{
				x+=a[i]-a[i-1];
			}
			else
			{
				y-=a[i]-a[i-1];
			}
		}
		cout<<"Case "<<k<<": "<<MAX(x,y)<<" "<<(MAX(a[0],a[n-1])-MIN(a[0],a[n-1])+1)<<endl;
		k++;
	}
	return 0;
}
		
		
		
