#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int m;
	cin>>m;
	if(m==1)cout<<0;
	else
	{
		double n=1.0;
		for(double i=2.0;i<=m;i++)
		{
			n-=1.0/(i*i);
		}	
		cout<<fixed<<setprecision(6)<<n;
	}
	
	return 0;
}

