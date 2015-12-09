#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,min=50000000;
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			int sum=0;
			for(int j=0;j<n;j++)
			{
				sum+=abs(a[j]-a[i]);
			}
			if(sum<min)
			{
				min=sum;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}

