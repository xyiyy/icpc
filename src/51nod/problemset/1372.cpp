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
const ll MOD = 1000000007;
const int MAXN = 100010;
vector<PII> vec[MAXN];
ll a[100010];

ll fast_mod(ll n, ll m) {
    ll ret = 1;
    while (m) {
        if (m & 1)ret = ret * n % MOD;
        n = n * n % MOD;
        m >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i < 100010; i++) {
        int temp = i;
        for (int j = 2; j * j <= temp; j++) {
            if (temp % j == 0) {
                int x = 0;
                while (temp % j == 0) {
                    temp /= j;
                    x++;
                }
                vec[i].PB(MP(j, x));
            }
        }
        if (temp != 1) {
            vec[i].PB(MP(temp, 1));
        }
    }
    int cas = 1;
    int t;
    cin >> t;
    while (t--) {

        ll n;
        cin >> n;
        CLR(a, 0);
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                int v = vec[i][j].first;
                a[v] += vec[i][j].second;
            }
        }
        ll ans = 1;
        for (ll i = 2; i <= n; i++) {
            if (a[i]) {
                ans = ans * fast_mod(i, a[i] - 1) % MOD * (i + a[i] * (i - 1)) % MOD;
            }
        }
        cout << "Case #" << cas++ << ": ";
        cout << ans << endl;


    }
    return 0;
}


