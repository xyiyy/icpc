#include "../../../../library/lib.hpp"
int dp[2010][2010];
int dp2[2010];
const int mod = 1000000007;
class hdu5362 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,m;
			in>>n>>m;
			dp[0][0] = 1;
			rep2(i,1,n){
				for(int j = (i&1);j<=m&&j<=i;j++){
					if(!j)dp[i][j] = dp[i-1][j+1];
					else if(j==i||j==m)dp[i][j] = (ll)dp[i-1][j-1]*(m-j+1) % mod;
					else dp[i][j] = ((ll)dp[i-1][j-1]*(m - j + 1) + (ll)dp[i-1][j+1]*(j+1))%mod;
				}
			}
			dp2[0] = 1;
			rep2(i,1,n){
				dp2[i] = (ll)dp2[i-1]*m%mod;
			}
			int ans = 0;
			rep2(i,1,n){
				ans = (ans + (ll)dp[i][i&1]*(n-i+1)%mod*dp2[n-i])%mod;
			}
			out<<ans<<endl;
		}
};