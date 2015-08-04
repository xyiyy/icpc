//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
const int MAXN = 100010;
int maxa;
int a[MAXN];
vector<int>G[MAXN];
int dpf[MAXN][110];
int dpg[MAXN];
int p[MAXN][110];
int q[MAXN][110];
int dp1[110];
int dp2[110];
void dfs(int x,int fa){
	int sz = G[x].size();
	for(int i=0;i<sz;i++){
		dfs(G[x][i],x);
	}
	for(int i=0;i<=maxa;i++){
		dpf[x][i] = dpg[x][i] = 0;
		p[x][i] = q[x][i] = INF;
	}
	dpf[x][maxa] = INF;
	for(int i=0;i<G[x].size();i++){
		int y = G[x][i];
		if(fa == y)continue;
		for(int j=0;j<=maxa;j++){
			if(j<maxa){
				if(j)dpf[x][j] += min(p[y][j+1],q[y][j-1]);
				else dpf[x][j] += p[y][j+1];
				if(f[y][j+1]!=INF){
					if(j)dp1[j] = min(dp1[j],dpf[y][j+1]-min(p[y][j+1],q[y][j-1]));
					else dp1[j] = min(dp1[j],dpf[y][j+1]-p[y][j+1]);
				}
			}
			
			if(j){
				dpg[x][j] += g[x][j] + min(dpf[y][j],dpg[y][j-1]);
				if(dpg[y][j-1]!=INF)
					dp2[j] = min(dp2[j],dpg[y][j+1]-min(p[y][j+1],q[y][j-1]));
			}else dpg[x][0] += dpf[y][0];
		}
	}
	if(G[x].size()==1)dpf[x][0] = INF;
	int tmp = INF;
	for(int i=0;i<=a[x];i++)
		tmp = min(tmp,min(dpg[x][i],dpf[x][i])+1);
	dpf[x][0] = min(dpf[x][0],INF);
	dpg[x][0] = min(dpg[x][0],INF);
	for(int i=0;i<maxa;i++){
		dpf[x][i] = min(INF,dpf[x][i] + dp1[i]);
		dpg[x][i] = min(INF,dpg[x][i] + dp2[i]);
	}
	dpf[x][a[x]] = min(dpf[x][a[x]],tmp);
	p[x][0] = dpf[x][0];
	q[x][0] = dpg[x][0];
	for(int i=1;i<=maxa;i++){
		 
	
					
			
				
				
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF){
		maxa = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			maxa = max(maxa,a[i]);
		}
		int u,v;
		for(int i=0;i<n;i++)G[i].clear();
		for(int i=0;i<n-1;i++;){
			scanf("%d %d",&u,&v);
			u--;v--;
			G[u].PB(v);
			G[v].PB(u);
		}
		dfs(0,-1);
	}
	return 0;
}



