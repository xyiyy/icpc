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
int s ,t,k;
const int maxn=1010;
vector<PII>G[maxn];
vector<PII>rG[maxn];
int dis[maxn];
int used[maxn];
void init(int n)
{
	memset(used,0,sizeof(used));
	for(int i=0;i<n;i++)
	{
		dis[i]=INF;
		G[i].clear();
		rG[i].clear();
	}
}
void add_edge(int u,int v,int w){
	G[u].push_back(make_pair(v,w));
	rG[v].push_back(make_pair(u,w));
}
void spfa()
{
	queue<int>q;
	q.push(t);
	used[t]=1;
	dis[t]=0;
	while(!q.empty())
	{
		int u=q.front();
		for(int i=0;i<rG[u].size();i++)
		{
			int v=rG[u][i].first;
			int y=rG[u][i].second;
			if(dis[u]+y<dis[v])
			{
				dis[v]=dis[u]+y;
				if(!used[v])
				{
					used[v]=1;
					q.push(v);
				}
			}
		}
		q.pop();
		used[u]=0;
	}
}
int A_star()
{
	priority_queue<pair<int,PII>,vector<pair<int,PII> >,greater<pair<int,PII> > >q;
	q.push(make_pair(dis[s],make_pair(0,s)));
	CLR(used,0);
	while(!q.empty())
	{
		pair<int,PII> p=q.top();
		q.pop();
		int f=p.first;
		int g=p.second.first;
		int u=p.second.second;
		used[u]++;
		if(used[t]==k)return f;
		if(used[u]>k)continue;
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i].first;
			int d=G[u][i].second;
			q.push(make_pair(g+dis[v]+d,make_pair(g+d,v)));
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		int u,v,w;
		init(n);
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			add_edge(--u,--v,w);
		}
		cin>>s>>t>>k;
		s--;t--; 
		spfa();
		if(s==t)k++;
		cout<<A_star()<<endl;
	}
	return 0;
}



