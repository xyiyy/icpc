#include "../../../xyiyylib/lib.hpp"

class Chef_and_the_stones {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in >> t;
		while(t--){
			ll n1,n2,m;
			in>>n1>>n2>>m;
			ll tmp = (1+m)*m / 2;
			ll minn = min(n1,n2);
			ll maxx = max(n1,n2);
			ll ans;
			ans = max(minn - tmp,0LL);
			ans += maxx - min(minn,tmp);
			out << ans << endl;
		}
	}
};
