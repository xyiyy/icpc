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
const int MAXN = 134567;
vector<int>G[MAXN];
int a[MAXN];
/*int dp[MAXN][2];
void dfs1(int u,int fa){
    int sz = G[u].size();
    rep(i,sz){
        int v =G[u][i];
        if(v == fa)continue;
        dfs(v,u);
        int d1 = dp[v][0] + 1;
        if(d1 > dp[u][1]){
            dp[u][1] = d1;
            pre[u][1] = v;
            if(dp[u][1] >dp[u][0]){
                swap(dp[u][0],dp[u][1]);
                swap(dp[u][1],dp[u][0]);
            }
        }
    }
}
int dis[MAXN];
void dfs2(int u,int fa){

}*/
int num[MAXN];
int ans;
int b[MAXN];
void dfs1(int u,int fa){
    int sz = G[u].size();
    b[u] = a[u];
    rep(i,sz){
        int v = G[u][i];
        if(v == fa)continue;
        dfs1(v,u);
        if(a[v])b[u] = 1;
    }
}/*
void dfs2(int u,int fa){
    int sz = G[u].size();
    rep(i,sz){
        int v = G[u][i];
        if(v==fa)continue;
        dfs(v,u);
        if(b[v])num[u]++;
    }
}*/
int dp1[MAXN];
int dp2[MAXN];
int dp3[MAXN];
int pre[MAXN][2];
void dfs3(int u,int fa){
    int sz = G[u].size();
    int tot = 0;
    int max1 = 0;
    int max2 = 0;
    int p1  = -1;
    int p2 = -1;
    rep(i,sz){
        int v = G[u][i];
        if(v == fa)continue;
        dfs3(v,u);
        if(b[v])dp2[u]+=dp2[v]+2;
        //dp2[u] += dp2[v];
        if(b[v]){
            if(dp1[v] + 1 - (dp2[v]+2) < max1){
                max1 = dp1[v] + 1 - (dp2[v]+2);
                p1 = v;
                if(max1 < max2){
                    swap(max1,max2);
                    swap(p1,p2);
                }
            }
        }
    }
    dp1[u] = dp2[u] + max2;
    dp3[u] = dp2[u] + max2 + max1;
    pre[u][0] = p2;
    pre[u][1] = p1;
    //cout<< u << " " << dp1[u] << " " << dp2[u] << " "<<dp3[u] << endl;
    //dp1[u] = dp1[]
}
int f[MAXN];
void dfs4(int u,int fa,int a,int b,int c){
    int sz = G[u].size();
    rep(i,sz){
        int v = G[u][i];
        if(v == fa)continue;
        //if(fa==-1)ans =
        int x;
        //if(!u){
        if(!b[v])continue;
            x = min(dp2[fa] + dp3[u],INF);
            x = min(dp1[fa] + 1 + dp1[u],x);
            x  = min(dp3[fa] + dp2[u] + 2,x);
        //}else x = dp3[u];
        f[u] = x;
        ans = min(ans,x);
        //if(b[v])
        dp2[u] -= dp2[v];
        dp1[u] -= dp1[]

        dfs4(v,u);
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int u,v;
        ans = INF;
        rep(i,n-1){
            scanf("%d%d",&u,&v);
            u--;
            v--;
            G[u].pb(v);
            G[v].pb(u);
        }
        //rep(i,n+1)dp[i][0] = dp[i][1] = -INF;
        //rep(i,n+1)pre[i][0] = pre[i][1] = -1;
        rep(i,m){
            scanf("%d",&u);
            u--;
            a[u] = 1;
            //dp[u][0] = dp[u][1] = 0;
        }
        dfs1(0,-1);
//        dfs2(0,-1);
        dfs3(0,-1);
        dfs4(0,MAXN-3);
        rep(i,n){
            if(f[i]==ans){
                cout << i+1<<endl;
                break;
            }
        }
        cout << ans << endl;
        //cout << ans << endl;
    }
    return 0;
}

