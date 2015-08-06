#include "../../../../library/lib.hpp"
#include "../../../../library/algo/math/quick_power.hpp"
class hdu5363 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			in>>n;
            ll mod = 1e9+7;
            out<<(quick_power(2,n-1,1e9+7) - 1 + mod )%mod <<endl;
		}
};