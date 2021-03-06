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
int a[100010];
int dp[100010];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int cas = 1;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = a[i] - i;
        }
        fill(dp, dp + n, INF);
        for (int i = 0; i < n; i++) {
            *upper_bound(dp, dp + n, a[i]) = a[i];
        }
        int len = lower_bound(dp, dp + n, INF) - dp;
        cout << "Case #" << cas++ << ":" << endl;
        cout << n - len << endl;

    }
    return 0;
}

