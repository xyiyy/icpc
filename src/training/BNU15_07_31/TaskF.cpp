#include "../../xyiyy/lib.hpp"
int a[110],b[110],c[110];

#include <bitset>
bitset<121>dp[42][121][121];
class TaskF {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n){
				int tot = 0;
				rep2(i,1,n){
					in>>a[i]>>b[i]>>c[i];
					tot += c[i];
				}
				rep(i,n+1)
					rep(j,121)
						rep(k,121)dp[i][j][k].reset();
				int ta = 0,tb = 0;
				dp[0][0][0][0] = 1;
				rep2(i,1,n){
					rep2(j,0,ta){
						rep2(k,0,tb){
							dp[i][j+a[i]][k] |= dp[i-1][j][k];
							dp[i][j][k+b[i]] |= dp[i-1][j][k];
							dp[i][j][k] |= (dp[i-1][j][k] <<c[i]);
						}
					}
					ta += a[i];
					tb += b[i];
				}
				int ans = 0;
				rep2(i,1,120){
					if(dp[n][i][i][i]){
						ans = i;
						break;
					}
				}
				if(ans)out<<ans<<endl;
				else out<<"NO"<<endl;
			}
		}
};