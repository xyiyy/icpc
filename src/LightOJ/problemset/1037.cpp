//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
int a[110];
string str[110];
int n;
int dp[(1 << 15) + 10];

int cal(int x, int m) {
    int tmp = 1;
    for (int i = 0; i < n; i++) {
        if (x & (1 << i)) {
            tmp = max(tmp, str[i][m] - '0');
        }
    }
    return (a[m] + tmp - 1) / tmp;
}

int dfs(int x, int m) {
    if (m == 0)return 0;
    if (dp[x] != INF)return dp[x];
    // cout<<m<<endl;
    for (int i = 0; i < n; i++) {
        if ((1 << i) & x)
            dp[x] = min(dp[x], dfs(x ^ (1 << i), m - 1) + cal(x ^ (1 << i), i));
    }
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)cin >> a[i];
        for (int i = 0; i < n; i++)cin >> str[i];
        int tot = 1 << n;
        for (int i = 0; i < tot; i++) {
            dp[i] = INF;
        }
        cout << "Case " << cas++ << ": " << dfs(tot - 1, n) << endl;

    }
    return 0;
}
