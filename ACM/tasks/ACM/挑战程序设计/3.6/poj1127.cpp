#include "../../../../library/lib.hpp"
const int MAXN = 110;
#include "../../../../library/algo/DS/UnionFindSet.hpp"
#include "../../../../library/algo/geo/P.hpp"
P p[110],q[110];
class poj1127 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			P *p = new P[110];
			P *q = new P[110];
			while(in>>n&&n){
				init(n+5);
				rep2(i,1,n){
					in>>p[i].x>>p[i].y>>q[i].x>>q[i].y;
 				}
				rep2(i,1,n){
					rep2(j,1,n){
						if(p[i].crsSS(p[i],q[i],p[j],q[j]))unite(i,j);
					}
				}
				int u,v;
				while(in>>u>>v&&(u&&v)){
					if(same(u,v))out<<"CONNECTED"<<endl;
					else out<<"NOT CONNECTED"<<endl;
				}
			}
		}
};