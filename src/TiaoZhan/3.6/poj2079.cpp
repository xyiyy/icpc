#include <../../xyiyy/lib.hpp>
#include <../../xyiyy/geo/P.hpp>
const int MAXN = 100010;
P ps[MAXN];
class poj2079 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		while(in>>n){
			if(n==-1)return;
			rep(i,n)in>>ps[i].x>>ps[i].y;
			convex_hull(ps,n);

		}
	}
};
