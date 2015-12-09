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
#include <cctype>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn = 30;
int t[maxn], d[maxn][maxn];
double dp[1 << 9][maxn];

int main() {
    ios::sync_with_stdio(false);
    int n, m, p, a, b;
    while (cin >> n >> m >> p >> a >> b && (n || m || p || a || b)) {
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        int x, y, len;
        for (int i = 0; i < m; i++) {
            fill(d[i], d[i] + m, -1);
        }
        for (int i = 0; i < p; i++) {
            cin >> x >> y >> len;
            x--;
            y--;
            d[x][y] = len;
            d[y][x] = len;
        }
        for (int i = 0; i < (1 << n); i++) {
            fill(dp[i], dp[i] + m, INF);
        }
        dp[(1 << n) - 1][a - 1] = 0;
        double ans = INF;
        for (int s = (1 << n) - 1; s >= 0; s--) {
            ans = min(ans, dp[s][b - 1]);
            for (int v = 0; v < m; v++) {
                for (int i = 0; i < n; i++) {
                    if (s >> i & 1) {
                        for (int u = 0; u < m; u++) {
                            if (d[v][u] >= 0) {
                                dp[s & ~(1 << i)][u] = min(dp[s & ~(1 << i)][u],
                                                           dp[s][v] + (1.0 * d[v][u]) / (t[i] * 1.0));
                            }
                        }
                    }
                }
            }
        }
        if (fabs(ans - INF) <= 1e-3) {
            cout << "Impossible" << endl;
        }
        else {
            cout << fixed << setprecision(3) << ans << endl;
        }
    }

    return 0;
}


