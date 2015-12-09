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
ll dp[6][10019];
int a[5] = {1, 5, 10, 25, 50};

int main() {
    ios::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < 10010; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 10010; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 10010; j++) {
            for (int k = 0; k * a[i] <= j; k++) {
                dp[i][j] += dp[i - 1][j - k * a[i]];
            }
        }
    }

    int n;
    while (cin >> n) {
        int i;
        for (i = 4; i >= 0; i--) {
            if (dp[i][n] != 0)break;
        }
        cout << dp[i][n] << endl;
    }

    return 0;
}

