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
int num[110];
int dp[110][2010];

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++)cin >> num[i];
        int sum = 0;
        for (int i = 1; i <= n; i++)sum = num[i] + sum;
        CLR(dp, -1);
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (dp[i - 1][j] >= 0)dp[i][j] = dp[i - 1][j];
                if (num[i] > j && dp[i - 1][num[i] - j] >= 0)dp[i][j] = max(dp[i][j], dp[i - 1][num[i] - j] + j);
                if (j + num[i] <= sum && dp[i - 1][j + num[i]] >= 0)dp[i][j] = max(dp[i][j], dp[i - 1][j + num[i]]);
                if (j >= num[i] && dp[i - 1][j - num[i]] >= 0)dp[i][j] = max(dp[i][j], dp[i - 1][j - num[i]] + num[i]);
            }
        }
        if (dp[n][0] > 0)cout << dp[n][0] << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}


