#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/math/quick_power.hpp"
class TaskA {
public:
		void solve(std::istream& in, std::ostream& out) {
			int m,n;
			while(in>>m>>n){
				ll ans = 0;
				rep2(i,1,m)ans += quick_power(i,n,1e9);
				int cnt = 0;
				while(ans){
					if(ans%10!=0)break;
					cnt++;
					ans /= 10;
				}
				out<<cnt<<endl;
			}
		}
};