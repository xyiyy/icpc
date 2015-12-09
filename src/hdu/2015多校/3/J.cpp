//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
#pragma comment(linker, "/STACK:102400000,102400000")
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
int Scan() {
	int res=0, ch;
	while(ch=getchar(), ch<'0'||ch>'9');
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
void Out(int a) {
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int w[500010];
vector<int>G[500010];
int dp[500010];
void dfs1(int u,int fa){
	dp[u] = 1;
	REP(i,G[u].size()){
		int v = G[u][i];
		if(v == fa)continue;
		dfs1(v,u);
		if(w[v] > w[u])dp[u] += dp[v];
	}
}
void dfs2(int u,int fa){
	if(fa!=-1){
		if(w[fa] > w[u])dp[u] += dp[fa];
	}
	REP(i,G[u].size()){
		int v = G[u][i];
		if(v == fa)continue;
		dfs2(v,u);
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF){
		REP(i,n)w[i] = Scan();
		REP(i,n)G[i].clear();
		int u,v;
		REP(i,n-1){
			u = Scan();
			v = Scan();
			u--;v--;
			G[u].PB(v);
			G[v].PB(u);
		}
		dfs1(0,-1);
		dfs2(0,-1);
		int ans = 0;
		REP(i,n)ans = max(dp[i],ans);
		Out(ans);
		puts("");
	}
	return 0;
}


/*
7
5 1 7 2 3 8 6
1 2
1 3
2 4
2 5
3 6
3 7
9
1 2 3 4 5 6 7 8 9
9 1
1 2
4 2
2 3
3 7
3 6
2 5
5 8
9
1 2 3 4 5 6 7 8 9
1 9
9 8
1 5
1 2
2 7
7 4
2 6
6 3
*/

