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
struct edge{
	int to,cap,f,rev;
	edge(int _to,int _cap,int _f,int _rev)
	{
		to=_to;
		cap=_cap;
		f=_f;
		rev=_rev;
	}
};
const int MAX_V=1100;
vector<edge>G[MAX_V];
int level[MAX_V];
void add_edge(int from,int to,int cap)
{
	G[from].PB(edge(to,cap,0,G[to].size()));
	G[to].PB(edge(from,0,0,G[from].size()-1));
}
void bfs(int s,int t)
{
	CLR(level,-1);
	queue<int>q;
	level[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			edge &e=G[u][i];
			if(e.cap>e.f&&level[e.to]<0)
			{
				level[e.to]=level[u]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f)
{
	if(v==t)return f;
	for(int i=0;i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>e.f&&level[v]==level[e.to]-1)
		{
			int d=dfs(e.to,t,min(e.cap-e.f,f));
			if(d>0)
			{
				e.f+=d;;
				G[e.to][e.rev].f-=d;
				return d;
			}
		}
	}
	return 0;
}
int Dinic(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s,t);
		if(level[t]<0)return flow;
		int f;
		while((f=dfs(s,t,INF))>0)
		{
			flow+=f;
		}
	}
}
int q[1100];
int mach1[1100][110];
//int mac1[110];
int mach2[1100][110];
//int mac2[110];
int ans1[10010][3];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
//	cin>>n>>m;
	n=0,m=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//CLR(mach1,0);
		//CLR(mach2,0);
		//CLR(q,0);
		//CLR(mac1,0);
		//CLR(mac2,0);
		for(int i=0;i<m;i++)
		{
			q[i]=0;
			scanf("%d",&q[i]);
			for(int j=0;j<n;j++)
			{
				mach1[i][j]=0;
				scanf("%d",&mach1[i][j]);
				//if(mac)
				//mac1[i]|=mach1[i][j]<<j;
			}
			for(int j=0;j<n;j++)
			{
				mach2[i][j]=0;
				scanf("%d",&mach2[i][j]);
				//mac2[i]|=mach2[i][j]<<j;
			}
		}
		int s=2*m,t=s+1;
		for(int i=0;i<=t;i++)G[i].clear();
		for(int i=0;i<m;i++)
		{
			add_edge(i,i+m,q[i]);
		}
		for(int i=0;i<m;i++)
		{
			bool flagin=1;
			bool flagout=1;
			//int tmpmax=0;
			//int tmpmin=1;
			for(int j=0;j<n;j++)
			{
				if(mach1[i][j]==1)flagin=0;
				if(mach2[i][j]==0)flagout=0;
			}
			if(flagin)add_edge(s,i,INF);
			if(flagout)add_edge(i+m,t,INF);
			//if(tmpmax==0)add_edge(s,i,q[i]);
			//if(tmpmin==1)add_edge(i+m,t,q[i]);
			for(int j=0;j<m;j++)
			{
				if(i==j)continue;
				bool flag=1;
				for(int k=0;k<n;k++)
				{
					if(mach2[i][k]+mach1[j][k]==1)flag=0;
				}
				if(flag)add_edge(i+m,j,INF);
			}
		}
		int id=0;
		int ans=Dinic(s,t);
		//cout<<Dinic(s,t)<<endl;
		for(int i=0;i<s;i++)
		{
			for(int j=0;j<G[i].size();j++)
			{
				int v=G[i][j].to;
				if(v==i+m||v==s||v==t)continue;
				if(G[i][j].cap&&G[i][j].f!=0)
				{
					ans1[id][0]=i%m+1;
					ans1[id][1]=v%m+1;
					ans1[id][2]=G[i][j].f;
					id++;
				}
				//cout<<(i+1)%m<<" "<<(v+1)%m<<" "<<G[i][j].f<<endl;
			}
		}
		printf("%d %d\n",ans,id);
	//	cout<<ans<<" "<<id<<endl;
		for(int i=0;i<id;i++)
		{
			printf("%d %d %d\n",ans1[i][0],ans1[i][1],ans1[i][2]);
			//cout<<ans1[i][0]<<" "<<ans1[i][1]<<" "<<ans1[i][2]<<endl;
		}
		
	}
			
	return 0;
}



