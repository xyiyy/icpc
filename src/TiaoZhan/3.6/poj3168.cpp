#include "../../xyiyy/lib.hpp"

vector <pair<PII, PII>> x, y;
vector <bool> ok;
#define X first
#define Y second
#define mmp(A, B, C, D) mp(mp(A,B),mp(C,D))

//should use scanf
class poj3168 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        x.resize(n * 4);
        y.resize(n * 4);
        ok.resize(n);
        int a, b, c, d;
        rep(i, n)
        {
            in >> a >> b >> c >> d;
            x[i * 4] = mmp(a, b, 0, i);
            x[i * 4 + 1] = mmp(a, d, 1, i);
            x[i * 4 + 2] = mmp(c, b, 0, i);
            x[i * 4 + 3] = mmp(c, d, 1, i);
            y[i * 4] = mmp(b, a, 0, i);
            y[i * 4 + 1] = mmp(b, c, 1, i);
            y[i * 4 + 2] = mmp(d, a, 0, i);
            y[i * 4 + 3] = mmp(d, c, 1, i);
            ok[i] = 1;
        }
        sort(ALL(x));
        sort(ALL(y));
        int now = 0, num = 0, m = x.size(), pre = -1;
        int f = 0;
        while (now < m) {
            pre = x[now].X.X;
            while (now < m && x[now].X.X == pre) {
                if (f) ok[x[now].Y.Y] = 0;
                if (!x[now].Y.X) {
                    num++;
                    if (num > 1)f = 1;
                } else {
                    num--;
                    if (!num)f = 0;
                }
                now++;
            }
        }
        now = 0, num = 0, pre = -1, f = 0;
        while (now < m) {
            pre = y[now].X.X;
            while (now < m && y[now].X.X == pre) {
                if (f) ok[y[now].Y.Y] = 0;
                if (!y[now].Y.X) {
                    num++;
                    if (num > 1)f = 1;
                } else {
                    num--;
                    if (!num)f = 0;
                }
                now++;
            }
        }
        out << count(ALL(ok), 1) << endl;
    }
};