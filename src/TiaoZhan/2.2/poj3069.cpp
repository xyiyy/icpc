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
int a[1010];

int main() {
    ios::sync_with_stdio(false);
    int r, n;
    while (cin >> r >> n && (n != -1 || r != -1)) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int i = 0;
        int ans = 0;
        while (i < n) {
            int p = a[i];
            while (a[i + 1] <= p + r && i + 1 < n)i++;
            p = a[i];
            while (a[i] <= p + r && i < n)i++;
            ans++;
        }
        cout << ans << endl;
    }


    return 0;
}

