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

int a[2010], b[2010];
int dp[2010];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        CLR(dp, 0);
        sort(b, b + n);
        int minn = 0;
        for (int i = 0; i < n; i++) {
            minn = dp[0];
            for (int j = 0; j < n; j++) {
                minn = min(minn, dp[j]);
                dp[j] = minn + abs(a[i] - b[j]);
            }
        }
        int ans = dp[0];
        for (int i = 0; i < n; i++) {
            ans = min(dp[i], ans);
        }
        sort(b, b + n, cmp);
        CLR(dp, 0);
        for (int i = 0; i < n; i++) {
            minn = dp[0];
            for (int j = 0; j < n; j++) {
                minn = min(dp[j], minn);
                dp[j] = minn + abs(a[i] - b[j]);
            }
        }
        for (int i = 0; i < n; i++) {
            ans = min(dp[i], ans);
        }
        cout << ans << endl;
    }


    return 0;
}


