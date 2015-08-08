#include "../../../../library/lib.hpp"
int a[100010];
class hdu1008 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n&&n){
				ll ans = 0;
				rep2(i,1,n){
					in>>a[i];
					if(a[i]>a[i-1]){
						ans += (a[i] - a[i-1])*6+5;
					}else if(a[i] == a[i-1])ans += 5;
					else ans += (a[i-1] - a[i])*4+5;
				}
				out<<ans<<endl;

			}
		}
};