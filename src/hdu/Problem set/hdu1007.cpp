#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/Closest_Pair.hpp"

class hdu1007 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        while (in >> n && n) {
            rep(i, n)
            in >> p[i].x >> p[i].y;
            Closest_Pair_init(n);
            double ans = Closest_Pair(0, n - 1) / 2;
            out << fixed << setprecision(2) << ans << endl;
        }
    }
};