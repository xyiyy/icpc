#include "../../xyiyy/lib.hpp"
ll dp[110];
class hdu5366 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 1;
		while(in>>n){
			ll ans = 0;
			rep2(i,3,n){
				dp[i] = 0;
				rep(j,i-2){
					dp[i] += dp[j];
				}
				ans+=dp[i];
			}
			rep2(i,1,min(n,2))ans+=dp[i];
			out<<ans<<endl;
		}
	}
};