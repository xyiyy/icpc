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
	int to,cap,rev;
};
const int MAX_V=1010;
vector<edge> G[MAX_V];
int level[MAX_V];//层次 
int iter[MAX_V];//当前弧，在其之前的边已经没有用了

void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
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
			if(e.cap>0&&level[e.to]<0)
			{
				level[e.to]=level[v]+1;
				que.push(e.to);
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
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0)return flow;
		CLR(iter,0);
		int f;
		while((f=dfs(s,t,INF))>0)
		{
			flow+=f;
		}
	}
}
const int MAX_N=110;
const int MAX_F=110;
const int MAX_D=110;
int main()
{
	ios::sync_with_stdio(false);
	int n,f,d;
	while(cin>>n>>f>>d)
	{
		for(int i=0;i<510;i++)G[i].clear();
		int s=n*2+f+d;
		int t=s+1;
		for(int i=0;i<n;i++)
		{
			add_edge(i,n+i,1);
		}
		for(int i=0;i<f;i++)
		{
			add_edge(s,2*n+i,1);
		}
		for(int i=0;i<d;i++)
		{
			add_edge(2*n+f+i,t,1);
		}
		int num1,num2;
		int food,drink;
		for(int i=0;i<n;i++)
		{
			cin>>num1>>num2;
			while(num1--)
			{
				cin>>food;
				add_edge(2*n+food-1,i,1);
			}
			while(num2--)
			{
				cin>>drink;
				add_edge(n+i,2*n+f+drink-1,1);
			}
		}
		cout<<max_flow(s,t)<<endl;
	}
			
	return 0;
}



