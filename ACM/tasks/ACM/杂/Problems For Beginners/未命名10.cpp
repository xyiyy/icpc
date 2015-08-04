#include<iostream>
using namespace std;
 
int main()
{
	int a,a1,n,b=10,sum=0;
	cin>>a>>n;
	if(a>9)return 0;
	for(int i=0;i<n;i++)
	{
		a1=a;
		for(int j=0;j<i;j++)
		{
			a1*=b;
			a1+=a; 
		}
		sum+=a1;
	}
	cout<<sum;
	return 0;
}
