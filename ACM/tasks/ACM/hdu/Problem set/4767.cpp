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
ll prime[5] = {31,37,41,43,47};
const int maxn = 50;
ll MOD;
class Matrix{
public:
    Matrix(){}
    Matrix(int _r,int _c):r(_r),c(_c){}
    void Init()
    {
        rep(i,r){
            rep(j,c){
                if(i==j)m[i][j] = 1;
                else m[i][j] =0;
            }
        }
    }
    void Unit();
    friend Matrix operator *(const Matrix &,const Matrix &);
    Matrix power(ll n);
    ll m[maxn][maxn];
    int r,c;
};
void Matrix::Unit(){
    int j = r - 1;
    rep(i,j){
        m[i+1][i] = 1;
    }
    m[0][j] = m[1][j] = 1;
}
Matrix operator*(const Matrix&M1,const Matrix &M2)
{
    Matrix M(M1.r,M2.c);
    rep(i,M1.r)
    rep(j,M2.c)M.m[i][j] = 0;
    rep(i,M1.r)
    rep(k,M1.c)
    {
        if(M1.m[i][k]!=0)
        rep(j,M2.c)
        {
            M.m[i][j]=(M.m[i][j]+M1.m[i][k]*M2.m[k][j])%MOD;
        }
    }
    return M;
}
Matrix Matrix::power(ll n){
    Matrix tmp(r,r);
    rep(i,r){
        rep(j,c){
            tmp.m[i][j] = m[i][j];
        }
    }
    (*this).Init();
    while(n){
        if(n&1)(*this) = (*this)*tmp;
        tmp =tmp *tmp;
        n>>=1;
    }
    return *this;
}
void extgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){d = a;x=1;y=0;}
    else {extgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

ll CRT(int n,ll *a,ll *m){
    ll M = 1, d, y, x = 0;
    rep(i,n)M *= m[i];
    rep(i,n){
        ll w = M / m[i];
        extgcd(m[i], w, d, d, y);
        x = (x + y * w * a[i]) % M;
    }
    return (x + M) % M;
}
int B[4010];int T[4010];
void Bell(int T[],int N,int MOD){
    B[0] = 1;B[1] = 1;T[0] = 1;
    for(int i=2;i<N;i++){
        T[i-1] = B[i-1];
        for(int j=i-2;j>=0;j--)T[j] = (T[j]+T[j+1])%MOD;
        B[i] = T[0];
    }
}
Matrix mat[5],pat[5];
Matrix l[5],r[5];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;cin>>t;
    rep(i,5){
        mat[i] = Matrix(prime[i],prime[i]);
        mat[i].Init();
        mat[i].Unit();
    }
    rep(i,5){
        pat[i] = Matrix(1,prime[i]);
        Bell(T,prime[i],prime[i]);
        rep(j,prime[i])pat[i].m[0][j] = B[j];
    }
    while(t--){
        int n;
        cin>>n;
        ll a[5];
        int ans = 0;
        rep(i,5){
            MOD = prime[i];
            l[i] = pat[i] , r[i] = mat[i];
            int m = n / MOD;
            l[i] = l[i] * r[i].power(m);
            a[i] = l[i].m[0][n%MOD];
        }
        ans = CRT(5,a,prime);
        cout << ans << endl;
    }
    return 0;
}

