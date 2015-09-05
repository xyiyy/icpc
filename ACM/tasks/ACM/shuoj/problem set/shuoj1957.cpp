#include "../../xyiyy/lib.hpp"

class shuoj1957 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n;
            in >> n;
            int m = n;
            int ans = 0;
            if (n & 1) {
                ans = n * n - (n - 1);
                ans /= 4;
            } else {
                m = n % 12;
                ans = n * n - m * m - 16 * (n / 12);
                ans /= 4;
                if (m == 0);
                else if (m == 2);
                else if (m == 4)ans += 3;
                else if (m == 6)ans += 7;
                else if (m == 8)ans += 13;
                else if (m == 10)ans += 22;
            }
            out << ans << endl;
        }
    }
};