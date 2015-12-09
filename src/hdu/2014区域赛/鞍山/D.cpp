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
const int maxn = 50010;
ll sum[maxn];
ll sum2[maxn];
ll a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int t;
    int n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];

        }

        if (n <= k) {
            cout << 0 << endl;
            continue;
        }
        sort(a, a + n);
        sum[0] = sum2[0] = 0;
        for (int i = 1; i <= n; i++) {
            //if(i)
            //{
            sum[i] = sum[i - 1] + a[i - 1];
            sum2[i] = sum2[i - 1] + a[i - 1] * a[i - 1];
            //}
            //else
            //{
            //		sum2[i]=a[i]*a[i];
            //		sum[i]=a[i];
            //	}
        }
        long double ans = 1e18;
        for (int i = 0; i <= k; i++) {
            ll temp = sum[n - k - i] - sum[i];
            ll temp2 = sum2[n - k - i] - sum2[i];

            long double x = temp * 1.0 / (n - k) * 1.0;
            long double s = temp2 + (n - k) * x * x - 2 * temp * x;
            if (s - ans < -(1e-12))ans = s;
        }
        cout << fixed << setprecision(12) << ans << endl;
    }


    return 0;
}



