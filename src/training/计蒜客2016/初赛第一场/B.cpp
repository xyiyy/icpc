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

bool ok[510][510];
int a[10010];
int gao[510];
int dp[510];
int ans = 0;
vector<int>G[10010];
const int maxn = 500;
int sum[10010][510];
void dfs1(int u,int fa){
    sum[u][a[u]]++;
    int sz = G[u].size();
    for(int i =0 ; i < sz;i++){
        int v = G[u][i];
        if(v== fa)continue;
        dfs1(v,u);
        for(int j = 0 ;j <510;j++)sum[u][j] += sum[v][j];
    }
}
void dfs(int u,int fa){
    now++;
    for(int i = 1; i <= maxn;i++){
        dp[i] += gao[i];
        if(ok[a[u]][i])ans+=dp[i];
    }
    gao[a[u]]++;
    int sz = G[u].size();
    for(int i =0 ; i < sz; i ++){
        int v = G[u][i];
        if(v == fa)continue;
        dfs(v,u);
    }
    for(int i = 1; i <= maxn; i++){
        dp[i] -= gao[i];
    }
    for(int i = 1; i <= maxn; i++){
        dp[i] += (sum[u][i] << 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i = 1 ; i < 510 ; i ++){
        for(int j = 1; j < 510 ; j ++){
            if(__gcd(i,j) == 1)ok[i][j] = 1;
        }
    }
    int n;
    cin >> n;
    rep(i,n)cin >> a[i];
    for(int i = 0 ;i < n - 1; i ++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs1(0,-1);
    now = 0;
    dfs(0,-1);
    cout << ans << endl;
    return 0;
}
