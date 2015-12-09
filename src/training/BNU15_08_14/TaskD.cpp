#include "../../xyiyy/lib.hpp"

int a[100010];

class TaskD {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        while (in >> n) {
            int sum = 0;
            rep(i, n)
            {
                in >> a[i];
                sum += a[i];
            }
            int ave = sum / n;
            if (ave * n != sum) {
                out << -1 << endl;
            } else {
                int ans = 0;
                rep(i, n)
                ans += abs(a[i] - ave);
                out << ans / 2 + 1 << endl;
            }

        }
    }
};