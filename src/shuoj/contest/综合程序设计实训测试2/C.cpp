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

int a[5];
int dp[10];

int LIS(int n) {
    int i, j;
    int ans = 3;
    int m = 0;
    for (int i = 1; i < n; i++)dp[i] = 1;
    for (i = 2; i <= n; i++) {
        m = 0;
        for (j = 1; j < i; j++) {
            if (dp[j] > m && a[j] < a[i])
                m = dp[j];
        }
        dp[i] = m + 1;
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}

int LIS1(int n) {
    int i, j;
    int ans = 3;
    int m = 0;
    for (int i = 1; i < n; i++)dp[i] = 1;
    for (i = 2; i <= n; i++) {
        m = 0;
        for (j = 1; j < i; j++) {
            if (dp[j] > m && a[j] > a[i])
                m = dp[j];
        }
        dp[i] = m + 1;
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 1; i <= 5; i++) {
            cin >> a[i];
        }
        int ans = LIS(5);
        int ans1 = LIS1(5);
        cout << max(ans, ans1) << endl;
    }
    return 0;
}


