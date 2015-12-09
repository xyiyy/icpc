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
const int maxn = 110;
double a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int h, r, T;
        cin >> n >> h >> r >> T;
        int time;
        for (int i = 0; i < n; i++) {
            time = T - i;
            if (time < 0) {
                a[i] = h;
                continue;
            }
            double t = sqrt(2.0 * h / 10.0);
            int k = (int) (time / t);
            if (k % 2 == 0) {
                a[i] = h - 0.5 * 10 * (time - k * 1.0 * t) * (time - k * 1.0 * t);
            }
            else {
                a[i] = h - 0.5 * 10 * (time - k * 1.0 * t - t) * (time - k * 1.0 * t - t);
            }

        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (i)cout << " ";
            cout << fixed << setprecision(2) << a[i] + 2 * r * (i * 1.0) / 100.0;
        }
        cout << endl;
    }


    return 0;
}
