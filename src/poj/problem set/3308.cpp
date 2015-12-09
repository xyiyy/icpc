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
//######################
//Dinic
//by fraud
//////////////////////
struct edge
{
	int to,rev;
	double cap;
	edge(int _to,double _cap,int _rev)
	{
		to=_to;cap=_cap;rev=_rev;
	}
};
const int MAX_V=110;
vector<edge> G[MAX_V];
int level[MAX_V];//层次 
int iter[MAX_V];//当前弧，在其之前的边已经没有用了

void add_edge(int from,int to,double cap)
{
	G[from].push_back(edge(to,cap,G[to].size()));
	G[to].push_back(edge(from,0,G[from].size()-1));
}
void bfs(int s)//层次 
{
	CLR(level,-1);
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++)
		{
			edge &e=G[v][i];
			if(e.cap>1e-12&&level[e.to]<0)
			{
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
double dfs(int v,int t,double f)
{
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>1e-12&&level[v]<level[e.to])
		{
			double d=dfs(e.to,t,min(f,e.cap));
			if(d>1e-12)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

double max_flow(int s,int t)
{
	double flow=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0)return flow;
		CLR(iter,0);
		double f;
		while((f=dfs(s,t,INF))>1e-12)
		{
			flow+=f;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int m,n,l;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l;
		double num;
		int s=n+m,t=s+1;
		for(int i=0;i<t+1;i++)G[i].clear();
		for(int i=0;i<n;i++)
		{
			cin>>num;
			add_edge(s,i,log(num));
		}
		for(int j=0;j<m;j++)
		{
			cin>>num;
			add_edge(j+n,t,log(num));
		}
		int x,y;
		for(int i=0;i<l;i++)
		{
			cin>>x>>y;
			x--;y--;
			add_edge(x,y+n,1e9);
		}
		cout<<fixed<<setprecision(4)<<exp(max_flow(s,t))<<endl;
	}
			
	return 0;
}



