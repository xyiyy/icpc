
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
vector<PII>G[210];
bool can[210];
typedef vector<double> vec;
typedef vector<vec> mat;
void dfs(int u){
    can[u] = 1;
    rep(i,G[u].size()){
        int v = G[u][i].first;
        if(can[v])continue;
        dfs(v);
    }
}
const double EPS = 1e-8;

vec gauss_jordan(const mat &A,const vec &b){
    int n = A.size();
    mat B(n,vec(n+1));
    rep(i,n){
        rep(j,n){
            B[i][j] = A[i][j];
        }
    }
    rep(i,n)B[i][n] = b[i];
    rep(i,n){
        int pivot = i;
        rep2(j,i,n-1){
            if(abs(B[j][i])>abs(B[pivot][i]))pivot = j;
        }
        swap(B[i],B[pivot]);
        if(abs(B[i][i])<EPS)return vec();

        rep2(j,i+1,n)B[i][j] /= B[i][i];
        rep(j,n){
            if(i!=j){
                rep2(k,i+1,n)B[j][k] -= B[j][i] * B[i][k];
            }
        }
    }
    vec x(n);
    rep(i,n)x[i] = B[i][n];
    return x;
}


int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    scanf("%d%d",&n,&m);
    int u,v,w;
    rep(i,m){
        scanf("%d%d%d",&u,&v,&w);
        u--;v--;
        G[u].pb(mp(v,w));
        G[v].pb(mp(u,w));
    }
    dfs(0);
    mat A(n,vec(n,0));
    vec b(n,0);
    rep(i,n){
        if(i==n-1||!can[i]){
            A[i][i] = 1;
            continue;
        }
        int sz = G[i].size();
        int tot = 0;
        int num = 0;
        rep(j,sz){
            int v = G[i][j].first;
            int d = G[i][j].second;
            A[i][v] = -1;
            tot += d;
            if(v != i)num++;
        }
        A[i][i] = num;
        b[i] = tot;
    }
    vec res = gauss_jordan(A,b);
    printf("%.1f\n",res[0]);

    return 0;
}
