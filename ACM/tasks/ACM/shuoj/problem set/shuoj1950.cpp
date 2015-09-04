#include "../../xyiyy/lib.hpp"

class shuoj1950 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n, m;
            in >> n >> m;
            if ((n & 1) && (m & 1)) {
                out << -1 << endl;
                continue;
            }
            if (n == 1 && m == 2) {
                out << "RL" << endl;
                continue;
            } else if (n == 2 && m == 1) {
                out << "DU" << endl;
                continue;
            } else if (n == 1 || m == 1) {
                out << -1 << endl;
                continue;
            }
            rep(i, m - 1)out << "R";
            rep(i, n - 1)out << "D";
            if (m % 2 == 0) {
                rep(i, m - 1) {
                    out << "L";
                    if (i & 1) {
                        rep(j, n - 2)out << "D";
                    } else {
                        rep(j, n - 2)out << "U";
                    }
                }
                out << "U";
                out << endl;
            } else {
                out << "L";
                rep(i, n - 1) {
                    if (i & 1) {
                        rep(j, m - 2)out << "R";
                    } else
                        rep(j, m - 2)out << "L";
                    out << "U";
                }
                out << endl;
            }
        }
    }
};