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
ll dp[110];
int pa[5010],ra[5010],b[5010];
void init(int n){
    n += 10;
    rep(i,n){
        pa[i] = i;
        ra[i] = 0;
        b[i]  =0;
    }
}
int find(int x){
    if(pa[x]!=x)pa[x] = find(pa[x]);
    return pa[x];
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y)return;
    if(ra[x] < ra[y])pa[x] = y;
    else {
        pa[y] = x;
        if(ra[x]==ra[y])ra[x]++;
    }
}
ll a[5010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    dp[0] = dp[1] = 1;
    rep2(i,2,50)dp[i] = dp[i-1] + dp[i-2];
    set<ll>ms;
    rep2(i,1,50)ms.insert(dp[i]);
    //cout << dp[50] << endl;
    int n,m;
    while(cin>>n>>m){
        init(n);
        rep(i,n)cin>>a[i];
        int u,v;
        rep(i,m){
            cin>>u>>v;
            u--;v--;
            unite(u,v);
        }
        int ans = 0;
        rep(i,n){
            if(!ms.count(a[i]))continue;
            v = find(i);
            b[v]++;
            ans = max(ans,b[v]);
        }
        cout << ans << endl;;
    }
    return 0;
}


