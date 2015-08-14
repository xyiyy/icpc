#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/math/single_Eular.hpp"
class TaskL {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n){
				int ans = 1;
				ans = Eular(n);
				if(ans&1);
				else ans/=2;
				out<<ans<<endl;
			}
		}
};