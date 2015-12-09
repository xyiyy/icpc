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
int v[110], num[110];
int dp[100010];
int use[100010];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m && (n || m)) {
        CLR(dp, 0);
        dp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int j = 0; j < n; j++) {
            cin >> num[j];
        }
        for (int i = 0; i < n; i++) {
            CLR(use, 0);
            for (int j = v[i]; j <= m; j++) {
                if (!dp[j] && dp[j - v[i]] && use[j - v[i]] < num[i]) {
                    dp[j] = 1;
                    ans++;
                    use[j] = use[j - v[i]] + 1;
                }

            }
        }
        cout << ans << endl;
    }


    return 0;
}


