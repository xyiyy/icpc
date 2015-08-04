#include <iostream>
using namespace std;

int a[30000],vis[30000];
int n=0;

int fun(int time)
{
	int i,j,l=0;
	i=time/20+2;
	while(i<=n)
	{
		while(i<=n&&vis[i]==1)
		{
			i++;
		}
		if((i-1)*4+10*l>time)
		return 0;
		j=(time-10*l+20*i+4)/24;
		i=(time-10*l+16*j+4)/20+1;
		l++;
		
	}
	return 1;
}

int main()
{
	while(cin>>n&&n)
	{
		for(int i=0;i<30000;i++)vis[i]=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			vis[i]=1;
		}
		int k=a[0];
		for(int i=0;i<n;i++)
		if(k<a[i])k=a[i];
		int min=(k-1)*4-1;
		int max=(k-1)*20;
		int mid;
		while(max-min>1)
		{
			mid=(max+min)/2;
			if(fun(mid))
			{
				max=mid;
			}
			else
			{
				min=mid;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}

