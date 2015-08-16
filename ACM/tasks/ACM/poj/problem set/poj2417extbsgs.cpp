#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/math/hashextbsgs.hpp"
class poj2417extbsgs {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,a,b;
			while(in>>n>>a>>b){
				int ans = extbsgs(a,b,n);
				if(ans == -1)out<<"no solution"<<endl;
				else out<<ans<<endl;
			}
		}
};