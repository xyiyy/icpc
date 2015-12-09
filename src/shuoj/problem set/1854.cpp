#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[1000010];
int num[10010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		/*CLR(num,0);
		int minn=3010;
		int maxx=10;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			num[a[i]]++;
			minn=min(minn,a[i]);
			maxx=max(maxx,a[i]);
		}
		int tmp=minn,tmp1=maxx;
		int ans=0;
		int sum=0;
		for(int i=1000;i<=2000;i++)
		{
			if(sum+num[i]>=(n+1)/2){tmp=i;break;}
			sum+=num[i];
		}
		sum=0;
		for(int i=2000;i>=1000;i--)
		{
			if(sum+num[i]>=(n+1)/2){tmp1=i;break;}
			sum+=num[i];
		}
		sum=0;
		int k;
		scanf("%d",&k);
		k=2*k;*/
		int k;
		int tmp,tmp1;
		int ans=0;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&k);
		sort(a,a+n);
		if(n&1)
		{
			tmp=tmp1=a[n/2];
		}else
		{
			tmp=a[n/2];
			tmp1=a[n/2-1];
		}
		for(int i=0;i<n;i++)
		{
			if(abs(a[i]-tmp)<=k||abs(a[i]-tmp1)<=k)sum++;
			if(a[i]==tmp)ans=i+1;
		}
		if(sum==1)
		{
			printf("YES\n");
			printf("%d\n",ans);
		}
		else 
		{
			printf("NO\n");
			printf("%d\n",sum);
		}
	}
	return 0;
}



