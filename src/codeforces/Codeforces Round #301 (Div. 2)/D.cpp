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
double dp[110][110][110];
bool vis[110][110][110];

void dfs(int r, int s, int p) {
    if ((r == 0 && s == 0) || (r == 0 && p == 0) || (s == 0 && p == 0)) {
        //dp[r][s][p]=1;
        vis[r][s][p] = 1;
        return;
    }
    if (!vis[r - 1][s][p] && r)dfs(r - 1, s, p);
    if (!vis[r][s - 1][p] && s)dfs(r, s - 1, p);
    if (!vis[r][s][p - 1] && p)dfs(r, s, p - 1);
    dp[r][s][p] =
            (r * s * dp[r][s - 1][p] + s * p * dp[r][s][p - 1] + r * p * dp[r - 1][s][p]) / (r * s + s * p + r * p);
    vis[r][s][p] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    int r, s, p;
    cin >> r >> s >> p;
    CLR(vis, 0);
    CLR(dp, 0);
    for (int i = 0; i <= r; i++) {
        dp[i][0][0] = 1;
        vis[i][0][0] = 1;
    }
    dfs(r, s, p);
    cout << fixed << setprecision(12) << dp[r][s][p] << " ";
    CLR(vis, 0);
    CLR(dp, 0);
    for (int i = 0; i <= s; i++) {
        dp[0][i][0] = 1;
        vis[0][i][0] = 1;
    }
    dfs(r, s, p);
    cout << fixed << setprecision(12) << dp[r][s][p] << " ";
    CLR(vis, 0);
    CLR(dp, 0);
    for (int i = 0; i <= p; i++) {
        dp[0][0][i] = 1;
        vis[0][0][i] = 1;
    }
    dfs(r, s, p);
    cout << fixed << setprecision(12) << dp[r][s][p] << " ";
    cout << endl;

    return 0;
}



