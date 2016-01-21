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
/*bool vis[MAXN];
int head[MAXN],qhead[MAXN],fa[MAXN];
ll disp[MAXN],dise[MAXN],resp[MAXN],rese[MAXN],pa[MAXN];
struct node{
    int Next,to;
};
int tot1, tot2;
struct qnode{
    int Next,to;
    int type,w;
};
node edge[MAXN<<1];
qnode q[MAXN];

void init(int n){
    rep(i,n+10){
        vis[i] = 0;
        head[i] = -1;
        qhead[i] = -1;
        disp[i] = 0;
        dise[i] = 0;
    }
    tot1 = tot2 = 0;
}
void addedge1(int u,int v){
    edge[tot1].to = v;
    edge[tot1].Next = head[u];
    head[u] = tot1++;
    edge[tot1].to = u;
    edge[tot1].Next = head[v];
    head[v] = tot1++;
}
void addedge2(int type,int u,int v,int w){
    q[tot2].to = v;
    q[tot2].type = type;
    q[tot2].w = w;
    q[tot2].Next = qhead[u];
    qhead[u] = tot2++;
}
int find(int x){
    if(x != pa[x])pa[x] = find(pa[x]);
    return pa[x];
}
void tarjan(int u,int f){
    pa[u] = u;
    vis[u] = 1;
    fa[u] = f;
    for(int i = head[u]; i != -1; i = edge[i].Next){
        int v = edge[i].to;
        if(!vis[v]){
            tarjan(v,u);
            pa[v] = u;
        }
    }
    for(int i = qhead[u]; i != -1; i = q[i].Next){
        int v = q[i].to;
        if(vis[v]){
            int lca = find(v);
            //cout << u << " " << v << " " << lca << endl;
            int w = q[i].w;
            if(q[i].type == 1){
                disp[u] += w;
                disp[v] += w;
                disp[lca] -= w;
                disp[fa[lca]] -= w;
            }else{
                dise[u] += w;
                dise[v] += w;
                dise[lca] -= 2 * w;
            }
        }
    }
}
void dfs(int u,int f){
    for(int i = head[u]; i != -1; i = edge[i].Next){
        int v = edge[i].to;
        if(v == f)continue;
        dfs(v,u);
        disp[u] += disp[v];
        dise[u] += dise[v];
        rese[i/2] = dise[v];
    }
   // cout << u << " " <<disp[u] << endl;
}*/
int d[MAXN];
int fa[MAXN][20];
ll disp[MAXN],dise[MAXN];
ll res[MAXN];
int head[MAXN];
struct node{
    int Next,to;
};
int tot1;
node edge[MAXN<<1];

int lca(int u,int v){
    if(d[u] < d[v])swap(u,v);
    //cout << u << " " << v << endl;
    dep(i,19,0){
        if(d[fa[u][i]] >= d[v]) u = fa[u][i];
        //cout << u << " " << v << endl;
        if(u == v)return v;
    }
    dep(i,19,0){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
void dfs1(int u,int f){
    for(int i = head[u];i!=-1;i=edge[i].Next){
        int v = edge[i].to;
        if(v == f)continue;
        d[v] = d[u] + 1;
        fa[v][0] = u;
        for(int j = 1;j<20;j++){
            fa[v][j] = fa[fa[v][j-1]][j-1];
        }
        dfs1(v,u);
    }
}
void dfs2(int u,int f){
    for(int i = head[u]; i!=-1;i = edge[i].Next){
        int v = edge[i].to;
        if(v == f)continue;
        dfs2(v,u);
        res[i / 2] = dise[v];
        dise[u] += dise[v];
        disp[u] += disp[v];
    }
}
void addedge1(int u,int v){
    edge[tot1].to = v;
    edge[tot1].Next = head[u];
    head[u] = tot1++;
    edge[tot1].to = u;
    edge[tot1].Next = head[v];
    head[v] = tot1++;
}
void init(int n){
    rep(i,n+10){
        head[i] = -1;
        disp[i] = 0;
        dise[i] = 0;
    }
    tot1 = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t,cas = 1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        int u,v;
        addedge1(0,1);
        rep(i,n-1){
            scanf("%d%d",&u,&v);
            addedge1(u,v);
        }
        char s[10];
        dfs1(0,-1);
        //cout << fa[fa[4][0]][0] << endl;
        rep(i,m){
            scanf("%s",s);
            int w;
            scanf("%d%d%d",&u,&v,&w);
            if(s[3] == '1'){
                disp[u] += w;
                disp[v] += w;
                int LCA = lca(u,v);
                disp[LCA] -= w;
                disp[fa[LCA][0]] -= w;
                //cout << LCA << endl;
            }else{
                dise[u] += w;
                dise[v] += w;
                int LCA = lca(u,v);
                dise[LCA] -= 2*w;
            }
            //addedge2(s[3] - '0',u,v,w);
        }
        dfs2(0,-1);
        //vis[0] = 1;
        //tarjan(0,-1);
        //dfs(0,-1);
        printf("Case #%d:\n",cas++);
        rep(i,n){
            if(i)printf(" ");
            printf("%d",disp[i+1]);
        }
        printf("\n");
        rep(i,n-1){
            if(i)printf(" ");
            printf("%d",res[i+1]);
        }
        printf("\n");
    }
    return 0;
}


