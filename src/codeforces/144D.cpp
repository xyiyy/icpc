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
#define MAXN 100100
vector<PII> Map[MAXN];

//清空邻接表 
void init() { REP(i,MAXN) Map[i].clear(); }

//求以s为源点的最短路 结果保存在dis中 
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

struct node
{
	int u,v,d;
}edge[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,s;
	while(cin>>n>>m>>s)
	{
		int u,v,d;
		init();
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>d;
			u--;
			v--;
			Map[u].PB(MP(v,d));
			Map[v].PB(MP(u,d));
			edge[i].u=u;
			edge[i].v=v;
			edge[i].d=d;
		}
		int l;
		cin>>l;
		s--;
		dijkstra(s);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(dis[i]==l)ans++;
		}
		for(int i=0;i<m;i++)
		{
			u=edge[i].u;
			v=edge[i].v;
			d=edge[i].d;
			if(dis[u]>dis[v])swap(u,v);
			if(dis[v]-dis[u]==d)
			{
				if(l>dis[u]&&l<dis[v])ans++;
			}
			else
			{
				int x=l-dis[u];
				if(x<=0)continue;
				if(x>d)continue;
				if(dis[v]>l&&x<d)
				{
					ans++;
					continue;
				}
				if(dis[v]==l&&x<d)
				{
					ans++;
					continue;
				}
				int y=l-dis[v];
				if(x+y==d)
				{
					ans++;
					continue;
				}
				if(x<d-y)ans++;
				if(y<d-x)ans++;
			}
		}
		cout<<ans<<endl;
	}
		
			
	return 0;
}



