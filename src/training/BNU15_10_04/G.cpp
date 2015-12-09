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
int _u[MAXN];
int _v[MAXN];
vector<PII> G[MAXN];
vector<PII> Q[MAXN];
int dft[MAXN];
int dep[MAXN];
int pa[MAXN];
int lca[MAXN];
int find(int x){
    if(pa[x] == -1)return x;
    return pa[x] = find(pa[x]);
}

void dfs(int u,int fa =-1){
    rep(i,G[u].size()){
        int v= G[u][i].first;
        int d = G[u][i].second;
        if(v == fa)continue;
        dft[v] = dft[u] + d;
        dep[v] = dep[u] + 1;
        dfs(v,u);
    }
    rep(i,Q[u].size()){
        int v = Q[u][i].first;
        int x = Q[u][i].second;
        lca[x] = find(v);
    }
    pa[u] = fa;
}

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        int u,v;
        rep(i,n)G[i].clear();
        rep(i,n-1){
            cin>>u>>v;
            u--;v--;
            G[u].pb(mp(v,1));
            G[v].pb(mp(u,-1));
        }
        //cout << "ok"<<endl;;
        int m;
        cin>>m;
        rep(i,m)Q[i].clear();
        rep(i,m){
            cin>>u>>v;
            u--;v--;
            _u[i] = u;
            _v[i] = v;
            Q[u].pb(mp(v,i));
            Q[v].pb(mp(u,i));
        }
        //cout << "ok" << endl;
        clr(pa,-1);
        dfs(n/2);
        //cout <<"ok" << endl;
        dft[n/2] = 0;
        dep[n/2] = 0;
        //rep(i,n)cout << dep[i] << " ";
        //cout << endl;
        rep(i,m){
            u = _u[i];
            v = _v[i];
            int x = dep[u] - dep[lca[i]];
            int y = dep[v] - dep[lca[i]];
            //cout <<x<<" "<<y<<endl;
            if(dft[lca[i]] - dft[u] == x && dft[v] - dft[lca[i]] == y ){
                cout <<"Yes"<<endl;
            }else cout <<"No"<<endl;
        }


    }
    return 0;
}
