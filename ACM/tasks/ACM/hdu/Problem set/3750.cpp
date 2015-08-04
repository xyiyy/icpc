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
vector<pair<int ,PII> > Map[MAXN];

void init() { REP(i,MAXN) Map[i].clear(); }

int dis[MAXN];
int cost[MAXN];
void dijkstra(int s)
{
	REP(i,MAXN){dis[i]=i==s?0:INF;}
	REP(i,MAXN){cost[i]=i==s?0:INF;}
	int vis[MAXN] = {0};
	priority_queue<pair<int,PII>, vector<pair<int ,PII> >, greater<pair<int,PII> > > q;
	q.push(MP(0,MP(0,s)));
	while(!q.empty())
	{
		pair<int ,PII> p = q.top(); q.pop();
		int x = p.second.second;
		if(vis[x])continue;
		vis[x] = 1;
		for(vector<pair<int,PII> >::iterator it = Map[x].begin(); it != Map[x].end(); it++)
		{
			int y = it->first;
			int d = it->second.first;
			int c = it->second.second;
			if(!vis[y] && dis[y] > dis[x] + d)
			{
				dis[y] = dis[x] + d;
				cost[y] = cost[x]+c;
				q.push(MP(dis[y],MP(c,y)));
			}
			else if(!vis[y] && dis[y] == dis[x] + d&&cost[y]>cost[x]+c)
			{
				cost[y] = cost[x]+c;
				q.push(MP(dis[y],MP(c,y)));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m&&(n||m))
	{
		init();
		int u,v,d,t;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>d>>t;
			Map[u].PB(MP(v,MP(d,t)));
			Map[v].PB(MP(u,MP(d,t)));
		}
		int s,g;
		cin>>s>>g;
		dijkstra(s);
		cout<<dis[g]<<" "<<cost[g]<<endl;
	}
			
	return 0;
}


