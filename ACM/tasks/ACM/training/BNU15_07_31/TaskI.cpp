#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/math/Lucas.hpp"
class TaskI {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,m,p;
			while(in>>n>>m>>p){
				 out<<Lucas(n-m+1,m,p) % p<<endl;
			}
		}
};