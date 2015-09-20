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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
vector<int>G[100010];
int dp[100010];
int ff = 0;
void dfs(int u,int fa){
	int num = 0;
	int sz = G[u].size();
	rep(i,sz){
		int v = G[u][i];
		if(v == fa)continue;
		dfs(v,u);
		dp[u] += dp[v];
		num++; 	
	}
	if(!dp[u])dp[u] = 1;
	if(dp[u] == 2 && num == 1)dp[u]++;
}
void dfs2(int u,int fa,int num){
	int sz = G[u].size();
	int n = 0;
	if(num>2)n++;
	rep(i,sz){
		int v = G[u][i];
		if(v == fa)continue;
		int tmp = 1;
		tmp = max(num+dp[u]-dp[v],tmp);
		if(tmp == 2 && num == 2)tmp = 3;
		dfs2(v,u,tmp);
		if(dp[v]>2)n++;
	}
	if(n>2)ff = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		u--;v--;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(0,-1);
	dfs2(0,-1,0);
	
	
	if(ff)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
		
		
	return 0;
}



