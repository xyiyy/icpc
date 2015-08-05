#include "../../../../library/lib.hpp"
#include "../../../../library/algo/math/quick_power.hpp"
vector<PII> vec[100010];
int dp[100010];
class shuoj1939 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		init();
		in >> t;
		while (t--) {
			int n, m, k;
			in >> n >> m >> k;
			clr(dp,0);
			int tmp = min(m,n-m);
			int p = max(m,n-m);
			rep2(i,p+1,n){
				rep(j,vec[i].size()){
					int x = vec[i][j].first;
					int y = vec[i][j].second;
					dp[x]+=y;
				}
			}
			rep2(i,2,tmp){
				rep(j,vec[i].size()){
					int x = vec[i][j].first;
					int y = vec[i][j].second;
					dp[x]-=y;
				}
			}
			ll ans = 1;
			rep2(i,2,100000){
				ans = ans * quick_power(i,dp[i],k) %k;
			}
			out<<ans<<endl;

		}
	}
	void init(){
		rep2(i,2,100000){
			int tmp = i;
			for(int j=2;j*j<=tmp;j++){
				if(tmp%j==0){
					int num = 0;
					while(tmp%j==0){
						num++;
						tmp/=j;
					}
					vec[i].pb(mp(j,num));
				}
			}
			if(tmp!=1)vec[i].pb(mp(tmp,1));
		}
	}
};
