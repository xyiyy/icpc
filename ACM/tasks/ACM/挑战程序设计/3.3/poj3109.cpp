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
#define fi first
#define se second
#define test printf("ok\n")
int n,m;
const int maxn=100010;
struct node
{
	int y,x;
	bool f;
	/*node(int _y,int _x,bool _f)
	{
		y=_y;
		x=_x;
		f=_f;
	}*/
	bool operator<(const node &b)const
	{
		if(x==b.x)return f>b.f;
		return x<b.x;
	}
}t[maxn<<1];
PII p[maxn];
int d[maxn];
int top[maxn];
int bot[maxn];
int bit[maxn];
int sum(int i)
{	
	int s=0;
	while(i)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=m)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	while(scanf("%d",&n)!=EOF)
	{
		CLR(bit,0);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i].fi,&p[i].se);
			d[i]=p[i].se;
		}
		sort(p+1,p+n+1);
		sort(d+1,d+n+1);
	//	for(int i=1;i<=n;i++)
	//	{
	//		printf("%d\n",p[i].fi);
	//	}
		m=unique(d+1,d+n+1)-d-1;
	//	printf("%d\n",m);
		for(int i=1;i<=n;i++)
		{
			p[i].se=lower_bound(d+1,d+m+1,p[i].se)-d;
		}
	//	for(int i=1;i<=n;i++)
	//	{
	//		printf("%d\n",p[i].se);
	//	}
		for(int i=1;i<=m;i++)top[i]=INF;
		for(int i=1;i<=n;i++)
		{
			if(top[p[i].se]==INF)top[p[i].se]=p[i].fi;
			bot[p[i].se]=p[i].fi;
		}
		for(int i=1;i<=m;i++)
		{
			t[2*i-1].y=t[2*i].y=i;
			t[2*i-1].x=top[i];
			t[2*i].x=bot[i];
			t[2*i-1].f=1;
			t[2*i].f=0;
		}
		sort(t+1,t+m+m+1);
	/*	for(int i=1;i<=m+m;i++)
		{
			printf("%d %d %d\n",t[i].y,t[i].x,t[i].f);
		}*/
		ll ans=0;
		int j=1;
		int i=1;
	//	test;
		while(i<=n)
		{
			int x=p[i].fi;
			int l=INF,r=-INF;
			while(i<=n&&p[i].fi==x)
			{
				l=min(l,p[i].se);
				r=max(r,p[i].se);
				i++;
			}
			//test;
			while(j<=m+m&&t[j].x<x)
			{
				j++;
			//	test;
			}
			while(j<=m+m&&t[j].x==x&&t[j].f)
			{
				add(t[j].y,1);
				j++;
			}
			ans+=sum(r)-sum(l-1);
			while(j<=m+m&&t[j].x==x&&!t[j].f)
			{
				add(t[j].y,-1);
		//		test;
				j++;
			}
		//	printf("%d  %d\n",i,ans);
		}
		printf("%lld\n",ans);
	}		
	return 0;
}


