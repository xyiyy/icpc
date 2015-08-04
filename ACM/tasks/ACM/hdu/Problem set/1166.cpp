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
int num[50010];
int sum[50010*4];
void push_up(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int cur)
{
	sum[cur]=0;
	if(l==r)
	{
		sum[cur]=num[l];
		return;
	//	push_up(cur>>1);
	}
	int mid=(l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	push_up(cur);
}
void Add(int goal,int l,int r,int cur,int inc)
{
	sum[cur]+=inc;
	if(l==r&&goal==l)
	{
		return;
	}
	int mid=(l+r)>>1;
	if(goal<=mid)Add(goal,l,mid,cur<<1,inc);
	else Add(goal,mid+1,r,cur<<1|1,inc);
	return;
}
void Sub(int goal,int l,int r,int cur,int inc)
{
	sum[cur]-=inc;
	if(l==r&&goal==l)
	{
		return;
	}
	int mid=(l+r)>>1;
	if(goal<=mid)Sub(goal,l,mid,cur<<1,inc);
	else Sub(goal,mid+1,r,cur<<1|1,inc);
	return;
}
int query(int curl,int curr,int l,int r,int cur)
{
	int ret=0;
	if(curl<=l&&curr>=r)
	{
		return sum[cur];
	}
	int mid=(l+r)>>1;
	if(curl<=mid)ret+=query(curl,curr,l,mid,cur<<1);
	if(curr>mid)ret+=query(curl,curr,mid+1,r,cur<<1|1);
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		printf("Case %d:\n",cas++);
		CLR(sum,0);
		CLR(num,0);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		build(0,n-1,1);
		char a[20];
		int x,y;
		while(scanf("%s",a)!=EOF)
		{
			if(a[0]=='E')break;
			scanf("%d%d",&x,&y);
			if(a[0]=='A')
			{
				Add(x-1,0,n-1,1,y);
			}
			else if(a[0]=='S')
			{
				Sub(x-1,0,n-1,1,y);
			}
			else
			{
				printf("%d\n",query(x-1,y-1,0,n-1,1));
			}
		}
	}
	return 0;
}


