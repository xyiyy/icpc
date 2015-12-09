#include "../../xyiyy/lib.hpp"

class hdu5344 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in>>t;
		while(t--){
			ll m,z,l,n;
			in >> n >> m >> z >> l;
			ll x = 0;
			ll ans = 0;
			rep(i,n){
				ans ^= (x + x);
				x = (x * m + z) % l;
			}
			out << ans << endl;
		}
	}
};
