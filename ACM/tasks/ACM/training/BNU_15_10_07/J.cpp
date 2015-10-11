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
const int MAX_V = 100010;
const int MAX_LOG_V = 20;
vector<PII>G[MAX_V];
int root;
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];
int dis[MAX_V];

void dfs(int v,int p){
    parent[0][v] = p;
    //cout << v << endl;
    //depth[v] = d;
    rep(i,G[v].size()){
        int x = G[v][i].first;
        int d = G[v][i].second;
        if(x==p)continue;
        depth[x] = depth[v] + 1;
        dis[x] = dis[v] + d;
        dfs(x,v);
    }
}
void init(int V){
    depth[root] = 0;
    dis[root] = 0;
    dfs(root,-1);
    for(int k = 0;k+1<MAX_LOG_V;k++){
        for(int v = 0;v < V;v++){
            if(parent[k][v] < 0)parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u,int v){
    if(depth[u] > depth[v])swap(u,v);
    for(int k =0;k<MAX_LOG_V;k++){
        if((depth[v] - depth[u])>>k & 1){
            v = parent[k][v];
        }
    }
    if(u == v)return u;
    for(int k = MAX_LOG_V - 1; k >=0 ;k--){
        if(parent[k][u]!=parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--){
        int  n,q;
        scanf("%d%d",&n,&q);
        int u,v,w;
        rep(i,n)G[i].clear();
        rep(i,n-1){
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            G[u].pb(mp(v,w));
            G[v].pb(mp(u,w));
        }
        //cout << "ok" << endl;
        init(n);
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;
        //cout << "ok" << endl;
        printf("Case #%d:\n",cas++);
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;y--;
            int f = lca(x,y);
            int tmp = dis[x] - dis[f] + dis[y] - dis[f];
            int df1 = lca(x,u);
            int df2 = lca(y,v);
            int df3 = lca(x,v);
            int df4 = lca(y,u);
            int tmp2 = dis[u] + dis[v] + dis[x] + dis[y] + w;
            tmp2 -=  2*max(dis[df1]+dis[df2],dis[df3]+dis[df4]);
            int ans = max(tmp - tmp2,0);
            printf("%d\n",ans);

        }


    }
    return 0;
}

