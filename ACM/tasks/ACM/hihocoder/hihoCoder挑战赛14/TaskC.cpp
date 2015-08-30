#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/P.hpp"

P p[1010][2];

class TaskC {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        rep(i, n)
            rep(j, 2)in >> p[i][j].x >> p[i][j].y;
        double ans = 0;
        rep(i, n)
            rep(l1, 2) {
                P p1 = p[i][l1];
                rep(j, n) {
                    if (i == j)continue;
                    rep(l2, 2) {
                        P p2 = p[j][l2];
                        double sum = p1.Det(p2) * 0.125;
                        p2 = p2 - p1;
                        rep(k, n) {
                            if (i == k || j == k)continue;
                            if (sig(sum) == 0)break;
                            int l = 0, r = 0;
                            rep(l3, 2) {
                                if (p2.Det(p[k][l3] - p1) > 0)l++;
                                else r++;
                            }
                            if (l == 2)sum = 0;
                            else if (l == 1)sum *= 0.5;
                            //else sum = sum;
                        }
                        ans += sum;
                    }
                }
            }
        out << fixed << setprecision(10) << fabs(ans) << endl;
    }
};