#include<iostream>
using namespace std;
int main()
{
	long long n;
	int a[100];
	while(cin>>n&&n)
	{
		for(int i=0;i<100;i++)
		{
			a[i]=0;
		}
		int i=0;
		while(n!=0)
		{
			a[i]=n%10;
			n/=10;
			i++;
		}
		int sum=0;
		for(int i=0;i<100;i++)
		{
			if(a[i]%2==0&&a[i]!=0)
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
		
