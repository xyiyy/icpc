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
typedef vector<PII> VII;
typedef vector<int> VI;
void extgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

ll inv(ll a, ll mod) {
    ll x, y, d;
    extgcd(a, mod, d, x, y);
    return d == 1 ? (x % mod + mod) % mod : -1;
}
const ll MOD = 1000000007;
int deg[110];
bool G[110][110];
//vector<int>G[110];
ll gao[110];
const int maxn = 50;
class Matrix {
public:
    Matrix(int _r, int _c) : r(_r), c(_c) { }

    void Init() {
        rep(i, r)
        {
            rep(j, c)
            {
                if (i == j)m[i][j] = 1;
                else m[i][j] = 0;
            }
        }
    }

    void Unit();

    friend Matrix operator*(const Matrix &, const Matrix &);

    Matrix power(ll n);

    ll m[maxn][maxn];
    int r, c;
};

Matrix operator*(const Matrix &M1, const Matrix &M2) {
    Matrix M(M1.r, M2.c);
    rep(i, M1.r)
    rep(j, M2.c)
    M.m[i][j] = 0;
    rep(i, M1.r)
    rep(k, M1.c)
    {
        if (M1.m[i][k] != 0)
            rep(j, M2.c)
        {
            M.m[i][j] = (M.m[i][j] + M1.m[i][k] * M2.m[k][j]) % MOD;
        }
    }
    return M;
}

Matrix Matrix::power(ll n) {
    Matrix tmp(r, r);
    rep(i, r)
    {
        rep(j, c)
        {
            tmp.m[i][j] = m[i][j];
        }
    }
    (*this).Init();
    while (n) {
        if (n & 1)(*this) = (*this) * tmp;
        tmp = tmp * tmp;
        n >>= 1;
    }
    return *this;
}
Matrix mat(50,50);
Matrix Mat(50,50);
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
//    cout <<inv(2,MOD)<<endl;
    int n,m;
    rep2(i,1,100){
        gao[i]=inv(i,MOD);
    }
    //cout << gao[2] << endl;
    //cout << 5LL * gao[6] % MOD << " "<<gao[2] + gao[3] << endl;
    while(scanf("%d%d",&n,&m)!=EOF){
        int u,v;
        clr(deg,0);
        clr(G,0);
        rep(i,m){
            scanf("%d%d",&u,&v);
            u--;v--;
            deg[u]++;
            G[u][v]=1;
        }
        int q;
        scanf("%d",&q);
        while(q--){
            int k;
            scanf("%d%d",&u,&k);
            u--;

            clr(mat.m,0);
            rep(i,n){
            rep(j,n){
                if(G[i][j])mat.m[i][j]=gao[deg[i]];
               // else mat.m[0][0];
            }
            }
            clr(Mat.m,0);
            Mat.m[u][u]=1;
            Mat = Mat*mat.power(k);
            rep(i,n){
                int res = Mat.m[u][i];
                printf("%d ",res);
            }
            puts("");

        }



    }
    return 0;
}

