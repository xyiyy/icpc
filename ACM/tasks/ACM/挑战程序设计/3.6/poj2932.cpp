#include "../../../../library/lib.hpp"

double r[40010],x[40010],y[40010];
vector<pair<double,int> >vec;
set<pair<double ,int> >s;
bool mark[40010];
vector<int>ans;
bool contain(int a,int b) {
	return ((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=r[b]*r[b]);
}
class poj2932 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		while(in>>n) {
			vec.clear();
			s.clear();
			ans.clear();
			rep(i, n)in >> r[i] >> x[i] >> y[i];
			rep(i, n) {
				vec.pb(mp(x[i] - r[i], i));
				vec.pb(mp(x[i] + r[i], i + n));
			}
			sort(ALL(vec));
			int num = 0;
			rep(i, vec.size()) {
				int j = vec[i].second;
				if (j < n) {
					set<pair<double, int> >::IT it = s.lower_bound(mp(y[j], j));
					if (it != s.end() && contain(j, it->second))continue;
					if (it != s.begin() && contain(j, (--it)->second))continue;
					s.insert(mp(y[j], j));
					mark[j+1] = 1;
					num++;
				} else {
					s.erase(mp(y[j-n], j-n));
				}
			}
			out<<num<<endl;
			rep(i,n){
				if(mark[i+1])out<<i+1<<" ";
			}
			out<<endl;
		}
	}
};