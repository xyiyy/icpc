#include "../../xyiyy/lib.hpp"
int hp[1010],dps[1010];
int p[1010];
bool cmp(int x,int y){
	if(hp[x]*dps[y]==hp[y]*dps[x])return hp[x]<hp[y];
	return hp[x]*dps[y]<hp[y]*dps[x];
}
class TaskA {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n){
				rep(i,n)in>>hp[i]>>dps[i];
				rep(i,n)p[i] = i;
				sort(p,p+n,cmp);
				ll ans = 0;
				ll sum = 0;
				rep(i,n){
					sum = sum + hp[p[i]];
					ans = ans +  sum * dps[p[i]];
				}
				out<<ans<<endl;
			}
		}
};