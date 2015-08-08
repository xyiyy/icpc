#include "../../../../library/lib.hpp"

int a[10010];
class hdu5364 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		while(in>>n){
			clr(a,0);
			int m;
			int ans = -1;
			rep(i,n){
				in>>m;
				a[m]++;
				if(a[m]>n/2)ans=m;
			}
			out<<ans<<endl;
		}
	}
};