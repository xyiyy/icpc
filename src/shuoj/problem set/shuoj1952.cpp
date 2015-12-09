#include "../../xyiyy/lib.hpp"

const int MAXN = 100010;
int eve[MAXN], odd[MAXN], a[MAXN];

class shuoj1952 {
public:
    void solve() {
        int t;
        scanf("%d", &t);//in >> t;
        while (t--) {
            int n, q;
            scanf("%d%d", &n, &q);//in >> n >> q;
            rep2(i, 1, n) {
                scanf("%d", &a[i]);//in >> a[i];
            }
            rep2(i, 1, n) {
                if (a[i] & 1)odd[i] = odd[i - 1] + 1, eve[i] = eve[i - 1];
                else eve[i] = eve[i - 1] + 1, odd[i] = odd[i - 1];
            }
            int l, r;
            ll x, y;
            ll ans = 0;
            rep(i, q) {
                scanf("%d%d", &l, &r);//in >> l >> r;
                x = eve[r] - eve[l - 1];
                y = odd[r] - odd[l - 1];
                ans = x * y;
                printf("%lld\n", ans);//out << ans << endl;
            }
        }
    }
};