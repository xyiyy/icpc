#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/math/single_Eular.hpp"

class poj2407 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        while (in >> n && n) {
            out << Eular(n) << endl;
        }
    }
};