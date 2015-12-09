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

int a[110];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        int temp = m;
        if (m > 9 * n || (m < 1 && n != 1))cout << -1 << " " << -1 << endl;
        else {
            for (int i = n; i > 0; i--) {
                if (m - 9 > 0) {
                    a[i] = 9;
                    m -= 9;
                }
                else if (i != 1) {
                    a[i] = m - 1;
                    m = 1;
                }
                else {
                    a[i] = m;
                }
            }
            for (int i = 1; i <= n; i++) {
                cout << a[i];
            }
            cout << " ";
            m = temp;
            for (int i = 1; i <= n; i++) {
                if (m > 9)a[i] = 9;
                else a[i] = m;
                m -= a[i];
            }
            for (int i = 1; i <= n; i++) {
                cout << a[i];
            }
            cout << endl;
        }
    }
    return 0;
}



