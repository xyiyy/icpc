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
const int LEN=1010;
int n ,m;
int dclock, low[LEN], dfn[LEN];
vector<int> G[LEN];
int vis[LEN][LEN];
vector<pair<int,int> >ans;

void tarjan(int u, int fa){
    dfn[u] = low[u] = ++dclock;
    for(int i = 0; i < G[u].size(); i ++){
        int v = G[u][i];
        if(fa==v)continue;
        if(dfn[v]==-1){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) 
           {
           		ans.PB(MP(u,v));
           		ans.PB(MP(v,u));
           		vis[u][v]=vis[v][u]=1;
           	}
           	else
           	{
           		ans.PB(MP(u,v));
           		vis[u][v]=vis[v][u]=1;
           	}
           		
        }else 
		{
			low[u] = min(low[u], dfn[v]);
        	if(!vis[u][v])
        	{
        		vis[u][v]=vis[v][u]=1;
        		ans.PB(MP(u,v));
        	}
        	
        }
    }
}


int main()
{
	int cas=1;
	while(scanf("%d%d",&n,&m)!=EOF&&(m||n))
	{
		memset(vis,0,sizeof(vis));
		fill(dfn,dfn+n+5,-1);
		memset(low,0,sizeof(low));
		dclock=0;
		ans.clear();
		int u,v;
		for(int i=0;i<=n+1;i++)
		{
			G[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			if(u==v)continue;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		tarjan(1,-1);
		printf("%d\n\n",cas);
		cas++;
		for(int i=0;i<ans.size();i++)
		{
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
		printf("#\n");
	}
		
		
		
		
	return 0;
}

