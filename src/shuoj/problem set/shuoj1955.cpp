#include "../../xyiyy/lib.hpp"

class shuoj1955 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            long long n;
            in >> n;
            n--;
            int ans = (sqrt(8 * n + 1.0) - 1) / 2;
            if (ans * (ans + 1) / 2 == n)out << 2 << endl;
            else out << 3 << endl;
        }
    }
};