#include <stdio.h>
int main()
{
	int T,n,a,sum,maxx,s,t,temp,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		s=1,t=temp=1;
		scanf("%d",&n);
		maxx=-1010;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			sum+=a;
			if(sum>maxx)
			{
				maxx=sum;
				s=temp;
				t=i;
			}
			if(sum<0)
			{
				sum=0;
				temp=i+1;
			}
		}
		if(cas!=1)printf("\n");
		printf("Case %d:\n",cas++);
		printf("%d %d %d\n",maxx,s,t);
	}
	return 0;
}


