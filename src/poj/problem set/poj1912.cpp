#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/P.hpp"

const int MAXN = 100010;
P ps[MAXN];
vector <P> p;
int id[MAXN];

bool cmp(int x, int y) {
    return p[x].y * p[y].x < p[x].x * p[y].y;
}

pair <double, int> a[MAXN];

class poj1912 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        double PI = acos(-1.0);
        double MPI = -acos(-1.0) / 2;
        P t1, t2, t;
        in >> n;
        rep(i, n)
        in >> ps[i].x >> ps[i].y;
        int sz = 0;
        if (n > 1) {
            convex_hull(ps, n);
            sz = qs.size();
            qs.pb(qs[0]);
        }
        rep(i, sz)
        {
            t = qs[i + 1] - qs[i];
            a[i] = mp(atan2(t.y, t.x), i);
            while (a[i].first < MPI)a[i].first += PI * 2;
        }
        sort(a, a + sz);
        while (in >> t1.x >> t1.y >> t2.x >> t2.y) {
            if (n < 2) {
                out << "GOOD" << endl;
                continue;
            }
            t = t1 - t2;
            double angle = atan2(t.y, t.x);
            while (angle < MPI) angle += PI * 2;
            int i = upper_bound(a, a + sz, mp(angle, 0)) - a;
            t = t2 - t1;
            angle = atan2(t.y, t.x);
            while (angle < MPI) angle += PI * 2;
            int j = upper_bound(a, a + sz, mp(angle, 0)) - a;
            i = a[i].second;
            j = a[j].second;
            if (crsLS(t1, t2, qs[i], qs[j]))out << "BAD" << endl;
            else out << "GOOD" << endl;
        }
    }
};
