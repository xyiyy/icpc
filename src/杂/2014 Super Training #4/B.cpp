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
int dp[1 << 13][510];
int a[20][20];
int ini[13];

int GCD(int x, int y) {
    int t;
    while (y > 0) {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    ini[0] = 1;
    for (int i = 1; i < 13; i++) {
        ini[i] = ini[i - 1] * i;
    }
    int n, num, tot;
    cin >> T;
    while (T--) {
        cin >> n >> num;
        tot = (1 << n) - 1;
        CLR(a, 0);
        //	CLR(dp,0);
        for (int j = 0; j <= tot; j++) {
            for (int k = 0; k <= num; k++) {
                dp[j][k] = 0;
            }
        }
        dp[0][0] = 1;
        REP(i, n) {
            REP(j, n) {
                cin >> a[i][j];
            }
        }
        int s, w, i, j, k, t, temp;
        REP(i, n) {
            if (i == 0) {
                j = k = 0;
                for (int p = 0; p < n; p++) {
                    if (j & (1 << p))continue;
                    s = j | (1 << p);
                    w = min(num, k + a[i][p]);
                    dp[s][w] += dp[j][k];
                }
            }
            else {
                for (j = tot; j >= 0; j--) {
                    t = 0;
                    temp = j;
                    while (temp) {
                        if (temp & 1)t++;
                        temp >>= 1;
                    }
                    if (t != i)continue;


                    for (k = 0; k <= num; k++) {
                        if (!dp[j][k])continue;
                        for (int p = 0; p < n; p++) {
                            if (j & (1 << p))continue;
                            s = j | (1 << p);
                            w = min(num, k + a[i][p]);
                            dp[s][w] += dp[j][k];
                        }
                    }
                }
            }
        }
        if (dp[tot][num]) {
            int num1 = ini[n];
            int num2 = dp[tot][num];
            int gcd = GCD(num1, num2);
            cout << ini[n] / gcd << "/" << dp[tot][num] / gcd << endl;
        }
        else {
            cout << "No solution" << endl;
        }
    }
    return 0;
}


