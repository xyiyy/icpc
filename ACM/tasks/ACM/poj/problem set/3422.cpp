//gaoshenbaoyou  ------ pass system test
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
struct edge
{
	int to,cap,cost,rev;
};
int V;
const int MAX_V=3010; 
vector<edge> G[MAX_V];
int dis[MAX_V];
int prevv[MAX_V],preve[MAX_V];//最短路中的前驱结点和对应的边 
void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back((edge){to,cap,cost,G[to].size()});
	G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)//如果不能在增广则返回-1 
{
	int res=0;
	while(f>0)
	{
		fill(dis,dis+V,INF);
		dis[s]=0;
		bool update=1;
		while(update)
		{
			update=false;
			for(int v=0;v<V;v++)
			{
				if(dis[v]==INF) continue;
				for(int i=0;i<G[v].size();i++)
				{
					edge &e=G[v][i];
					if(e.cap>0&&dis[e.to]>dis[v]+e.cost)
					{
						dis[e.to]=dis[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						update=1;
					}
				}
			}
		}	
		if(dis[t]==INF)
		{
			return -1;
		}
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
		{
			d=min(d,G[prevv[v]][preve[v]].cap);
		//	cout<<"ok"<<endl;
		}
		f-=d;
		res+=dis[t];
		cout<<f<<" "<<res<<endl;
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			e.cost=0;
			G[v][e.rev].cap+=d;
		}
		//cout<<f<<endl;
	//	cout<<"ok"<<endl;
	}
	return res;
}
const int maxn=55;
int dir[4]={1,0,0,1};
bool vis[maxn][maxn];
int a[maxn][maxn];
int n;
bool in(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n)return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int k;
	while(cin>>n>>k)
	{
		CLR(vis,0);
		for(int i=0;i<n*n+10;i++)G[i].clear();
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
		int s=n*n,t=s+1;
		V=t+1;
		queue<PII> q;
		q.push(MP(0,0));
		vis[0][0]=1;
		add_edge(s,0,INF,-a[0][0]);
		while(!q.empty())
		{
			PII p=q.front();
			int x=p.first;
			int y=p.second;
			q.pop();
			for(int i=0;i<2;i++)
			{
				int dx=x+dir[i*2];
				int dy=y+dir[i*2+1];
				if(in(x,y)&&!vis[dx][dy])
				{
					vis[dx][dy]=1;
					add_edge(x*n+y,dx*n+dy,INF,-a[dx][dy]);
				}
			}
		}
		add_edge(n*n-1,t,k,-a[n-1][n-1]);
		//cout<<"ok"<<endl;
		cout<<-min_cost_flow(s,t,k)<<endl;
	}
	return 0;
}



