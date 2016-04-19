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
const double eps = 1e-8;

bool check(double a, double b) {
    if (fabs(a - b) <= eps)return 1;
    return 0;
}

double c[110], r[110];

int main() {
    ios::sync_with_stdio(false);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int t;
    int cas = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        double v, x;
        cin >> v >> x;
        double v0, v1;
        for (int i = 0; i < n; i++)cin >> r[i] >> c[i];
        cout << "Case #" << cas++ << ": ";
        if (check(c[0], c[1]) && check(c[0], x)) {
            double ans = v / (r[0] + r[1]);
            cout << fixed << setprecision(10) << ans << endl;
        } else {
            if (check(c[0], c[1])) {
                cout << "IMPOSSIBLE" << endl;
            } else {
                if (x > c[0] && x > c[1]) {
                    cout << "IMPOSSIBLE" << endl;
                    continue;
                }
                if (x < c[0] && x < c[1]) {
                    cout << "IMPOSSIBLE" << endl;
                    continue;
                }
                v1 = v * (x - c[0]) / (c[1] - c[0]);
                v0 = v - v1;

                cout << fixed << setprecision(10) << max(v0 / r[0], v1 / r[1]) << endl;
            }
        }
    }
    return 0;
}


