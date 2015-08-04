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
int num[maxn],maxx[maxn*4];
int same[maxn*4],key[maxn*4];
int gcd(int x, int y)
{
	int t;
    while(y>0)
	{
		t=x%y;
		x=y;
		y=t;
	}
    return x;
}

void build(int l,int r,int cur)
{
	same[cur]=0;
	key[cur]=cur;
	if(l==r)
	{
		num[l]=0;
		maxx[cur]=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	maxx[cur]=max(cur<<1,cur<<1|1);
}
void push_up(int r)
{
	maxx[r]=max(maxx[r<<1],maxx[r<<1|1]);
}


void update_same(int r)
{
	//push_up(r);
	if(key[r<<1]==key[r<<1|1]&&same[r<<1]&&same[r<<1|1])
	{
		same[r]=1;
		key[r]=key[r<<1];
		//maxx[r]=key[r<<1];
	}
	else
	{
		same[r]=0;
		//push_up(r);
	}
	push_up(r);
}
void make_same(int curl,int curr,int l,int r,int cur,int x)
{
	if(curl<=l&&curr>=r)
	{
		same[cur]=1;
		key[cur]=x;
		maxx[cur]=x;
		return;
	}
	int mid=(l+r)>>1;
	if(curl<=mid)make_same(curl,curr,l,mid,cur<<1,x);
	if(curr>mid)make_same(curl,curr,mid+1,r,cur<<1|1,x);
	update_same(cur);
	return;
}
/*void push_down(int curl,int curr,int l,int r ,int cur)
{
	if(curl<=l&&curr>=r)
	{
		dfs(l,r,cur);
		return;
	}
	int mid=(l+r)>>1;
	if(curl<=mid)push_down(curl,curr,l,mid,cur<<1);
	if(curr>mid)push_down(curl,curr,mid+1,r,cur<<1|1);
}
	*/
void push_down(int l,int r,int cur)
{
	if(l==r)
	{
		maxx[cur]=num[l]=key[cur];
		return;
	}
	else
	{
		maxx[cur<<1]=maxx[cur<<1|1]=key[cur];
		key[cur<<1]=key[cur<<1|1]=key[cur];
		same[cur<<1]=same[cur<<1|1]=1;
	}
}
void dfs(int l,int r,int cur)
{
	if(same[cur])
	{
		push_down(l,r,cur);
	}
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,cur<<1);
	dfs(mid+1,r,cur<<1|1);
}
void update(int curl,int curr,int l,int r,int cur,int x)
{
	if(same[r])push_down(l,r,cur);
	if(maxx[cur]<=x||x==0)
	{
		return;
	}
	if(l==r)
	{
		same[cur]=0;
		num[l]=gcd(num[l],x);
		maxx[cur]=num[l];
		return;
	}
	int mid=(l+r)>>1;
	if(curl<=mid)update(curl,curr,l,mid,cur<<1,x);
	if(curr>mid)update(curl,curr,mid+1,r,cur<<1|1,x);
	update_same(cur);
}
	
int main()
{
	//ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q,x,y,z,m;
		scanf("%d",&n);
		build(0,n-1,1);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			scanf("%d%d%d%d",&x,&y,&z,&m);
			y--;z--;
			if(x==1)
			{
				make_same(y,z,0,n-1,1,m);
			}
			else 
			{
				update(y,z,0,n-1,1,m);
			}
		//	cout<<"ok"<<endl;
		}
		dfs(0,n-1,1);
		for(int i=0;i<n;i++)
		{
			//if(i)printf(" ");
			printf("%d ",num[i]);
		}
		printf("\n");
	}
		
			
	return 0;
}


