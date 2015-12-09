#include "../../xyiyy/lib.hpp"

class TaskA {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,m;
			in>>m>>n;
			int a[110];
			clr(a,0);
			rep(i,n){
				int maxx = -1;
				int x = 0;
				int y;
				rep(j,m){
					in>>y;
					if(y>maxx){x = j,maxx = y;}
				}
				a[x]++;
			}
			int maxx = -1;
			int x = 0;
			rep(i,m){
				if(a[i]>maxx)x = i,maxx = a[i];
			}
			out<<x+1<<endl;
		}
};