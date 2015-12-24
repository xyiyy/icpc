#include "../../../xyiyylib/lib.hpp"
string str[110];
class Oracle_Devu_and_Longest_Common_Subsequence  {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in >> t;
		while(t--){
			int n;
			in >> n;
			rep(i,n)in>>str[i];
			int m = str[0].length();
			int ans = m;
			rep(i,n){
				int num = 0;
				rep(j,m){
					if(str[i][j] == 'a')num++;
				}
				ans = min (ans,min(m - num,num));
			}
			out << ans << endl;
		}

	}
};
