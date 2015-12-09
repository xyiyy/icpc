//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X, Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X, N) for(int X=0;X<N;X++)
#define rep2(X, L, R) for(int X=L;X<=R;X++)
#define dep(X, R, L) for(int X=R;X>=L;X--)
#define clr(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int b[110];
int a[200020];
int num[1010];
int dp[200020];

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n, t;
    cin >> n >> t;
    rep(i, n)cin >> b[i];
    int m = min(t, 200);
    rep(i, n) {
        num[b[i]]++;
    }
    rep(i, m) {
        rep(j, n) {
            a[i * n + j] = b[j];
        }
    }
    int f = n * m;
    rep(i, f + 1)dp[i] = INF;
    int len = 0;
    rep(i, f) {
        int x = upper_bound(dp + 1, dp + f + 1, a[i]) - dp;
        dp[x] = min(a[i], dp[x]);
        len = max(x, len);
    }
    //int len = lower_bound(dp,dp+n,INF) - dp;
    int maxx = 0;
    rep(i, 310)maxx = max(num[i], maxx);
    int ans = len + (t - m) * maxx;
    cout << ans << endl;

    return 0;
}
