//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
struct edge{
	int to,cap,rev;
	edge(int _to,int _cap,int _rev)
	{
		to=_to;
		cap=_cap;
		rev=_rev;
	}
};
const int MAX_V=10020;
vector<edge>G[MAX_V];
int iter[MAX_V];
int level[MAX_V];
int tot=0;
void add_edge(int from,int to,int cap)
{
	G[from].PB(edge(to,cap,G[to].size()));
	G[to].PB(edge(from,0,G[from].size()-1));
}
void bfs(int s,int t)
{
	CLR(level,-1);
	queue<int>q;
	level[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			edge &e=G[u][i];
			if(e.cap>0&&level[e.to]<0)
			{
				level[e.to]=level[u]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f)
{
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to])
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int Dinic(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s,t);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0)
		{
			flow+=f;
		}
	}
}

int a[MAX_V];
int dp[MAX_V];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int ans=0;
		CLR(dp,0);
		for(int i=0;i<n;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(a[j]<a[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		}
		int s=2*n,t=2*n+1;
		for(int i=0;i<t+1;i++)G[i].clear();
		for(int i=0;i<n;i++)add_edge(i,i+n,1);
		for(int i=0;i<n;i++){
			if(dp[i]==1)add_edge(s,i,1);
			if(dp[i]==ans)add_edge(i+n,t,1);
			for(int j=i+1;j<n;j++){
				if(dp[j]==dp[i]+1&&a[i]<a[j]){
					add_edge(i+n,j,1);
				}
			}
		}
		printf("%d\n",ans);
		printf("%d\n",Dinic(s,t));
			
	}
	return 0;
}



