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

vector<PII> G[1010];
int mid;
ll dfs(int u,int fa){
    ll ret = 0;
    rep(i,G[u].size()){
        int v = G[u][i].first;
        if(v == fa)continue;
        ll d = dfs(v,u);
        ll w = G[u][i].second;
        if(w < d && w <= mid) ret += w;
        else ret = ret + d;
    }
    if(!ret)ret = INF;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    while(cin >> n >> m && (n || m)){
        rep(i,n)G[i].clear();
        int u,v,w;
        rep(i,n-1){
            cin >> u >> v >> w;
            u--;v--;
            G[u].pb(mp(v,w));
            G[v].pb(mp(u,w));
        }
        int l = 0,r = 1000;
        int ans = -1;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        while(l <= r){
            mid = (l + r) >> 1;
            if(dfs(0,-1) <= 1LL * m)r = mid - 1,ans = mid;
            else l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}


