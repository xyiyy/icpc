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

//#define ll long long

ll dp[1000][1000];

ll C(int m, int n) {
    if (m < 1000 && n < 1000 && dp[m][n]) return dp[m][n];
    if (m == n || n == 0)return 1;
    if (n == 1) return m;
    ll ret = C(m - 1, n - 1) * m / n;
    if (m < 1000 && n < 1000)dp[m][n] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int m, n, k = 1;
    while (cin >> m >> n) {
        memset(dp, 0, sizeof(dp));
        if (n <= m)
            cout << "Case " << k++ << ": " << "C(" << m << ", " << n << ") = " << C(m, n) << endl;
        else cout << "Case " << k++ << ": " << "C(" << m << ", " << n << ") = " << 0 << endl;
    }
    return 0;
}

