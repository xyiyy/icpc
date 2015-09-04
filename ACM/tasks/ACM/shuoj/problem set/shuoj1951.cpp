#include "../../xyiyy/lib.hpp"

int num[1010];

class shuoj1951 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n, k;
            in >> n >> k;
            clr(num, 0);
            int p, a;
            int tot = 0;
            rep(i, n) {
                in >> p >> a;
                num[p] += a;
                tot += a;
            }
            int ans = 0;
            int i = 1000;
            int now = k;
            while (tot--) {
                while (num[i] == 0)i--;
                num[i]--;
                if (now == k) {
                    ans += 2 * i;
                    now = 0;
                }
                now++;
            }
            out << ans << endl;
        }
    }
};