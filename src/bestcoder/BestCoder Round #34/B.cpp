#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <functional>
#include <ios>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
#define MAXN 100010
int a[MAXN];
ll s[MAXN];
ll dp[MAXN];
ll bit[MAXN];
ll dp2[MAXN];
int n;

ll getsum(int x) {
    ll ret = 0;
    while (x >= 0) {
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}

void add(int i, ll x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int w, h;
    while (scanf("%d%d%d", &n, &w, &h) != EOF) {
        ll sum = (ll) w * h;
        ll tot = 0;
        for (int i = 0; i <= n; i++)s[i] = dp[i] = dp2[i] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            tot += a[i];
            if (i)s[i] = s[i - 1] + a[i];
            else s[i] = a[i];
        }
        if (tot < sum) {
            cout << "-1" << endl;
            continue;
        }
        // for(int i=0;i<=n;i++)cout<<dp[i]<<"  "<<dp2[i]<<endl;
        for (int i = 0; i < n; i++) {
            b[i] = a[i] - h;
            //cout<<b[i]<<endl;
            if (b[i] >= 0) { dp[i + 1] += dp[i] + b[i], dp2[i + 1] = dp2[i]; }
            else { dp2[i + 1] += dp2[i] + abs(b[i]), dp[i + 1] = dp[i]; }//cout<<b[i]<<endl;}
            //  cout<<dp[i+1]<<"  "<<dp2[i]<<endl;
        }
        // for(int i=0;i<=n;i++)cout<<dp[i]<<"  "<<dp2[i]<<endl;
//        for()
        ll ans = 1e12;
        for (int i = 0; i < n - w + 1; i++) {
            ans = min(ans, max(abs(dp[i + w] - dp[i]), dp2[i + w] - dp2[i]));
        }
        //cout<<ans<<endl;
        for (int i = 0; i < w; i++) {
            ans = min(tot - (ll) (i + 1) * h + max(abs(dp[i + 1]), dp2[i + 1]), ans);
        }
        //cout<<ans<<endl;
        for (int i = n - w + 1; i < n; i++) {
            ans = min(ans, (tot - (ll) (n - i) * h) + max(abs(dp[n] - dp[i + 1]), dp2[n] - dp2[i + 1]));
        }
        cout << ans << endl;


    }
    return 0;
}
