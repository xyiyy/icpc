#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/P.hpp"

P ps[1010];

class poj1113 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, l;
        while (in >> n >> l) {
            rep(i, n) {
                in >> ps[i].x >> ps[i].y;
            }
            convex_hull(ps, n);
            double ans = 2.0 * acos(-1.0) * l;
            qs.pb(qs[0]);
            rep(i, qs.size()) {
                if (i == qs.size() - 1)break;
                ans += (qs[i + 1] - qs[i]).abs();
            }
            out << fixed << setprecision(0) << ans << endl;
        }
    }
};