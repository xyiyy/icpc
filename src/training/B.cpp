//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MAXN 100010
char a[5][MAXN];
int dp[MAXN][10];
int m[MAXN];
const int MOD = 1000000007;
int n;

int gao() {
    CLR(m, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'X')m[j] |= 1 << i;
        }
    }
    CLR(dp, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (k & m[i])continue;
                int x = j | m[i] | k;
                if ((j & (k | m[i])) == 0 && (x == 7 || x == 4 || x == 1)) {
                    dp[i + 1][k] += dp[i][j];
                    if (dp[i + 1][k] >= MOD)dp[i + 1][k] -= MOD;
                }
            }
        }
    }
    return dp[n][0];
}

bool check(int x, int y) {
    if (x >= 0 && x < 3 && y >= 0 && y < n && a[x][y] == '.')return 0;
    return 1;
}

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    int ci, cj;
    int x[110], y[110], tot = 0;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'O')ci = i, cj = j, a[i][j] = 'X';
        }
    }
    int ans = 0;
    for (int i = 1; i < 16; i++) {
        int t = i;
        tot = 0;
        int c = 0;
        for (int j = 0; j < 4; j++) {
            if (t & 1) {
                x[tot] = dx[j];
                y[tot++] = dy[j];
                x[tot] = dx[j] * 2;
                y[tot++] = dy[j] * 2;
                c++;
            }
            t >>= 1;
        }
        bool flag = 1;
        for (int j = 0; j < tot; j++) {
            if (check(ci + x[j], cj + y[j]))flag = 0;
        }
        if (flag) {
            for (int j = 0; j < tot; j++) {
                a[ci + x[j]][cj + y[j]] = 'X';
            }
            if (c & 1)ans += gao();
            else ans -= gao();
            if (ans >= MOD)ans -= MOD;
            else if (ans < 0)ans += MOD;
            for (int j = 0; j < tot; j++) {
                a[ci + x[j]][cj + y[j]] = '.';
            }
        }
    }
    cout << ans << endl;


    return 0;
}



