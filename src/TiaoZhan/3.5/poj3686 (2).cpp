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
	edge(int _to,int _cap,int _cost,int _rev)
	{
		to=_to;cap=_cap;cost=_cost;rev=_rev;
	}
};
int V;
const int MAX_V=3010; 
vector<edge> G[MAX_V];
int dis[MAX_V];
int prevv[MAX_V],preve[MAX_V];//最短路中的前驱结点和对应的边 
void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
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
		}
		f-=d;
		res+=d*dis[t];
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int num[52][52];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int s=(m+1)*n,t=s+1;
		CLR(prevv,-1);
		CLR(preve,-1);
		V=t+1;
		for(int i=0;i<t+1;i++)G[i].clear();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>num[i][j];
			}
		}
		for(int i=0;i<n;i++)add_edge(s,i,1,0);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				add_edge(n+n*i+j,t,1,0);
				for(int k=0;k<n;k++)
				{
					add_edge(k,n+i*n+j,1,(j+1)*num[k][i]);	
				}
			}
		}
		cout<<fixed<<setprecision(6)<<min_cost_flow(s,t,n)/(n*1.0)<<endl;
	}	
	return 0;
}



