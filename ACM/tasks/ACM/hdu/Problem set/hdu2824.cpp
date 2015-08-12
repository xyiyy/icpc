#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/algo/math/simple_Eular.hpp"
class hdu2824 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int a,b;
			Eular();
			rep2(i,1,MAXN)phi[i] += phi[i-1];
			while(in>>a>>b){
				out<<phi[b]-phi[a-1]<<endl;
			}
		}
};