#include<iostream>
using namespace std;

int main()
{
	int n,m;
	while (cin>>n>>m) 
	{
		if(n<=m)
		{
			cout<<(2+2*n)/2<<endl;
		}
		else
		{
			int i;
			int x=1+m;
			for(i=1;m*i<n;i++)
			{
				if(i==1)
				{
					cout<<x<<" ";
				}
				else
				{
					x+=2*m;
					cout<<x<<" ";
				}
			}
			i--;
			x=x+m+n-i*m;
			cout<<x<<endl;
		}
	}
	return 0;
}
		
		
