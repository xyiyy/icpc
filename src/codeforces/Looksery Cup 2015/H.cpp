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

bool gao(double a, double b, double c, double d, double x) {
    double m1 = max((a + x) * (d + x), (a - x) * (d - x));
    double m2 = max((b + x) * (c + x), (b - x) * (c - x));
    double tx1, tx2;
    if (fabs(x) >= min(fabs(a), fabs(d))) {
        tx1 = 0;
    } else {
        if (a > 0)a -= x;
        else a += x;
        if (d > 0)d -= x;
        else d += x;
        tx1 = a * d;
    }
    if (fabs(x) >= min(fabs(b), fabs(c))) {
        tx2 = 0;
    } else {
        if (b > 0)b -= x;
        else b += x;
        if (c > 0)c -= x;
        else c += x;
        tx2 = b * c;
    }
    return max(tx1, tx2) <= min(m1, m2);
}

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double l = 0, r = 1e9;
    for (int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2.0;
        if (gao(a, b, c, d, mid) || gao(-a, -b, c, d, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(11) << l << endl;
    return 0;
}
