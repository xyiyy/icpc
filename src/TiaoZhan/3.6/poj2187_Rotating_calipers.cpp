#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/P.hpp"

const int MAXN = 50010;
P ps[MAXN];

//should use scanf and printf
class poj2187_Rotating_calipers {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        rep(i, n)
        {
            in >> ps[i].x >> ps[i].y;
        }
        convex_hull(ps, n);
        double ans = convexDiameter();
        out << ans * ans << endl;
    }
};