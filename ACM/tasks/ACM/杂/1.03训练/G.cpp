#include <cstdio>
#include<algorithm>
using namespace std;

int cmp(int a,int b)
{
return a>b;
}
int t,rank[101],l[101],rr[101],ll[101];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
 		int lap=0;
    	int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
  		{
  			scanf("%d%d",&l[i],&rank[i]);
			rr[i]=rank[i];
		}
		sort (rr,rr+n,cmp);
		for(int i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
		{
		if(rr[i]==rank[j])
			ll[i]=l[j];
		}
	}
	for(int i=1;i<n;i++)
		if(ll[i]<ll[i-1])
      		lap++;     
    if(ll[n-1]+lap*400>m )
		printf("NO\n");
  	else
	printf("YES\n"); 
	}
    return 0;
}
