#include "../../xyiyy/lib.hpp"

#define X first
#define Y second
const int MAXN = 400010;
pair <pair<ll, ll>, ll> p[MAXN];
ll y[MAXN << 1];
ll sum[MAXN << 1], lx[MAXN << 1], rx[MAXN << 1], mx[MAXN << 1];

void build(int l, int r, int cur) {
    sum[cur] = 0;
    lx[cur] = rx[cur] = mx[cur] = -INF;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur << 1);
    build(mid + 1, r, cur << 1 | 1);
}

void push_up(int r, int x) {
    sum[r] += x;
    lx[r] = max(lx[r << 1], sum[r << 1] + lx[r << 1 | 1]);
    rx[r] = max(rx[r << 1 | 1], sum[r << 1 | 1] + rx[r << 1]);
    mx[r] = max(rx[r << 1] + lx[r << 1 | 1], max(mx[r << 1], mx[r << 1 | 1]));
}

void update(int x, ll inc, int l, int r, int cur) {
    if (l == r) {
        sum[cur] += inc;
        lx[cur] = rx[cur] = sum[cur];
        mx[cur] = sum[cur];
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)update(x, inc, l, mid, cur << 1);
    else update(x, inc, mid + 1, r, cur << 1 | 1);
    push_up(cur, inc);
}

class poj2482 {
public:
    void solve(std::istream &in, std::ostream &out) {
        ll n, w, h;
        while (in >> n >> w >> h) {
            ll u, v, z;
            rep(i, n)
            {
                in >> u >> v >> z;
                p[i] = mp(mp(u, v), z);
                y[i << 1] = p[i].X.Y;
                y[i << 1 | 1] = p[i].X.Y + h;
            }
            sort(p, p + n);
            int m = n + n;
            sort(y, y + m);
            m = unique(y, y + m) - y;
            build(1, m, 1);
            ll ans = 0;
            int j = 0;
            rep(i, n)
            {
                while (j < i && p[j].X.X + w <= p[i].X.X) {
                    int x = lower_bound(y, y + m, p[j].X.Y) - y + 1;
                    update(x, -p[j].Y, 1, m, 1);
                    x = lower_bound(y, y + m, p[j].X.Y + h) - y + 1;
                    update(x, p[j].Y, 1, m, 1);
                    j++;
                }
                int x = lower_bound(y, y + m, p[i].X.Y + h) - y + 1;
                update(x, -p[i].Y, 1, m, 1);
                x = lower_bound(y, y + m, p[i].X.Y) - y + 1;
                update(x, p[i].Y, 1, m, 1);
                ans = max(ans, mx[1]);
            }
            out << ans << endl;
        }
    }
};