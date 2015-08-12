#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/P.hpp"
const int MAXN = 50010;
P ps[MAXN];
//should use scanf and printf
class poj2187 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			in>>n;
			rep(i,n){
				in>>ps[i].x>>ps[i].y;
			}
			convex_hull(ps,n);
			double res= 0;
			rep(i,qs.size()){
				rep(j,i){
					res = max(res, (qs[i] - qs[j]).abs2());
				}
			}
			out<<fixed<<setprecision(0)<<res<<endl;
		}
};