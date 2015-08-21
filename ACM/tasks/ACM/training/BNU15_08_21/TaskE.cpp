#include "../../xyiyy/lib.hpp"
int a[2010],b[2010];
int p[2010];
int dp[2010][2010];
bool cmp(int x,int y){
	return a[x]+b[x]>a[y]+b[y];
}
class TaskE {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n){
				rep2(i,1,n)in>>a[i]>>b[i];
				int h;
				in>>h;
				rep2(i,1,n)p[i] = i;
				sort(p+1,p+n+1,cmp);
				rep(i,n+1)dp[0][i] = INF;
				dp[0][0] = 0;
				int sum = 0;
				rep2(i,1,n){
					sum += a[p[i]];
					rep2(j,1,i){
						dp[i][j] = dp[i-1][j] - a[p[i]];
						int tmp = max(dp[i-1][j-1],h - sum -b[p[i]]);
						dp[i][j] = min(dp[i][j],tmp);
					}
					dp[i][i+1] = INF;
				}
				int ans = 0;
				rep(i,n+1){
					if(dp[n][i]<=0)ans = i;
				}
				out<<ans<<endl;
			}
		}
};