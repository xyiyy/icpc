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
double a[10010];
double p[10010];
int deg[10010];
vector<int>G[10010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        rep(i,n)scanf("%lf%lf",&a[i],&p[i]);//cin>>a[i]>>p[i];
        int u,v;
        rep(i,n)G[i].clear();
        rep(i,k){
            //cin>>u>>v;
            scanf("%d%d",&u,&v);
            u--;v--;
            G[u].pb(v);
            deg[v]++;
        }
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--;z--;
        queue<int> q;
        q.push(x);
        p[x] += y;
        rep(i,n){
            if(i==x)continue;
            if(!deg[i])q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            if(p[t] > a[t]){
                int sz =G[t].size();
                if(!sz){
                    p[t] = a[t];
                    continue;
                }
                double tmp = (p[t] - a[t]) / G[t].size();
                p[t] = a[t];
                rep(i,G[t].size()){
                    int v = G[t][i];
                    p[v] += tmp;
                    deg[v]--;
                    if(!deg[v]){
                        q.push(v);
                    }
                }
            }
        }
        cout << fixed  << setprecision(10) << p[z] << endl;



    }
    return 0;
}
