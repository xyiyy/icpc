#include <../../xyiyy/lib.hpp>

class Chef_and_the_stones {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            ll n1, n2, k;
            in >> n1 >> n2 >> k;
            ll tmp = (1 + k) * k / 2;
            ll minn = min(n1, n2);
            ll ans;
            if (tmp < minn) {
                ans = n1 - tmp - tmp + n2;
            } else {
                ans = max(n1, n2) - min(n1, n2);
            }
            out << ans << endl;
        }
    }
};
