//gaoshenbaoyou  ------ pass system test
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
const double pai = 3.1415926535898;

int main() {
    ios::sync_with_stdio(false);
    double a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        double fenz = sin((b + c + d) / 180 * pai);
        //cout<<fenz<<endl;
        double x = sin(d / 180 * pai) * sin((a + b) / 180 * pai) / (sin(a / 180 * pai) * sin(c / 180 * pai)) -
                   cos((180 - b - c - d) / 180 * pai);
        double ans = atan(fenz / x);
        ans = (ans / pai * 180);
        if (ans < -1e-6)ans += 180;
        cout << fixed << setprecision(2) << ans << endl;

    }
    return 0;
}



