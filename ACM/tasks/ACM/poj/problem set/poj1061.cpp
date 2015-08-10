#include "../../../../library/lib.hpp"
#include "../../../../library/algo/math/inv.hpp"
class poj1061 {
public:
		void solve(std::istream& in, std::ostream& out) {
			ll x,y,n,m,l;
			while(in>>x>>y>>m>>n>>l){//(m-n)*xx - yy * l = y-x;
				ll xx,yy,d,c = x-y;
				extgcd(n-m,l,d,xx,yy);
				if(n<m){
					d = -d;
					c = -c;
				}
				l/=d;
				if(c%d!=0)out<<"Impossible"<<endl;
				else out<<((c/d*xx)%l + l)%l<<endl;
			}
		}
};