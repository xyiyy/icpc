//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
const int MAXN = 100010;
vector<PII> G[MAXN];
ll dp[200010];
void dfs(int u,int f,int now){
    dp[now]++;
    for(int i = 0; i < (int)G[u].size();i++){
        int v = G[u][i].first;
        if(v == f)continue;
        dfs(v,u,now^G[u][i].second);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        rep(i,n)G[i].clear();
        clr(dp,0);
        int u,v,w;
        rep(i,n-1){
            cin >> u >> v >> w;
            u--;v--;
            G[u].pb(mp(v,w));
            G[v].pb(mp(u,w));
        }
        dfs(0,-1,0);
        int q;
        cin >> q;
        while(q--){
            cin >> u;
            ll ans = 0;
            if(u){
                rep(i,200010){
                    ans += dp[i] * (dp[u^i]);
                }
                ans /= 2;
            }else{
                rep(i,200010){
                    ans += dp[i] * (dp[i] - 1) / 2;
                }
                ans += n;
            }
            cout << ans << endl;
        }

    }

    return 0;
}
