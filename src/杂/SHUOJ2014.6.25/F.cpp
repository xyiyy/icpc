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

int f[3000];

int main() {
    ios::sync_with_stdio(false);
    int n, i, j, c;
    while (cin >> n) {
        CLR(f, 0);
        f[0] = 1;
        for (i = 2; i <= n; i++) {
            c = 0;
            for (j = 0; j < 3000; j++) {
                int s = f[j] * i + c;
                f[j] = s % 10;
                c = s / 10;
            }
        }
        cout << n << "!=" << endl;
        for (j = 2000; j >= 0; j--)if (f[j])break;
        int k = 0;
        for (i = j; i >= 0; i--) {
            k++;
            cout << f[i];
            if (k % 80 == 0)
                cout << endl;
        }
        if (k % 80 != 0)
            cout << endl;
    }
    return 0;
}


