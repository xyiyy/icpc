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
double a[110];
double b[110];

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1)b[0] = a[0];
        else {
            for (int i = 0; i < n; i++) {
                if (i == 0)b[0] = (a[0] + b[0]) / 2;
                else if (i == n - 1)b[n - 1] = (a[n - 2] + a[n - 1]) / 2;
                else {
                    b[i] = (b[i] + b[i - 1] + b[i + 1]) / 3;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            b[i] *= 1000;
        }
        for (int i = 0; i < n; i++) {
            cout << (int) b[i] / 1000 << "." << ((int) b[i] / 100) % 10;
            if ((int) b[i] % 100 >= 50)cout << (((int) b[i] / 10) % 10) + 1 << endl;
            else cout << (((int) b[i] / 10) % 10) << endl;
        }

    }
    return 0;
}

