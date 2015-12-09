#include "../../xyiyy/lib.hpp"
const int maxn = 5;
const ll MOD = 10000;
#include "../../xyiyy/math/Matrix.hpp"
void Matrix::Unit(){
	m[0][0] = m[0][1] = m[1][0] = 1;
	m[1][1] = 0;
}

class poj3070 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n&&n!=-1){
				Matrix ans(2,2);
				ans.Unit();
				ans = ans.power(n+1);
				out<<ans.m[1][1]<<endl;
			}
		}
};