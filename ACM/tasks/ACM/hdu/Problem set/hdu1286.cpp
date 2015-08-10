#include "../../../../library/lib.hpp"
#include "../../../../library/algo/math/single_Eular.hpp"
class hdu1286 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			in>>n;
			out<<Eular(n)<<endl;
		}
};