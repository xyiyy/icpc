#include "../../../../library/lib.hpp"
vector<PII> vec[100010];
ll dp[1010][1010];
const int mod = 1e9+7;
ll C(int m, int n)
{
	if(m<1000&&n<1000&&dp[m][n]) return dp[m][n];
	if(m==n||n==0)return 1;
	if(n==1) return m;
	ll ret = (C(m-1,n-1) + C(m-1,n)) % mod;
	if(m<1000&&n<1000)dp[m][n]=ret;
	return ret;
}
class shuoj1938 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in>>t;
		while(t--){
			int n,m;
			in>>n>>m;
			out<<C(n,m)<<endl;
		}
		
	}
};
