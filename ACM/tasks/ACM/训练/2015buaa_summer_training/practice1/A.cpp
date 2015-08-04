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
typedef vector<PII> vii;
typedef vector<int> vi;
int a[6010];
vi G[6010];
int dp[6010];
int ans;
int n;
void dfs(int x,int fa){
    int tmp = lower_bound(dp,dp+n,a[x])-dp;
    ans = max(tmp+1,ans);
    int gao = dp[tmp];
    dp[tmp] = a[x];
    rep(i,G[x].size()){
        int v = G[x][i];
        if(v==fa)continue;
        dfs(v,x);
    }
    dp[tmp] = gao;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int u,v;
    rep(i,n)cin>>a[i];
    rep(i,n-1){
        cin>>u>>v;
        u--;v--;
        G[v].pb(u);
        G[u].pb(v);
    }
    rep(i,n)dp[i] = INF;
    rep(i,n)dfs(i,-1);
    cout<<ans<<endl;
    return 0;
}
