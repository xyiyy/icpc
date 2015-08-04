#include<iostream>
using namespace std;

int main()
{
	int n;
	double i,s=0;
	while(cin>>n)
	{
		s=0;
		for(i=1.0;s<=n;i++)
		{
			s+=1/i;
		}
		i--;
		cout<<i<<endl;
	}
	return 0;
}
