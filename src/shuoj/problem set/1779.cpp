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
int deg[1010];
bool vis[1001];
vector<int> G[110];
bool flag;
void dfs(int x)
{
	for(int i=0;i<G[x].size();i++)
	{
		deg[G[x][i]]--;
		if(deg[G[x][i]]==0)
		{
			dfs(G[x][i]);
			vis[G[x][i]]=1;
		}
		
	}
}
	
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		int u,v;
		flag=0;
		for(int i=0;i<n;i++)G[i].clear();
		CLR(deg,0);
		CLR(vis,0);
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			deg[v]++;
			G[u].PB(v);
		}
		for(int i=0;i<n;i++)
		{
			if(!deg[i]&&!vis[i])
			{
				dfs(i);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(deg[i])
			{
				flag=1;
			}
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
		
					
		
		
	return 0;
}


