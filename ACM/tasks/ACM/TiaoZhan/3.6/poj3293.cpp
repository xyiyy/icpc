#include "../../xyiyy/lib.hpp"
int x[100010], y[100010], p[100010];
int tot = 0;

bool cmp1(int i, int j) {
    if (x[i] == x[j])return y[i] < y[j];
    return x[i] < x[j];
}

bool cmp2(int i, int j) {
    if (y[i] == y[j])return x[i] < x[j];
    return y[i] < y[j];
}

int con[100010][2];
pair<int, PII> gao[100010];

bool check(int a, int b) {
    int ynow = y[a];
    int tx = x[a], gx = x[b];
    rep(i, tot) {
        if (tx < gao[i].first && gx > gao[i].first && gao[i].second.first < ynow && gao[i].second.second > ynow)
            return true;
    }
    return false;
}

class poj3293 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n;
            tot = 0;
            in >> n;
            rep(i, n)in >> x[i] >> y[i];
            rep(i, n)p[i] = i;
            sort(p, p + n, cmp1);
            int ans = 0;
            int f = 0;
            int num = 1;
            rep2(i, 1, n - 1) {
                if (f)break;
                if (x[p[i]] != x[p[i - 1]]) {
                    f = (num & 1);
                    num = 1;
                } else {
                    num++;
                    if (!(num & 1)) {
                        ans += y[p[i]] - y[p[i - 1]];
                        con[p[i]][0] = p[i - 1];
                        con[p[i - 1]][0] = p[i];
                        gao[tot++] = mp(x[p[i]], mp(y[p[i - 1]], y[p[i]]));
                    }
                }
            }
            num = 1;
            rep(i, n)p[i] = i;
            sort(p, p + n, cmp2);
            rep2(i, 1, n - 1) {
                if (f)break;
                if (y[p[i]] != y[p[i - 1]]) {
                    f = (num & 1);
                    num = 1;
                } else {
                    num++;
                    if (!(num & 1)) {
                        ans += x[p[i]] - x[p[i - 1]];
                        con[p[i]][1] = p[i - 1];
                        con[p[i - 1]][1] = p[i];
                        if (check(p[i - 1], p[i]))f = 1;
                    }
                }
            }
            int now = 0;
            num = 0;
            int c = 0;
            do {
                c ^= 1;
                now = con[now][c];
                num++;
            } while (now && !f);
            if (num != n)f = 1;
            if (f)ans = -1;
            out << ans << endl;
        }
    }
};