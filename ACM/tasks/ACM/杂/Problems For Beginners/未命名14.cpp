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
int main()
{
	int N;
	cin>>N;
	if(N==1)return 0;
	if(N==2) cout<<"1";
	else
	{
		if(cal(N))
		cout<<"1";
		else
		cout<<"0";
	}
	return 0;
}
