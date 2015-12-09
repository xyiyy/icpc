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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
const int MAX_V=2020;
int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
int k;
void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v]=true;
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
	for(int v=0;v<V;v++)
	{
		if(!used[v])dfs(v);
	}
	memset(used,0,sizeof(used));
	k=0;
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]])rdfs(vs[i],k++);
	}
	return k;
}


int main()
{
	ios::sync_with_stdio(false);
	int mm;
	while(cin>>V>>mm)
	{
		for(int i=0;i<V;i++)
		{
			G[i].clear();
			rG[i].clear();
		}
		int u,v;
		for(int i=0;i<mm;i++)
		{
			cin>>u>>v;
			add_edge(u-1,v-1);
			add_edge(v-1,u-1);
		}
		scc();
		cout<<k<<endl;
	}
		
	return 0;
}

