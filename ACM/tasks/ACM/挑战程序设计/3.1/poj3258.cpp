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
int len,n,m;
const int maxn=50010;
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	while(scanf("%d%d%d",&len,&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n+1);
		a[n+1]=len;
		int l=0,r=len;
		int ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int last=0;
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[last]<mid)
				{
					cnt++;
				}
				else last=i;
			}
			if(last==n&&len-a[n]<mid)cnt++;
			if(cnt>m)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
				ans=max(ans,mid);
			}
		}
		printf("%d\n",ans);
	}
		
		
		
	return 0;
}


