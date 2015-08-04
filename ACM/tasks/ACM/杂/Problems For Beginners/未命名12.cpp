#include<iostream>
#include<cmath>
using namespace std;

int cal(int i)
{
	for(int j=2;j<=int(sqrt(i));j++)
	{
		if(i%j==0)
		return 0;
	}
	return 1;
}

int main()
{
	int N;
	cin>>N;
	if(N==1)return 0;
	if(N==2)
	{
		cout<<2;
	}
		
	cout<<2<<' ';	
	for (int i=3;i<=N;i++)
	{
		if(cal(i))
		{
			cout<<i<<' ';
		}
	}
	return 0;
}
	
