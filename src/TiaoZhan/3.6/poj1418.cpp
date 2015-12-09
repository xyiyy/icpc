#include "../../xyiyy/lib.hpp"
/*#include <complex>
typedef complex<double> P;
const double EPS = 4e-13;
const double PI = acos(-1.0);
double update(double r){
	while(r < 0.0)r += 2 * PI;
	while(r >= 2* PI)r -= 2 * PI;
	return r;
}



class poj1418 {
public:
	void solve(std::istream &in, std::ostream &out) {
		int n;
		while(in>>n && n){
			vector <P>ps;
			vector <double>rs;
			rep(i,n){
				double x,y,r;
				in>>x>>y>>r;
				ps.pb(P(x,y));
				rs.pb(r);
			}
			vector<bool> cansee(n,0);
			rep(i,n){
				vector<double> pp;
				pp.pb(0.0);
				pp.pb(2 * PI);
				rep(j,n){
					double a = rs[i];
					double d = abs(ps[i] - ps[j]);
					double b = rs[j];
					if(a + b < d || a + d < b || b + d < a)continue;
					double theta = acos((a * a + d * d - b * b) / (2 * a * d));
					double alpha = arg(ps[j] - ps[i]);
					pp.pb(update(alpha - theta));
					pp.pb(update(alpha + theta));
				}
				sort(ALL(pp));
				rep(j,pp.size()-1) {
					double theta = (pp[j] + pp[j + 1]) / 2;
					for (int k = -1; k <= 1; k += 2) {
						P t = P(ps[i].real() + (rs[i] + EPS * k) * cos(theta),
								ps[i].imag() + (rs[i] + EPS * k) * sin(theta));
						int gao = 0;
						for (gao = n - 1; gao >= 0; gao--) {
							if (abs(ps[gao] - t) < rs[gao])break;
						}
						if (gao != -1)cansee[gao] = 1;
					}
				}
			}
			out<<count(ALL(cansee),1)<<endl;
		}
	}
};

*/


#include "../../xyiyy/geo/P.hpp"
const long double PI2 = 2 * acos(-1.0);
long double update(double x){
	while(x<0.0)x += PI2;
	while(x>=PI2)x -= PI2;
	return x;
}
class poj1418 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			P t;
			while(in>>n && n){
				vector<P> ps;
				vector<double>rs;
				vector<bool>cansee(n,0);
				rep(i,n){
					double x,y,r;
					in>>x>>y>>r;
					ps.pb(P(x,y));
					rs.pb(r);
				}
				rep(i,n){
					vector<double> pp;
					pp.pb(0.0);
					pp.pb(PI2);
					rep(j,n){
						double a = rs[i];
						double d = (ps[i] - ps[j]).abs();
						double b = rs[j];
						if(a + b < d || a + d < b || b + d < a)continue;
						double theta = acos((a * a + d * d - b * b) / (2 * a * d));
						double alpha = polarangle(ps[i],ps[j]);
						pp.pb(update(alpha - theta));
						pp.pb(update(alpha + theta));
					}
					sort(ALL(pp));
					rep(j,pp.size()-1){
						double theta = (pp[j] + pp[j + 1]) / 2;
						for(int k = -1;k<=1;k+=2){
							t.x = ps[i].x + (rs[i] + k * EPS) * cos(theta);
							t.y = ps[i].y + (rs[i] + k * EPS) * sin(theta);
							int gao = n-1;
							for(;gao>=0;gao--){
								if((ps[gao] - t).abs() < rs[gao])break;
							}
							if(gao!=-1)cansee[gao] = 1;
 						}
					}
				}
				out<<count(ALL(cansee),1)<<endl;
			}

		}
};