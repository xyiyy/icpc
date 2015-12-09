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
int V;
const int MAX_V=1010;
vector<int> G[MAX_V];
int match[MAX_V];
bool used [MAX_V];
void add_edge(int u,int v)
{
	G[u].PB(v);
	G[v].PB(u);
}
int dfs(int v)
{
	used[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[u]=v;
			match[v]=u;
			return 1;
		}
	}
	
	return 0;
}
	
int bipartite_matching()
{
	int res=0;
	CLR(match,-1);
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			CLR(used,0);
			if(dfs(v))
			{
				res++;
			}
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k)
	{
		V=n+n;
		for(int i=0;i<V;i++)G[i].clear();
		int u,v;
		for(int i=0;i<k;i++)
		{
			cin>>u>>v;
			u--,v--;
			add_edge(u,n+v);
		}
		cout<<bipartite_matching()<<endl;
	}
	return 0;
}



