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
int num[200020];
int maxx[200020*4];
void push_up(int rt)
{
	maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
}
void build(int l,int r,int cur)
{
	//maxx[cur<<1]=maxx[cur<<1|1]=0;
	if(l==r)
	{
		maxx[cur]=num[r];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	push_up(cur);
}
void update(int goal,int l,int r,int cur,int inc)
{
	if(l==r&&goal==l)
	{
		num[l]=inc;
		maxx[cur]=inc;
		return ;
	}
	int mid=(l+r)>>1;
	if(goal<=mid)update(goal,l,mid,cur<<1,inc);
	else update(goal,mid+1,r,cur<<1|1,inc);
	push_up(cur);
}
int query(int curl,int curr,int l,int r,int cur)
{
	if(curl<=l&&curr>=r)
	{
		return maxx[cur];
	}
	int mid=(l+r)>>1;
	int m=-1;
	if(curl<=mid)m=max(query(curl,curr,l,mid,cur<<1),m);
	if(curr>mid)m=max(query(curl,curr,mid+1,r,cur<<1|1),m);
	return m;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		CLR(maxx,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		build(0,n-1,1);
		char a[10];
		int x,y;
		for(int i=0;i<m;i++)
		{
			scanf("%s%d%d",a,&x,&y);
			if(a[0]=='Q')
			printf("%d\n",query(x-1,y-1,0,n-1,1));
			else 
			update(x-1,0,n-1,1,y);
		}
	}
	return 0;
}


