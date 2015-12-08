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
ll a[100010];
ll MOD = 1000000007;
ll m[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    m[0] = 1;
    rep2(i,1,100005)m[i] = m[i-1] * 2 % MOD;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        rep(i,n)cin>>a[i];
        sort(a,a+n);
        a[n] = -1;
        int j = 0,k = 0;
        ll ans = 0;
        while(j<n){
            while(a[j]==a[k])k++;
            int num = k - j;
            ans += a[j] * (m[num] - 1) % MOD * m[j] % MOD;
            ans %= MOD;
            ans -= a[j] * (m[num] - 1) % MOD * m[n-k] % MOD;
            ans = (ans + MOD) % MOD;
            j = k;
        }
        cout << ans << endl;


    }
    return 0;
}

