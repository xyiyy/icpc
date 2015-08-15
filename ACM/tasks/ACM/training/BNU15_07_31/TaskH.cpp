#include "../../xyiyy/lib.hpp"
const ll MOD = 1000000007;

#include "../../xyiyy/math/quick_power.hpp"
class TaskH {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,k;
			while(in>>n>>k){
				ll ans = quick_power(2 , k, MOD) - 1;
				ans = (ans + MOD)%MOD;
				ans = quick_power(ans,n,MOD);
				out<<ans<<endl;
			}
		}
};