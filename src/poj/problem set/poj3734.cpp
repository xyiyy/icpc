#include "../../xyiyy/lib.hpp"
const int maxn = 4;
const int MOD = 10007;
#include "../../xyiyy/math/Matrix.hpp"
void Matrix::Unit() {
	m[0][0] = 2;m[0][1] = 2;m[0][2] = 0;
	m[1][0] = 1;m[1][1] = 2;m[1][2] = 1;
	m[2][0] = 0;m[2][1] = 2;m[2][2] = 2;
}
class poj3734 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			while(t--) {
				int n;
				in >> n;
				Matrix tmp(3, 3);
				tmp.Unit();
				Matrix ans(1, 3);
				ans.Init();
				ans = ans * tmp.power(n);
				out << ans.m[0][0] << endl;
			}
		}
};