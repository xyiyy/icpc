#include "../../../xyiyylib/lib.hpp"
const int maxn = 100010;
vector<pair<int,ll> > G[maxn];
stack<int>
class Chef_and_Girls {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,m;
		in >> n >> m;
		int u,v,l,r;
		rep(i,m){
			in >> u >> v >> l >> r;
			ll key = 1LL;
			key = (1LL<<r) - 1LL - ((1LL<<(l-1)) - 1LL);
			G[u].pb(mp(v,key));
		}


	}
};
