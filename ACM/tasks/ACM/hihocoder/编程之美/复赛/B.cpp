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
int n,m;

const int maxn=200010;
int a[maxn];
vector<int> dat[maxn*4];
void init(int l,int r,int cur)
{
	if(r==l)
	{
	    dat[cur].clear();
		dat[cur].PB(a[l]);
		return;
	}
	int mid=(l+r)/2;
	init(l,mid,cur<<1);
	init(mid+1,r,cur<<1|1);
	dat[cur].resize(r-l+1);
	merge(dat[cur<<1].begin(),dat[cur<<1].end(),dat[cur<<1|1].begin(),dat[cur<<1|1].end(),dat[cur].begin());
}
int query(int curl,int curr,int l,int r,int cur,int x)
{
	if(curr<l||curl>r)return INF;
	else if(curl<=l&&curr>=r)
	{
	    if(dat[cur].size()==0)return INF;
	    int px=lower_bound(dat[cur].begin(),dat[cur].end(),x)-dat[cur].begin();
	    int lx =INF;
	    int rx= INF;
	    if(px)lx=x-dat[cur][px-1];
	    if(px!=dat[cur].size())rx = dat[cur][px]-x;
	    return min(lx,rx);
	}
	else
	{
		int mid=(l+r)/2;
		int ret = INF;
		if(curl<=mid)ret=min(ret,query(curl,curr,l,mid,cur<<1,x));
		if(curr>mid)ret=min(ret,query(curl,curr,mid+1,r,cur<<1|1,x));
		return ret;
	}
}

int main()
{
	int cas=1;
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		init(0,n-1,1);
		int l,r,k;
		printf("Case #%d:\n",cas++);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&l,&r,&k);
			l--;r--;
			printf("%d\n",query(l,r,0,n-1,1,k));
		}
	}
	return 0;
}
