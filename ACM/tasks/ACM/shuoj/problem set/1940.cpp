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
typedef vector<PII> vii;
typedef vector<int> vi;
bool check(int x){
    if(x<2)return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}
void getdata(){
    int t = 100;
    cout<<t<<endl;
    for(int i=0;i<t;i++){
        int n = 0;
        rep(i,4)n =((n<<6)|(rand()%64));
        n %= 100001;
        int m = 0;
        rep(i,4)m = ((m<<6)|(rand()%64));
        m %= (n+1);
        int k = 0;
        while(!check(k)){
            k=0;
            rep(i,4)k = ((k<<7)|(rand()%128));
            k = (k<<(rand()%3));
            k %= 1000000008;
        }
        cout<<n<<" "<<m<<" "<<k<<endl;
    }
}
ll quick_power(ll n,ll m,ll mod){
    ll ret = 1;
    while(m){
        if(m&1) ret = ret * n % mod;
        n = n * n % mod;
        m>>=1;
    }
    return ret;
}
ll fac[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("1940.in","w",stdout);
        //getdata();
        freopen("1940.in","r",stdin);
        freopen("1940.out","w",stdout);
    #endif // LOCAL
    int t;
    cin>>t;
    int n,m,k;
    while(t--){
        cin>>n>>m>>k;
        fac[0] = 1;
        rep2(i,1,n)fac[i] = fac[i-1] * (ll)i % k;
        ll ans = fac[n];
        ans = ans * quick_power(fac[m] * fac[n-m] % k, k - 2, k) %k;
        cout<<ans<<endl;

    }


    return 0;
}

