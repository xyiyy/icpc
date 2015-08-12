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
const int maxn=100010;
ll a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		ll maxx=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			maxx=max(maxx,a[i]);
		}
		ll k;
		scanf("%lld",&k);
		if(k==1)
		{
			printf("%lld\n",maxx);
			continue;
		}
		ll ans=0;
		ll l=0,r=maxx;
		while(l<=r)
		{
			ll mid=(l+r)/2;
			ll num=0;
			ll temp;
			for(int i=0;i<n;i++)
			{
				temp=(a[i]-mid+k-2)/(k-1);
				if(temp>0)num+=temp;
			}
			if(num<=mid)
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


