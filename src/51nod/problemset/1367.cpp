//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MAXN 100010
int p[MAXN];
vector<int >G[MAXN];
int dp[MAXN][2];
int pre[MAXN][2];
int ans=0;
int d;
void dfs1(int u,int fa){
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa)continue;
		dfs1(v,u);
		if(dp[v][0]+1>dp[u][1]){
			dp[u][1]=dp[v][0]+1;
			pre[u][1]=v;
			if(dp[u][1]>dp[u][0]){
				swap(pre[u][0],pre[u][1]);
				swap(dp[u][1],dp[u][0]);
			}
		}
	}
}
void dfs2(int u,int fa,int dis){
	if(dis>d)return;
	if(dp[u][0]<=d)ans++;
	int d0=dis+1,d1=dis+1;
	d0=max(dp[u][0]+1,d0);
	d1=max(dp[u][1]+1,d1);
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa)continue;
		if(pre[u][0]==v)dfs2(v,u,d1);
		else dfs2(v,u,d0);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m>>d;
	int u,v;
	for(int i=0;i<m;i++)cin>>p[i];
	for(int i=0;i<m;i++)p[i]--;
	for(int i=0;i<n;i++)pre[i][0]=pre[i][1]=-1;
	for(int i=0;i<n;i++)dp[i][0]=dp[i][1]=-INF;
	for(int i=0;i<m;i++)dp[p[i]][0]=0;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans=0;
	dfs1(0,-1);
	dfs2(0,-1,-INF);
	cout<<ans<<endl;
	return 0;
}

vector<PII>G[500010];
ll dp[500010][2];

int main()
{
	ios::sync_with_stdio(false);
    int n,maxx;
    cin>>n>>maxx;
    int u,v,d;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>d;
        G[u].PB(MP(v,d));
    }

	return 0;
}


