#include "../../xyiyy/lib.hpp"
char f[2010][110],s[2010][110];
int dp[2010][110];
class TaskG {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,w;
			while(in>>n>>w){
				int t1,t2,t3;
				in>>t1>>t2>>t3;
				rep2(i,1,n){
					in>>f[i] + 1;
					in>>s[i] + 1;
				}
				rep(i,n+10){
					rep(j,w+10)dp[i][j] = INF;
				}
				dp[n][1] = 0;
				int num = 0;
				if(f[n][1] == '|'||s[n][1]=='0')dp[n][1] = INF;
				rep2(i,2,w){
					if(f[n][i]=='|'||s[n][i]=='0')break;
					if(f[n][i] == '#')num += t3;
					num += t1;
					dp[n][i]  = dp[n][1] + num;
				}
				dep(i,n-1,1){
					rep2(j,1,w){
						if(f[i][j]=='|'||s[i][j]=='0')continue;
						num = 0;
						if(f[i][j]=='#')num += t3;
						bool ok = 0;
						dep(k,j-1,1){
							if(f[i][k] == '|')break;
							if(s[i][k]=='0')ok = 1;
							if(f[i][k+1]!='#') dp[i][j] = min(dp[i][j],dp[i+1][k] + num +(s[i][k] - '0' + 1) * t2);
							if(f[i][k] == '#')num += t3;
							num += t1;
							if(ok)break;
						}
						ok = 0;
						num = 0;
						if(f[i][j]=='#')num+=t3;
						rep2(k,j+1,w){
							if(f[i][k] == '|')break;
							if(s[i][k] == '0')ok = 1;
							if(f[i][k-1]!='#')dp[i][j] = min(dp[i][j],dp[i+1][k] + num + (s[i][k] - '0' + 1) * t2);
							if(f[i][k] == '#')num += t3;
							num += t1;
							if(ok)break;
						}
					}
				}
				int ans = INF;
				rep2(i,1,w)ans = min(ans,dp[1][i]);
				if(ans == INF)ans = -1;
				out<<ans<<endl;
			}
		}
};