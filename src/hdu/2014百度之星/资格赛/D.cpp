#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
int n, m, a[105][105], dp[105][105], w[105][105][105];

int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 105; i++)
            for (int j = 0; j < 105; j++)
                dp[i][j] = -INF;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        if (m == 1) {
            printf("Case #%d:\n%d\n", cas, a[1][1]);
            continue;
        }
        memset(w, 0, sizeof(w));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= j; k++) {
                    if (j == k)w[i][j][k] = a[k][i];
                    else {
                        w[i][j][k] = w[i][j - 1][k] + a[j][i];
                        w[i][k][j] = w[i][j][k];
                    }
                }
            }
        }
        dp[2][1] = a[1][1];
        for (int i = 2; i <= n; i++)
            dp[2][i] = dp[2][i - 1] + a[i][1];
        for (int i = 3; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + w[i - 1][j][k]);
                }
            }
        }
        int ans = -INF;
        for (int i = 1; i <= n; i++) {
            int temp = dp[m][i] + w[m][i][1];
            ans = max(ans, temp);
        }
        printf("Case #%d:\n%d\n", cas, ans);
    }
    return 0;
}
