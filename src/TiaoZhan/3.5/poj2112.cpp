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
const int MAX_V=250;
int Map[MAX_V][MAX_V];
struct node
{
	int cap,f;
};
node net[MAX_V][MAX_V];
int level[MAX_V];
int V;
void bfs(int s,int t)
{
	queue<int>q;
	CLR(level,-1);
	q.push(s);
	level[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<=t;i++)
		{
			if(level[i]<0&&net[u][i].cap>net[u][i].f)
			{
				level[i]=level[u]+1;
				q.push(i);
			//	cout<<i<<"   "<<level[i]<<endl;
			}
		}
	}
}
int dfs(int v,int t,int f)
{
	if(v==t)return f;
	for(int i=0;i<=t;i++)
	{
		if(net[v][i].cap>net[v][i].f&&level[i]==level[v]+1)
		{
			int d=dfs(i,t,min(net[v][i].cap-net[v][i].f,f));
			if(d>0)
			{
				net[v][i].f+=d;
				net[i][v].f-=d;
				return d;
			}
		}
	}
	return 0;
}
int dinic(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s,t);
		if(level[t]<0)return flow;
		int f;
		while((f=dfs(s,t,INF))>0)
		{
		//	cout<<f<<endl;
			flow+=f;
		}
	}
	
}
void floyd(int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				Map[i][j]=min(Map[i][k]+Map[k][j],Map[i][j]);
			}
		}
	}
}
void add_edge(int u,int v,int cap)
{
	net[u][v].cap=cap;
	//cout<<u<<"  "<<v<<endl;
}
int c,k,m;
void build(int s,int t,int mid)
{
	CLR(net,0);
	for(int i=c;i<V;i++)
	{
		add_edge(s,i,1);
	}
	for(int i=0;i<c;i++)
	{
		add_edge(i,t,m);
	}
	for(int i=0;i<c;i++)
	{
		for(int j=c;j<V;j++)
		{
			if(Map[i][j]<=mid)
			{
				add_edge(j,i,1);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	
	while(scanf("%d%d%d",&c,&k,&m)!=EOF)
	{
		for(int i=0;i<c+k;i++)
		{
			for(int j=0;j<c+k;j++)
			{
				scanf("%d",&Map[i][j]);
				if(!Map[i][j])Map[i][j]=INF;
			}
		}
	/*	for(int i=0;i<c+k;i++)
		{
			for(int j=0;j<c+k;j++)
			{
				cout<<Map[i][j]<<" ";
			}
			cout<<endl;
		}*/
		V=c+k;
		floyd(c+k);
		int s=c+k,t=s+1;
		int l=0,r=INF;
		int ans=INF;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			build(s,t,mid);
			int res=dinic(s,t);
		//	cout<<res<<endl;
			if(res<k)
			{
				l=mid+1;
			}
			else
			{
				r=mid-1;
				ans=min(ans,mid);
			}
		//	cout<<"ok"<<endl;
		}
		printf("%d\n",ans);
	}
			
		
		
	return 0;
}



