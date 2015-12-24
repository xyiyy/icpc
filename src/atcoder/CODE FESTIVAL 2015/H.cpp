
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
int l[2010],r[2010];
map<int,int>ls;
//int G[2010][2010];
vector<int>G[2010];
int sz[2010];
PII p[2010];
const ll MOD = 1000000007;
int sum[2010][2010];
int dp[2010][2010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    cin>>n;
    rep(i,n){
        cin>>p[i].second>>p[i].first;
    }
    sort(p,p+n);
    n = unique(p,p+n) - p;
    rep(i,n)l[i]=p[i].second;
    l[n] = -INF;
    l[n+1] = INF;
    sort(l,l+n+2);
    int lnum = unique(l,l+n+2)-l;
    //ls[-INF] = 0;
    rep(i,lnum)ls.insert(mp(l[i],i+1));
    //ls[INF] = n + 1;
    G[0].pb(-100);
    dp[0][0] = 1;
    sum[0][0] = 1;
    sz[0]++;
    ll ans = 1;
    rep(i,n){
        int tl = p[i].second;
        int tr = p[i].first;
        int px = lower_bound(l,l+lnum,tl) - l;
        //if(l[px]!=tl)px--;
        //G[px][sz[px]] = tr;
        ll tmp = 1;
        //ans++;
        rep(j,px){
            if(G[j].size()==0)continue;
            int pr = lower_bound(G[j].begin(),G[j].end(),tr) - G[j].begin();
            //tmp += sum[];
            if(pr == 0);
            else tmp += sum[j][pr-1];
            if(G[j][sz[j]-1]<tr&&G[j][sz[j]-1]>=tl){G[j].pb(tr);sum[j][sz[j]] = dp[j][pr];sz[j]++;}//sum[j][sz[j]]=sum[j][sz[j-1]]+1}
        }
        tmp %= MOD;
        cout<< tmp << endl;
        G[px].pb(tr);
        //G[px][sz[px]] = tr;
        dp[px][sz[px]] = tmp;
        sum[px][sz[px]] = tmp;
        sz[px]++;
    }
    ll gao = 0;
    rep(i,lnum){
        gao += sum[i][sz[i]-1];
        gao %= MOD;
    }
    cout << gao << endl;
    return 0;
}
