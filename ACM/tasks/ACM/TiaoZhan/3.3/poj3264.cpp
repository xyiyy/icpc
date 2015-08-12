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
const int maxn=50010;
int a[maxn];
int maxx[maxn*4];
int minn[maxn*4];
void build(int l,int r,int cur)
{
	if(l==r)
	{
		maxx[cur]=minn[cur]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	maxx[cur]=max(maxx[cur<<1],maxx[cur<<1|1]);
	minn[cur]=min(minn[cur<<1],minn[cur<<1|1]);
}
int ans=0;
int x,y;
void query(int curl,int curr,int l,int r,int cur)
{
	if(curl>r||curr<l)return;
	if(curl<=l&&curr>=r)
	{
		x=max(maxx[cur],x);
		y=min(minn[cur],y);
		return ;
	}
	int mid=(l+r)>>1;
	if(curl<=mid)query(curl,curr,l,mid,cur<<1);
	if(curr>mid)query(curl,curr,mid+1,r,cur<<1|1);
}
	
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		CLR(maxx,0);
		CLR(minn,INF);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		build(0,n-1,1);
		int l,r;
		while(m--)
		{
			scanf("%d%d",&l,&r);
			l--;r--;
			ans=0;
			x=0;y=INF;
			query(l,r,0,n-1,1);
			printf("%d\n",x-y);
		}
	}		
	return 0;
}


