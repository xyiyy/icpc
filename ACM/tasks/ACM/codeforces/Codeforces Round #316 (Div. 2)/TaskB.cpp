#include "../../xyiyy/lib.hpp"

class TaskB {
public:
		void solve(std::istream& in, std::ostream& out) {
			int m,n;
			in>>n>>m;
			if(n==1)out<<1<<endl;
			else if(m==1)out<<2<<endl;
				else if(n==m)out<<n-1<<endl;
			else if(m-1>=n-m)out<<m-1<<endl;
			else out<<m+1<<endl;
		}
};