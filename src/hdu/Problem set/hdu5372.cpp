#include "../../xyiyy/lib.hpp"

const int MAXN = 400010;
int bit0[MAXN + 1], bit1[MAXN + 1];
int a[MAXN], l[MAXN], r[MAXN];
//map<int,int>ms;
const int N = MAXN;
//map<int,int>mm;
int c[MAXN];
int d[MAXN];

int query(int *b, int i) {
    int s = 0;
    while (i > 0) {
        s += b[i];
        i -= (i & -i);
    }
    return s;
}

void add(int *b, int i, int v) {
    while (i <= N) {
        b[i] += v;
        i += (i & -i);
    }
}

int tmp[MAXN];
int tmp2[MAXN];

class hdu5372 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        int cas = 1;
        while (in >> n) {
            out << "Case #" << cas++ << ":" << endl;
            int num = 0, cnt = 0;
            rep(i, n)
            {
                in >> a[i] >> l[i];
                if (!a[i]) {
                    num++;
                    tmp[cnt++] = l[i];
                    tmp[cnt++] = l[i] + num;
                }
                r[i] = l[i] + num;
            }
            sort(tmp, tmp + cnt);
            cnt = unique(tmp, tmp + cnt) - tmp;
            num = 1;
            clr(bit0, 0);
            clr(bit1, 0);
            rep(i, n)
            {
                if (!a[i]) {
                    c[num] = lower_bound(tmp, tmp + cnt, l[i]) - tmp + 2;
                    d[num] = lower_bound(tmp, tmp + cnt, r[i]) - tmp + 2;
                    int ans = query(bit1, d[num]) - query(bit0, c[num] - 1);
                    out << ans << endl;
                    add(bit0, c[num], 1);
                    add(bit1, d[num], 1);
                    num++;
                } else {
                    add(bit0, c[l[i]], -1);
                    add(bit1, d[l[i]], -1);
                }
            }
        }

    }
};