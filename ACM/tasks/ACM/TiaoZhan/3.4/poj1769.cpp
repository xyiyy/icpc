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
int minn[maxn*4];
void build(int l,int r,int cur)
{
	minn[cur]=INF;
	if(l>=r)return;
	int mid=(l+r)/2;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
}
void update(int id,int l,int r,int cur,int x)
{
	minn[cur]=min(minn[cur],x);
	int mid=(l+r)/2;
	if(l==r&&id==l)
		return;
	if(id<=mid)
		update(id,l,mid,cur<<1,x);
	else
		update(id,mid+1,r,cur<<1|1,x);
}
int query(int curl,int curr,int l,int r,int cur)
{
	if(curl<=l&&curr>=r)
		return minn[cur];
	int mid=(l+r)/2;
	int ret1=INF,ret2=INF;
	if(curl<=mid)ret1=query(curl,curr,l,mid,cur<<1);
	if(curr>mid)ret2=query(curl,curr,mid+1,r,cur<<1|1);
	return min(ret1,ret2);
}
int main()
{
	//ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		build(0,n-1,1);
		int x,y,z;
		update(0,0,n-1,1,0);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			z=query(x,y-1,0,n-1,1)+1;
			update(y,0,n-1,1,z);
		}
		printf("%d\n",query(n-1,n-1,0,n-1,1));
	}
		
	return 0;
}


