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
const int maxn=1000010;
int num[maxn*4];
int maxx[maxn*4];
void build(int l,int r,int cur)
{
	num[cur]=0;
	maxx[cur]=0;
	if(l>=r)return;
	int mid=(l+r)/2;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
}
void pushdown(int cur)
{
	if(num[cur])
	{
		num[cur<<1]+=num[cur];
		num[cur<<1|1]+=num[cur];
		maxx[cur<<1]+=num[cur];
		maxx[cur<<1|1]+=num[cur];
		num[cur]=0;
	}
}
void pushup(int cur)
{
	maxx[cur]=max(maxx[cur<<1],maxx[cur<<1|1]);
}
void update(int curl,int curr,int l,int r,int cur)
{
	if(curl>r||curr<l)return;
	if(curl<=l&&curr>=r)
	{
		num[cur]++;
		maxx[cur]++;
		return;
	}
	pushdown(cur);
	int mid=(l+r)/2;
	if(curl<=mid)update(curl,curr,l,mid,cur<<1);
	if(curr>mid)update(curl,curr,mid+1,r,cur<<1|1);
	pushup(cur);
}
int query(int curl,int curr,int l,int r,int cur)
{
	if(curl>r||curr<l)return 0;
	if(curl<=l&&curr>=r)
	{
		return maxx[cur];
	}
	pushdown(cur);
	int ret1=0,ret2=0;
	int mid=(l+r)/2;
	if(curl<=mid)ret1=max(ret1,query(curl,curr,l,mid,cur<<1));
	if(curr>mid)ret2=max(ret2,query(curl,curr,mid+1,r,cur<<1|1));
	return max(ret1,ret2);
}
int man[100010];
int main()
{
	ios::sync_with_stdio(false);
	int t,k,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&q);
		CLR(man,0);
		build(0,maxn-1,1);
		int a,b;
		int id=0;
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&a,&b);
			if(b>a&&query(a,b-1,0,maxn-1,1)<k)
			{
				update(a,b-1,0,maxn-1,1);
				man[id++]=i;
			}
		}
		for(int i=0;i<id;i++)
		{
			if(i)printf(" ");
			printf("%d",man[i]);
		}
		printf("\n");
	}
	return 0;
}


