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
int a[1010];
int b[1010];
int main()
{
	ios::sync_with_stdio(false);
	int t,s,d;
	while(cin>>t>>s>>d)
	{
		init();
		int u,v,c;
		int minn=INF;
		for(int i=0;i<t;i++)
		{
			cin>>u>>v>>c;
			Map[u].PB(MP(v,c));
			Map[v].PB(MP(u,c));
		}
		for(int i=0;i<s;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<d;i++)
		{
			cin>>b[i];
		}
		for(int i=0;i<s;i++)
		{
			dijkstra(a[i]);
			for(int j=0;j<d;j++)
			{
				minn=min(minn,dis[b[j]]);
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}


