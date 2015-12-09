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
int V;
const int maxn=200010;
vector<int>G[maxn];
vector<int>rG[maxn];
vector<int>vs;
int out[maxn];
int in[maxn];
bool used[maxn];
int cmp[maxn];
void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v)
{
	used[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}
int rdfs(int v,int k)
{
	used[v]=1;
	cmp[v]=k;
	for(int i=0;i<rG[v].size();i++)
	{
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}
int scc()
{
	memset(used,0,sizeof(used));
	vs.clear();
	for(int i=0;i<V;i++)
	{
		if(!used[i])dfs(i);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=0;i<V;i++)
	{
		if(!used[i])rdfs(i,k++);
	}
	return k;
}
	
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)G[i].clear();
		for(int i=0;i<n;i++)G[i].clear();
		V=n;
		int u,v; 
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			add_edge(--u,--v);
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		int num=scc();
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<G[i].size();j++)
			{
				int v=G[i][j];
				if(cmp[i]!=cmp[j])
				{
					out[i]++;
					in[j]++;
				}
			}
		}
		int a=0,b=0;
		for(int i=0;i<V;i++)
		{
			if(!in[i])a++;
			if(!out[i])b++;
		}
		cout<<max(a,b)<<endl;
	}
			
	return 0;
}



