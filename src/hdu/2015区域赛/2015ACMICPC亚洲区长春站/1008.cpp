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
int f[3010];
int dp[2030][2030];

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        rep2(i, 1, n - 1) {
            scanf("%d", &f[i]);
        }
        rep(i, n)
            rep(j, n)dp[i][j] = -INF;
        dp[0][0] = n * f[1];
        rep2(i, 1, n - 2) {
            rep2(j, 0, i)dp[i][1] = max(dp[i - 1][j] + f[2] - f[1], dp[i][1]);
            rep2(j, 2, i)dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + f[j + 1] - f[j]);
        }
        int ans = -INF;
        rep(i, n - 1) {
            ans = max(ans, dp[n - 2][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
