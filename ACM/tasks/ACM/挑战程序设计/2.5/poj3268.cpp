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
#define MAXN 1010
vector<PII> Map[MAXN];
vector<PII> Map1[MAXN];
//清空邻接表 
void init() { REP(i,MAXN) Map[i].clear(); }
void init1() { REP(i,MAXN) Map1[i].clear();}
//求以s为源点的最短路 结果保存在dis中 
int dis[MAXN];
int sum[MAXN];
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
void dijkstra1(int s)
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
		for(vector<PII>::iterator it = Map1[x].begin(); it != Map1[x].end(); it++)
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

int main()
{
	ios::sync_with_stdio(false);
	int n,m,s;
	while(cin>>n>>m>>s)
	{
		init();
		init1();
		int u,v,l;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>l;
			u--;v--;
			Map[u].PB(MP(v,l));
			Map1[v].PB(MP(u,l));
		}
		dijkstra(s-1);
		for(int i=0;i<n;i++)
		{
			sum[i]=dis[i];
		}
		//for(int i=0;i<n;i++)
	//	{
	//		cout<<dis[i]<<endl;
	//	}
		dijkstra1(s-1);
		int maxx=0;
		for(int i=0;i<n;i++)
		{
			sum[i]+=dis[i];
		//	cout<<dis[i]<<endl;
			maxx=max(sum[i],maxx);
		}
		cout<<maxx<<endl;
	}
		
	return 0;
}


