#include "../../xyiyy/lib.hpp"
ll dp[10010],dp2[10010],a[10010],sum[10010];
class TaskC {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n){
				clr(sum,0);
				clr(dp,0);
				clr(dp2,0);
				rep2(i,1,n)in>>a[i];
				rep2(i,1,n){
					dp2[i] = a[i];
					sum[i] = sum[i-1] + a[i];
				}
				rep2(k,2,n){
					rep2(i,1,n-k+1)dp[i] = max(sum[i+k-1] - sum[i] - dp2[i+1] + a[i],sum[i+k-2] - sum[i-1] - dp2[i] + a[i+k-1]);
					rep2(i,1,n-k+1)dp2[i] = dp[i];
				}
				out<<dp[1]<<endl;
			}
		}
};