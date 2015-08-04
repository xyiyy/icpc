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
#define MAXN 1600
vector<PII> Map[MAXN];


void init() { REP(i,MAXN) Map[i].clear(); }

int dis[MAXN];
void dijkstra(int s)
{
	REP(i,MAXN){dis[i]=i==s?0:INF;}
	int vis[MAXN] = {0};
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(MP(0,s));
	while(!q.empty())
	{
		PII p = q.top(); q.pop();
		int x = p.second;
		if(vis[x])continue;
		vis[x] = 1;
		for(vector<PII>::iterator it = Map[x].begin(); it != Map[x].end(); it++)
		{
			int y = it->first;
			int d = it->second;
			if(!vis[y] && dis[y] > dis[x] + d)
			{
				dis[y] = dis[x] + d;
				q.push(MP(dis[y],y));
			}
		}
	}
}
struct edge{
	int to,cap,rev;
	edge(int _to,int _cap,int _rev)
	{
		to=_to;
		cap=_cap;
		rev=_rev;
	}
};
const int MAX_V=2020;
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

int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		init();
		scanf("%d",&n);
		int u,v,d;
		while(scanf("%d%d%d",&u,&v,&d)&&(u||v||d)){
			u--;
			v--;
			Map[u].PB(MP(v,d));
			Map[v].PB(MP(u,d));
		}
		if(n==1){
			printf("0\n");
			continue;
		}
		for(int i=0;i<n;i++)G[i].clear();
		dijkstra(0);
		for(int i=0;i<n;i++){
			for(vector<PII>::iterator it = Map[i].begin(); it != Map[i].end(); it++)
			{
				int y = it->first;
				int d = it->second;
				if(dis[i]+d==dis[y]){
					add_edge(i,y,1);
				}
			}
		}
		printf("%d\n",Dinic(0,n-1));
	}
		
			
	return 0;
}



