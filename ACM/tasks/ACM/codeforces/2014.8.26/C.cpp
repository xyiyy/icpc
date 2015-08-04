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
bool rev[maxn];
int sum[maxn];
int num[maxn];
void pushup(int cur)
{
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
}
void init(int l,int r,int cur)
{
	sum[cur]=0;
	rev[cur]=0;
	if(l>r)return;
	if(l==r)
	{
		num[l]=0;
		return ;
	}
	int mid=(l+r)/2;
	init(l,mid,cur<<1);
	init(mid+1,r,cur<<1|1);
}/*
void pushdown(int cur)
{
	if(rev[cur])
	{
		rev[cur<<1]=rev[cur<<1|1]=1;
		rev[cur]=0;
	}
	
}*/
void update(int curx,int cury,int l,int r,int cur)
{
	if(rev[cur])
	{
		pushdown(cur);
		if(curx<=(r-l)/2)
		{
			update(r-curx,)
	}
	else 
	{
		if(curx<(r-l)/2)
		{
			rev[cur]
			
			
int main()
{
	ios::sync_with_stdio(false);
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		int k,l,r;
		int sum=0;
		for(int i=0;i<q;i++)
		{
			scanf("%d",&k);
			if(k==1)
			{
				scanf("%d",&l);
				update(l);
			}
			else 
			{
				scanf("%d%d",&l,&r);
				printf("%d\n",query2(l,r));
			}
		}
		
	}
	return 0;
}


