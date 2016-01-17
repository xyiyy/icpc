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
struct node{
    int to,w,Next;
    int lca;
};
const int MAXN = 100010;
node edge[MAXN];
node qedge[MAXN];
bool vis[MAXN];
int head[MAXN];
int qhead[MAXN];
ll d[MAXN];
ll res[MAXN];

int tot1, tot2;
void addedge1(int u,int v,int w){
    edge[tot1].to = v;
    edge[tot1].w = w;
    edge[tot1].Next = head[u];
    head[u] = tot1;
    tot1++;

    edge[tot1].to = u;
    edge[tot1].w = w;
    edge[tot1].Next = head[v];
    head[v] = tot1;
    tot1++;
}
void addedge2(int u,int v){
    qedge[tot2].to = v;
    qedge[tot2].Next = qhead[u];
    qhead[u] = tot2;
    tot2++;
}
int p[MAXN];
int find(int x){
    if(p[x]!=x){
        p[x] = find(p[x]);
    }
    return p[x];
}

void dfs(int u,int f,ll w){
    d[u] = w;
    for(int i = head[u];i!=-1;i=edge[i].Next){
        int v = edge[i].to;
        if(v == f)continue;
        dfs(v,u,w+edge[i].w);
    }
}
void tarjan(int u){
    p[u] = u;
    vis[u] = 1;
    for(int i = head[u];i!=-1;i=edge[i].Next){
        int v = edge[i].to;
        if(!vis[v]){
            tarjan(v);
            p[v] = u;
            //cout << v << " " << u << endl;
        }
    }
    for(int i = qhead[u];i!=-1;i = qedge[i].Next){
        int v = qedge[i].to;
        if(vis[v]){
            qedge[i].lca = find(v);
            res[i] = d[u] + d[v] - 2 * d[qedge[i].lca];
            //cout << u << " " << v << " " << d[qedge[i].lca] << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int u,v,w;
        tot1 = 0;
        tot2 = 0;
        clr(head,-1);
        clr(qhead,-1);
        clr(vis,0);
        rep(i,n-1){
            cin>>u>>v>>w;
            addedge1(u,v,w);
        }
        rep(i,m){
            cin >> u >> v;
            addedge2(u,v);
        }
        dfs(1,0,0);
        tarjan(1);
        //rep(i,m)cout << qedge[i].lca<< endl;
        for(int i=0;i<m;i++){
            //cout << qedge[i].lca<<endl;
            printf("%I64d\n",res[i]);
        }
    }


    return 0;
}
