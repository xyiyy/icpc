#include "../../xyiyy/lib.hpp"
char str[3000010];
class TaskC {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n,m;
			in>>n>>m;
			in>>str+1;
			int len = strlen(str+1);
			int ans = 0;
			rep2(i,1,len-1){
				if(str[i]=='.'&&str[i+1]=='.')ans++;
			}
			int x;
			char c;
			rep(i,m){
				in>>x>>c;
				int f = 0;
				if(str[x-1]=='.'&&str[x]=='.')f++;
				if(str[x+1]=='.'&&str[x]=='.')f++;
				str[x] = c;
				if(str[x-1]=='.'&&str[x]=='.')f--;
				if(str[x+1]=='.'&&str[x]=='.')f--;
				ans -=f ;
				out<<ans<<endl;
			}
		}
};