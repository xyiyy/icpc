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
ll ten[20];

int main() {
    ios::sync_with_stdio(false);
    freopen("A-large-practice.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    ten[0] = 1LL;
    for (int i = 1; i < 16; i++) {
        ten[i] = ten[i - 1] * 10LL;
    }
    ll a[110];
    ll b[110];
    for (int i = 1; i < 16; i++) {
        b[i] = ten[i / 2] - 1 + 1 + ten[i - i / 2] - 1;
    }
    int cas = 1;
    while (t--) {
        ll n;
        cin >> n;
        cout << "Case #" << cas++ << ": ";
        ll temp = 0;
        ll ans = 0;
        temp = n;
        int len = 0;
        while (temp) {
            a[len++] = temp % 10;
            temp /= 10;
        }

        if (n % ten[len] == 0) {
            len--;
            for (int i = 0; i < len; i++)a[i] = 9;
            ans++;
        } else if (n % 10 == 0) {
            a[0] = 9;
            a[1]--;
            for (int i = 1; i < len; i++) {
                if (a[i] < 0) {
                    a[i] = 9;
                    a[i + 1]--;
                }
            }
            ans++;
        } else if (n <= 10) {
            cout << n << endl;
            continue;
        }
        int tlen = 1;
        while (tlen < len) {
            ans += b[tlen++];
        }
        ll gao1 = 0;
        a[len - 1]--;
        for (int i = 0; i < len; i++) {
            gao1 += a[i] * ten[i];
        }
        a[len - 1]++;
        ll gao2 = 0;
        for (int i = 0; i < len / 2; i++) {
            gao2 += ten[i] * a[len - 1 - i];
        }
        gao2++;
        a[0]--;
        for (int i = 0; i < len / 2; i++) {
            gao2 += ten[i] * a[i];
        }
        if (len & 1) {
            gao2 += ten[len / 2] * a[len / 2];
        }
        ans += min(gao1, gao2);
        cout << ans << endl;

    }
    return 0;
}


