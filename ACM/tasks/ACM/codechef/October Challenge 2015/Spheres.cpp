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
const ll MOD = 1e9 + 7;
ll a[1010];
ll b[1010];
ll dp[1010];
ll ans[1010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m,c;
    while(cin>>n>>m>>c){
        int tmp;
        clr(a,0);
        clr(b,0);
        rep(i,n){
            cin>>tmp;
            a[tmp]++;
        }
        rep(j,m){
            cin>>tmp;
            b[tmp]++;
        }
        rep2(i,1,c){
            ll x = a[i] * b[i] % MOD;
            dep(j,c,1){
                dp[j] += dp[j-1] * x  % MOD;
                dp[j] %= MOD;
            }
            dp[0] += x;
            dp[0] %= MOD;
        }
        rep(i,c){
            if(i)cout << " ";
            cout << dp[i+1];
        }
        cout << endl;
    }
    return 0;
}
