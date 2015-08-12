#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/P.hpp"
const int MAXN = 310;
P ps[MAXN];
class poj1981baoli {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			P t;
			while(in>>n && n){
				rep(i,n)in>>ps[i].x>>ps[i].y;
				if(n == 1){
					out<< n <<endl;
					continue;
				}
				int ans = 1;
				rep(i,n){
					rep2(j,i+1,n-1){
						double d;
						t = ps[i] - ps[j];
						if((d = t.abs()) <= 2){
							ans = max(ans,2);
							double angle = acos(d / 2);
							int res = 2;
							for(int k = -1;k<=1;k+=2){
								P tmp = ps[j] + ((t/d).rot( k * angle));
								res = 0;
								rep(l,n){
									if((tmp - ps[l]).abs2() <= 1)res++;
								}
								ans = max(ans,res);
							}
						}
					}
				}
				out<<ans<<endl;
			}
		}
};