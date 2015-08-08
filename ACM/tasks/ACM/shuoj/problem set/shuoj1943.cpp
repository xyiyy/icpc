#include "../../../../library/lib.hpp"
int a[100010];
int dp[100010];
int b[100010];
class shuoj1943 {
public:
	int n,len;
		void solve(std::istream& in, std::ostream& out) {
			while(in>>n){
				len = 0;
				rep2(i,1,n)in>>a[i];
				rep(i,n+1)dp[i] = 0;
				dep(i,n,1){
					int m = run(a[i]);
					b[i] = m;
					len = max(len,m);
					dp[m] = max(dp[m],a[i]);
				}
				int last = 0;
				rep2(i,1,n){
					if(b[i]==len&&a[i]>last){
						out<<a[i];
						len--;
						last = a[i];
						if(len)out<<" ";
						else break;
					}
				}
				out<<endl;
			}
		}
	int run(int x){
		int l = 1,r=len,ans = 0;
		while(l<=r){
			int mid = (l+r)>>1;
			if(dp[mid]>x)ans = mid,l = mid+1;
			else r = mid - 1;
		}
		return ++ans;
	}
};