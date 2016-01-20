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
int ok[10][10];
int dp[300010][3][3];
int n;
const int MOD = 777777777;
void push_up(int r){
    rep(i,3)
    rep(j,3){
        dp[r][i][j] = 0;
        rep(k,3)
        rep(l,3){
            if(!ok[k][l])continue;
            dp[r][i][j] = (dp[r][i][j] + 1LL * dp[r<<1][i][k] * dp[r<<1|1][l][j]) % MOD;
        }
    }
}
void build(int l = 1,int r = n,int cur = 1){
    if(l > r)return;
    if(l == r){
        rep(i,3)
        rep(j,3)dp[cur][i][j] = 0;
        rep(i,3)dp[cur][i][i] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,cur<<1);
    build(mid+1,r,cur<<1|1);
    push_up(cur);
}
int v,t;
void update(int l = 1,int r = n,int cur = 1){
    if(r < l)return;
    if(l == r){
        rep(i,3)
        rep(j,3)dp[cur][i][j] = 0;
        if(!t){
            rep(i,3)dp[cur][i][i] = 1;
        }else dp[cur][t-1][t-1] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(v <= mid)update(l,mid,cur<<1);
    else update(mid+1,r,cur<<1|1);
    push_up(cur);
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int m;
    cin >> n >> m ;
    rep(i,3)
    rep(j,3)cin>>ok[i][j];
    build();
    int ans = 0;
    while(m -- ){
        cin >> v >> t;
        update();
        ans = 0;
        rep(i,3)
        rep(j,3){
            ans = (ans + 1LL * dp[1][i][j]) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
