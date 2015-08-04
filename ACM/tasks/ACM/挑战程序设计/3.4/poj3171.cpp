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
#define INF (ll)1000000000000
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
const int maxn=87000;
ll minn[maxn*4];
void build(int l,int r,int cur)
{
	minn[cur]=INF;
	if(l>=r)return;
	int mid=(l+r)/2;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
}
void update(int id,int l,int r,int cur,ll x)
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
ll query(int curl,int curr,int l,int r,int cur)
{
	if(curl<=l&&curr>=r)
		return minn[cur];
	int mid=(l+r)/2;
	ll ret1=INF,ret2=INF;
	if(curl<=mid)ret1=query(curl,curr,l,mid,cur<<1);
	if(curr>mid)ret2=query(curl,curr,mid+1,r,cur<<1|1);
	return min(ret1,ret2);
}
int x[maxn],y[maxn],id[maxn],c[maxn];
bool cmp(int a,int b)
{
	if(x[a]==x[b])return y[a]<y[b];
	return x[a]<x[b];
}
int main()
{
	//ios::sync_with_stdio(false);
	int n,m,e;
	while(scanf("%d%d%d",&n,&m,&e)!=EOF)
	{
		m++;e++;
		build(0,maxn-2,1);
		//update(m-1,0,n-1,0);
		//int x,y,c;
		ll z;
		update(m-1,0,maxn-2,1,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&c[i]);
			id[i]=i;
		}
		sort(id,id+n,cmp);
		for(int i=0;i<n;i++)
		{
			//scanf("%d%d%d",&x,&y,&c);
			x[id[i]]++;y[id[i]]++;
			if(y[id[i]]>x[id[i]])
			{
				z=query(x[id[i]]-1,y[id[i]]-1,0,maxn-2,1)+c[id[i]];
			//	cout<<z<<endl;
				update(y[id[i]],0,maxn-2,1,z);
			}
			else if(y[id[i]]==x[id[i]])
			{
				update(y[id[i]],0,maxn-2,1,query(y[id[i]]-1,y[id[i]]-1,0,maxn-2,1)+c[id[i]]);
			}
		}
		z=query(e,maxn-2,0,maxn-2,1);
		if(z>=INF)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",z);
		}
		
	}
		
	return 0;
}
