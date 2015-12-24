#include "../../../xyiyylib/lib.hpp"
const int mod = 1000000007;
int MOD(int &a,int b){
	a += b;
	while(a>=mod)a -= mod;
}
string a;
int f1(){
	int ret = 0;
	rep(i,10){
		ret <<= 1;
		if(a[i] == 'w'){
			ret=(ret|1);
		}
	}
	return ret;
}
int gao(){
	int ret = 0;
	rep(i,10){
		ret<<=1;
		if(a[i] == '+'){
			ret |= 1;
		}
	}
	return ret;
}
int dp[10010][2];
class Chef_and_Filters {//change to scanf can ac
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in>> t;
		while(t--){
			in>>a;
			int num = f1();
			clr(dp,0);
			int n;
			dp[num][1] = 1;
			in>> n;
			rep(i,n){
				in>>a;
				num = gao();
				//out << num<<endl;
				int p = (i&1);
				int fp = (p^1);
				rep(j,1024){
					dp[j][p] = dp[j][fp];
					MOD(dp[j][p],dp[j^num][fp]);
				}
			}
			out << dp[0][(n-1)&1] << endl;
		}
	}
};
