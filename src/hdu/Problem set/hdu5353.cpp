#include "../../xyiyy/libhdug++.hpp"

#define gao() out<<"NO"<<endl
int a[100010];

class hdu5353 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        rep(i, n)
        in >> a[i];
        ll tot = 0;
        rep(i, n)
        tot += a[i];
        if (tot % n != 0) {
            gao();
            return;
        }
        int ok = 1;
        int ave = tot / n;
        VII v;
        rep(i, n)
        {
            a[i] -= ave;
            if (a[i] < -2 || a[i] > 2)ok = 0;
            else if (a[i] == -1 || a[i] == 1)v.pb(mp(a[i], i));
            else if (a[i] == -2 || a[i] == 2)v.pb(mp(a[i] / 2, i)), v.pb(mp(a[i] / 2, i));
        }
        if (!ok) {
            gao();
            return;
        }
        int sz = v.size();
        if (sz & 1) {
            gao();
            return;
        }
        int st = 0;
        rep(i, sz)
        {
            if (v[(i + sz - 1) % sz].first == v[i].first)st = i;
        }
        int e = st;
        VII ans;
        if (sz) {
            while (1) {
                int a = v[st].first, b = v[(st + 1) % sz].first;
                int l = v[st].second, r = v[(st + 1) % sz].second;
                if (a == b) {
                    ok = 0;
                    break;
                } else if (a == 1) {
                    for (; l != r; (l += 1) %= n)ans.pb(mp(l, (l + 1) % n));
                } else {
                    for (; r != l; (r += n - 1) %= n)ans.pb(mp(r, (r + n - 1) % n));
                }
                (st += 2) %= sz;
                if (st == e)break;
            }
        }
        if (!ok) {
            gao();
            return;
        }
        out << "YES" << endl << ans.size() << endl;
        rep(i, ans.size())
        {
            out << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }
    }
};