#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/geo/P.hpp"
const int MAXN = 710;
P ps[MAXN];
pair<double,bool> arc[MAXN];
class poj1981 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			P t;
			while(in>>n && n){
				rep(i,n)in>>ps[i].x>>ps[i].y;
				int ans = 1;
				rep(i,n){
					int num = 0;
					rep(j,n){
						if(i==j)continue;
						double d;
						if((d = (ps[i]-ps[j]).abs())<=2){
							double a = acos(d / 2);
							double b = atan2((ps[j].y - ps[i].y), (ps[j].x - ps[i].x));
							arc[num++] = mp(b - a, 1);
							arc[num++] = mp(b + a, 0);
						}
					}
					sort(arc,arc+num);
					int res = 1;
					rep(j,num){
						if(arc[j].second)res++;
						else res--;
						ans = max(ans,res);
					}
				}
				out<<ans<<endl;
			}
		}
};