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
typedef vector<int> VI;/*
struct edge
{
	int to,cap,cost,rev;
	edge(int _to,int _cap,int _cost,int _rev)
	{
		to=_to;cap=_cap;cost=_cost;rev=_rev;
	}
};
int V;
const int MAX_V=410; 
vector<edge> G[MAX_V];
int dis[MAX_V];
int prevv[MAX_V],preve[MAX_V];//最短路中的前驱结点和对应的边 
void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}
int vis[MAX_V];
int min_cost_flow(int s,int t,int f)//如果不能在增广则返回-1 
{
	int res=0;
	while(f>0)
	{
		fill(dis,dis+V,INF);
		dis[s]=0;
		queue<int>q;
		CLR(vis,0);
		q.push(s);
		while(!q.empty())
		{
			int v=q.front();
			q.pop();
			vis[v]=0;
			for(int i=0;i<G[v].size();i++)
			{
				edge &e=G[v][i];
				if(e.cap>0&&dis[e.to]>dis[v]+e.cost)
				{
					dis[e.to]=dis[v]+e.cost;
					prevv[e.to]=v;
					preve[e.to]=i;
					if(!vis[e.to])
					{
						q.push(e.to);
						vis[e.to]=1;
					}
				}
			}
		}
	/*	bool update=1;
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
		}*//*
		if(dis[t]==INF)
		{
			return -1;
		}
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
		{
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*dis[t];
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
		//cout<<f<<endl;
	//	cout<<"ok"<<endl;
	}
	return res;
}*/
vector<PII>vec;
///int a[51][51];
int size;
int ans=INF;
int vis[150];
void dfs(int num,int temp,int last)
{
	if(num==size)
	{
		ans=min(ans,temp);
		return;
	}
	for(int i=0;i<size;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		
		//cout<<i<<"  "<<min(temp-vec[last].first-vec[last].second+abs(vec[i].first-vec[last].first)+abs(vec[i].second-vec[last].second)+vec[i].first+vec[i].second,temp+2*(vec[i].first+vec[i].second))<<endl;
		dfs(num+1,min(temp-vec[last].first-vec[last].second+abs(vec[i].first-vec[last].first)+abs(vec[i].second-vec[last].second)+vec[i].first+vec[i].second,temp+2*(vec[i].first+vec[i].second)),i);
		vis[i]=0;
	}
}
/*
2 6
0 1 0 1 1 1
1 1 1 1 1 1
*/
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		ans=INF;
		vec.clear();
		int smin=INF;
		int x=0,a;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a;
				if(i==0&&j==0)continue;
				if(a)
				{
					vec.PB(MP(i,j));
					if(i+j<smin)
					{
						smin=i+j;
						x=vec.size()-1;
					}
				}
			}
		}
		size=vec.size();
		//cout<<x<<endl;
		CLR(vis,0);
		vis[x]=1;
		if(size)
		if(vec[x].first!=0||vec[x].second!=0)
		dfs(1,2*(vec[x].first+vec[x].second),x);
		if(ans==INF) ans=0;
		cout<<ans<<endl;
	}
				
		

	return 0;
}



