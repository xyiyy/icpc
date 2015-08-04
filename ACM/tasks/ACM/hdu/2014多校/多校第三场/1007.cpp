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
ll fib[80];
ll num[500010],sum[500010];
int vis[500010];
set<long long> s;
set<long long>::IT it,it1;
void push_up(int cur){
	vis[cur]=max(vis[cur<<1],vis[cur<<1|1]);
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
}
void build(int l,int r ,int cur)
{
	sum[cur]=0;
	vis[cur]=1;
	if(l==r){
		num[l]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
}
void add(int i,int l,int r,int cur,ll inc)
{
	sum[cur]+=inc;
	vis[cur]=1;
	if(l==i&&r==i){
		num[l]+=inc;
		return;
	}
	int mid=(l+r)>>1;
	if(i>mid)
	{
		add(i,mid+1,r,cur<<1|1,inc);
	}
	else if(i<=mid)add(i,l,mid,cur<<1,inc);
}
long long query(int curl,int curr,int l,int r,int cur)
{
	//printf("%d ",cur);
	//printf("%d  %d\n",l,r);
	//
	//cout<<l<<"  "<<r<<endl;
	if(curl<=l&&curr>=r){
		return sum[cur];
	}
	int mid=(l+r)>>1;
	ll result=0;
	if(curl<=mid)
	{
		result+= query(curl,curr,l,mid,cur<<1);
	}
	if(curr>mid)
	{
		result+=query(curl,curr,mid+1,r,cur<<1|1);
	}
	return result;
}
void update(int curl,int curr,int l,int r,int cur)
{
	//cout<<l<<" "<<r<<endl;
	if(!vis[cur])
	{
		return;
	}
	//return ;
	if(l==r){
		vis[cur]=0;
		if(num[l]<1)
		{
			num[l]=sum[cur]=1;
			return;
		}
		it1=s.upper_bound(num[l]);
		it=it1;
		it1--;
	//	cout<<*it1<<"  "<<*it<<endl;
		if(abs(*(it1)-num[l])<=abs(*it-num[l]))
		{
			num[l]=*(it1);
		}
		else num[l]=*it;
		sum[cur]=num[l];
		return ;
	}
	int mid=(l+r)>>1;
	if(curl<=mid&&vis[cur])
	{
		update(curl,curr,l,mid,cur<<1);
	}
	if(curr>mid&&vis[cur])
		update(curl,curr,mid+1,r,cur<<1|1);
	push_up(cur);
}
		
int main()
{
	//ios::sync_with_stdio(false);
	fib[0]=fib[1]=1;
	s.insert(1);
	for(int i=2;i<80;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		s.insert(fib[i]);
	}
	//for(int i=60;i<75;i++)
	//cout<<fib[i]<<endl;
	int n,m,x,y;
	ll z;
	//while(cin>>n>>m)
	while(scanf("%d%d",&n,&m)!=EOF)
	{
	//	CLR(num,0);
	//	CLR(sum,0);
		build(0,n-1,1);
		for(int i=0;i<m;i++)
		{
			//cin>>x>>y>>z;
			scanf("%d%d%I64d",&x,&y,&z);
			if(x==1)
			{
				add(y-1,0,n-1,1,z);
			}
			else if(x==2)
			{
			//	for(int j=0;j<5;j++)cout<<num[j]<<" ";
			//	cout<<endl;
				printf("%I64d\n",query(y-1,z-1,0,n-1,1));
				//cout<<query(y-1,z-1,0,n-1,1)<<endl;
			}
			else if(x==3)
			{
				update(y-1,z-1,0,n-1,1);	
			}
		//	printf("%d\n",i);
		}
	}

	return 0;
}


