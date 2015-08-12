#include "../../../../library/libhdug++.hpp"
#include "../../../../library/algo/math/quick_power.hpp"
class shuoj1942 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int a,b,k;
			while(in>>a>>b>>k){
                int ans = (ll)a*quick_power(2, k, a+b) % (a + b);
                out<<min(ans, a+b-ans)<<endl;
			}
		}
};