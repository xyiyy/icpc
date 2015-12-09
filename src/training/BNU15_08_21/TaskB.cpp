#include "../../xyiyy/lib.hpp"

ll x[100010], y[100010], ans[100010];
int p[100010];

bool cmpx(int i, int j) {
    return x[i] < x[j];
}

bool cmpy(int i, int j) {
    return y[i] < y[j];
}

class TaskB {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n;
            in >> n;
            ll totx = 0, toty = 0;
            rep2(i, 1, n)
            {
                in >> x[i] >> y[i];
                totx += x[i];
                toty += y[i];
            }
            rep2(i, 1, n)
            p[i] = i;
            sort(p + 1, p + n + 1, cmpx);
            ll tot = 0;
            rep2(i, 1, n)
            {
                ans[p[i]] = totx - tot - (ll)(n - i + 1) * x[p[i]] + x[p[i]] * (i - 1) - tot;
                tot += x[p[i]];
            }
            rep2(i, 1, n)
            p[i] = i;
            sort(p + 1, p + n + 1, cmpy);
            tot = 0;
            rep2(i, 1, n)
            {
                ans[p[i]] += toty - tot - (ll)(n - i + 1) * y[p[i]] + y[p[i]] * (i - 1) - tot;
                tot += y[p[i]];
            }
            ll res = 1LL << 60;
            rep2(i, 1, n)
            res = min(res, ans[i]);
            out << res << endl;
        }
    }
};