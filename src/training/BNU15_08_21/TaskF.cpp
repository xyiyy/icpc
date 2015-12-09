#include "../../xyiyy/lib.hpp"

int a[1010];

class TaskF {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, k;
        while (in >> n >> k) {
            k--;
            rep(i, n)
            {
                in >> a[i];
            }
            int f = 0;
            if (!k) {
                out << "Alice" << endl;
                continue;
            } else if (k == 1) {
                a[0] -= (n & 1);
            }
            if (n & 1) {
                f = a[0];
                for (int i = 1; i < n; i += 2)f ^= a[i + 1] - a[i] - 1;
            } else {
                for (int i = 0; i < n; i += 2)f ^= a[i + 1] - a[i] - 1;
            }
            if (f)out << "Alice" << endl;
            else out << "Bob" << endl;
        }
    }
};