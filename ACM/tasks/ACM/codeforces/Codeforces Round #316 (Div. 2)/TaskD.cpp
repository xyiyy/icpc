#include "../../xyiyy/lib.hpp"
string str;
int dft = 0;
vector<int>G[500010];
vector<PII>q[500010];
int vs[2*500010];
int dep[500010];
int beg[500010];
vector<int>gao[500010];
int last[500010];
int dp[500010][26];
bool ok[500010];
void dfs(int u){
	beg[u] = dft;
	vs[dft] = u;
	gao[dep[u]].pb(dft++);
	for(int v:G[u]){
		dep[v] = dep[u] + 1;
		dfs(v);
	}
	last[u] = dft - 1;
}
class TaskD {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,m;
			in>>n>>m;
			rep(i,n - 1){
				int p;
				in>>p;
				p--;
				G[p].pb(i+1);
			}
			in>>str;
			rep(i,m){
				int v,h;
				in>>v>>h;
				v--,h--;
				q[h].pb(mp(i,v));
			}
			dep[0] = 0;
			dfs(0);
			rep(i,n){
				rep(j,26){
					dp[gao[i].size()][j] = 0;
				}
				dep(j,(int)gao[i].size()-1,0){
					rep(k,26){
						dp[j][k] = dp[j+1][k];
					}
					dp[j][str[vs[gao[i][j]]] - 'a'] ^= 1;
				}
				for(auto j:q[i]){
					int lx = lower_bound(ALL(gao[i]),beg[j.second]) - gao[i].begin();
					int rx = upper_bound(ALL(gao[i]),last[j.second]) - gao[i].begin();
					int num = 0;
					rep(k,26){
						num += dp[lx][k]^dp[rx][k];
						if(num>1)break;
					}
					if(num<=1)ok[j.first] = 1;
					//out<<j.first<<" "<<ok[j.first]<<endl;
				}
			}
			rep(i,m){
				if(ok[i])out<<"Yes"<<endl;
				else out<<"No"<<endl;
			}
		}
};