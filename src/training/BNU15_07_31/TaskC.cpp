#include "../../xyiyy/lib.hpp"
double dp[100010];
class TaskC {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			while(t--){
				int n;
				double p;
				in>>n>>p;
				dp[n-1] = 0;
				double tot = (double)n*(n-1)/2/p;
				dep(i,n-2,0){
					dp[i] = dp[i+1] + tot /(i+1)/(n-i-1);
				}
				out<<fixed<<setprecision(3)<<dp[0]<<endl;
			}
		}
};