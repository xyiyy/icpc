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

void getdata(){
    int t = 10;
    cout<<t<<endl;
    for(int i=0;i<t;i++){
        int n = 0;
        rep(i,4)n =((n<<6)|(rand()%64));
        n %= 100001;
        int m = 0;
        rep(i,4)m = ((m<<6)|(rand()%64));
        m %= (n+1);
        int k = 0;
        rep(i,4)k = ((k<<7)|(rand()%128));
        k = (k<<(rand()%3));
        k %= 1000000008;
        cout<<n<<" "<<m<<" "<<k<<endl;
    }
}
vector<PII>vec[100010];
ll quick_power(ll n,ll m,ll mod){
    ll ret = 1;
    while(m){
        if(m&1) ret = ret * n % mod;
        n = n * n % mod;
        m>>=1;
    }
    return ret;
}
map<int,int>ms;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("1939.in","w",stdout);
        //getdata();
        freopen("1939.in","r",stdin);
        freopen("1939a.out","w",stdout);
    #endif // LOCAL
    int t;
    cin>>t;
    rep2(i,2,100000){
        int tmp = i;
        for(int j=2;j*j<=tmp;j++){
            if(tmp%j==0){
                int num = 0;
                while(tmp%j==0){
                    num++;
                    tmp/=j;
                }
                vec[i].pb(mp(j,num));
            }
        }
        if(tmp!=1)vec[i].pb(mp(tmp,1));
    }
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        ms.clear();
        int tmp = min(m,n-m);
        int p = max(m,n-m);
        rep2(i,p+1,n){
            rep(j,vec[i].size()){
                int x = vec[i][j].first;
                int y = vec[i][j].second;
                ms[x]+=y;
            }
        }
        rep2(i,2,tmp){
            rep(j,vec[i].size()){
                int x = vec[i][j].first;
                int y = vec[i][j].second;
                ms[x]-=y;
            }
        }
        ll ans = 1;
        for(map<int,int>::IT it = ms.begin();it!=ms.end();it++){
            ans = ans * quick_power(it->first,it->second,k) % k;
        }
        cout<<ans<<endl;
    }
    return 0;
}

