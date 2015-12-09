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
double a[3];

int main() {
    ios::sync_with_stdio(false);
    int k = 1;
    double p, l, s;
    while (cin >> a[0] >> a[1] >> a[2]) {
        cout << "Case " << k++ << ": ";
        //sort(a,a+3);
        if (a[0] + a[1] <= a[2] || a[0] <= 0 || a[2] <= 0) {
            cout << "不能构成三角形" << endl;
        }
        else {
            l = 0;
            for (int i = 0; i < 3; i++) {
                l += a[i];
            }
            p = l / 2.0;
            s = sqrt(1.0 * p * (p - a[0]) * (p - a[1]) * (p - a[2]));
            cout << l << ", " << s << endl;
        }
    }

    return 0;
}

