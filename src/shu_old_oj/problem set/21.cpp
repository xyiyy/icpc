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

int main() {
    ios::sync_with_stdio(false);
    double a, b;
    double c, d;
    double m;
    int cas = 1;
    while (cin >> a >> b) {
        cout << "Case " << cas++ << ": ";
        int flag = 0;
        while (!flag) {
            c = a;
            d = b;
            m = a * a * a * a + b * b * b * b + 2 * a * a * b * b;
            m = m * 3.0;
            b = d - (c * c * c * c * d + 2 * c * c * d * d * d + 2 * c * d + d * d * d * d * d) / m;
            a = c - (c * c * c * c * c + 2 * c * c * c * d * d + c * d * d * d * d - c * c + d * d) / m;
            if ((fabs(a - 1.0) <= 1e-3 && fabs(b) <= 1e-3)) {
                flag = 1;
                break;
            }
            if (fabs(a + 0.5) <= 1e-3 && fabs(b - sqrt(3.0) / 2) <= 1e-3) {
                flag = 2;
                break;
            }
            if (fabs(a + 0.5) <= 1e-3 && fabs(b + sqrt(3.0) / 2) <= 1e-3) {
                flag = 3;
                break;
            }

        }
        cout << flag - 1 << endl;
    }
    return 0;
}


