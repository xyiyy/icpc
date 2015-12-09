#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/Scanner.hpp"

class hdu5391 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n;
            in >> n;
            if (check(n))out << n - 1 << endl;
            else if (n == 4)out << 2 << endl;
            else out << 0 << endl;
        }
    }

    bool check(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
};