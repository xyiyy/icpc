#include<iostream>
#include<cmath>
using namespace std;

int cal(int i)
{
	for(int j=2;j<=sqrt(i);j++)
	{
		if(i%j==0)
		return 0;
	}
	return 1;
}

int verify(int n)
{
	int m=n;
	int t=0;
	while(m!=0)
	{
		t=t*10+m%10;
		m/=10;
	}
	if(n==t)
	return 1;
	return 0;

}
		

	
	
int main()
{
	int a,b;
	cin>>a>>b;
	int min=0;
	for(int i=a;min==0&&i<=b;i++)
	{
		if(verify(i)&&cal(i))
		{
			min=i;
			cout<<i;
		}
	}
	for(int i=min+1;i<=b;i++)
	{
		if(verify(i)&&cal(i))
		{
			cout<<'\n'<<i;
		}
	}
	return 0;
}
	

