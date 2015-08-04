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
int n,w,h;
#define lson t<<1,l,m
#define rson t<<1|1,m+1,r
const int maxn=200000;
int a[maxn*4];
void build(int t,int l,int r)
{
	a[t]=w;
	if(l==r)return ;
	int m=(l+r)/2;
	build (lson);
	build (rson);
}
int query(int x,int t,int l,int r)
{
	if(l==r)
	{
		a[t]-=x;
		return l;
	}
	int m=(l+r)/2,ret;
	if(x<=a[t<<1])
		ret=query(x,lson);
	else 
		ret=query(x,rson);
	a[t]=max(a[t<<1],a[(t<<1)+1]);
	return ret;
}
	


int main()
{
	//ios::sync_with_stdio(false);
	int x;
	while(scanf("%d%d%d",&h,&w,&n)!=EOF)
	{
		h=min(h,n);
		build(1,1,h);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>a[1])printf("-1\n");
			else 
			{
				printf("%d\n",query(x,1,1,h));
			}
		}
	}
	return 0;
}


