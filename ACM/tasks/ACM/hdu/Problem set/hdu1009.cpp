#include "../../xyiyy/lib.hpp"
double a[10010];
double b[10010];
int p[10010];
bool cmp(int x,int y){
	return  (double)b[x]*a[y]<(double)b[y]*a[x];
}

class hdu1009 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			double m;
			while(in>>m>>n&&(n!=-1||m!=-1)){
				rep(i,n){
					in>>a[i]>>b[i];
					p[i] = i;
				}
				sort(p,p+n,cmp);
				double ans = 0;
				rep(i,n){
					if(m>=b[p[i]]){
						ans+=a[p[i]];
						m -= b[p[i]];
					}else {
						ans+= m * a[p[i]] /b[p[i]];
						break;
					}
				}
				out<<fixed<<setprecision(3)<<ans<<endl;
			}
		}
};