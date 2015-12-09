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
    ll n, a, b;
    cin >> a >> b >> n;
    while (n--) {
        ll l, t, m;
        cin >> l >> t >> m;
        ll x = (l - 1) * b + a;
        ll tmp = (t - a) / b + 1;
        cout << tmp << endl;
        if (x > t) {
            cout << -1 << endl;
            continue;
        }
        if (tmp - l + 1 <= m) {
            cout << tmp << endl;
            continue;
        }
        ll lx = (tmp - l + 1);
        ll tl = l + m - 1, tr = tmp;
        ll ans = (l + m - 1);
        //cout<<ans<<endl;
        while (tl <= tr) {
            ll mid = (tl + tr) >> 1;
            lx = (mid - l + 1);
            ll tt = lx / (2 * m);
            ll tp = lx % (2 * m);
            tmp = ((2 * m - 1) * b + 2 * a) * tt;
            tmp += (2 * tp * b + (tt - 1) * 2 * m * b) * tt / 2;
            if (tp <= m)tmp += (tp - 1) * b + a;
            else {
                tmp += ((tp - 1) * b + 2 * a) * tp / m;
            }
            //cout<<tmp<<endl;
            if (tmp <= t) {
                ans = mid;
                tl = mid + 1;
            } else tr = mid - 1;
        }
        cout << ans << endl;

    }
    return 0;
}



