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
const int maxn=6010;
vector<int>G[maxn];
//vector<pair<int,int> > ans;
int dfn[maxn],low[maxn];
int dclock;
int ans,n;
int nbri, bri[maxn][2];
int vis[maxn][maxn];


void tarjan(int u, int fa){
   // int son = 0;
    dfn[u] = low[u] = ++dclock;
    for(int i = 0; i <G[u].size(); i ++){
        int v = G[u][i];
        if(dfn[v]<0){
            tarjan(v, u);
           // son ++;
            low[u] = min(low[u], low[v]);
          //  if((fa < 0 && son > 1) || (fa >= 0 && low[v] >= dfn[u])) cut[u] = 1; //点u为割点
            if(low[v] > dfn[u]) {bri[nbri][0] = u; bri[nbri++][1] = v; }  //边(u,v)是桥。
        }else if(low[u] > low[v]&&v!=fa) low[u] = min(low[u], dfn[v]);
    }
}


int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		int num;
		int u,v;
		char a;
		memset(dfn,-1,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));
		dclock=0;
		nbri=0;
		for(int i=0;i<n;i++)
		{
			cin>>u;
			cin>>a>>num>>a;
			REP(i,num)
			{
				cin>>v;
				if(u==v)continue;
				G[u].push_back(v);
			}
		}
		REP(i,n)
		{
			if(dfn[i]<0)
			{
				dclock=0;
				tarjan(i,-1);
			}
		}
		if(nbri!=1)
		cout<<nbri<<" critical links"<<endl;
		else 
		{
			cout<<nbri<<" critical link"<<endl;
		}
		REP(i,nbri)
		{
			cout<<bri[i][0]<<" - "<<bri[i][1]<<endl;
		}
		cout<<endl;
	}	
	return 0;
}

