#include "../../xyiyy/lib.hpp"

class TaskA {
public:
		void solve(std::istream& in, std::ostream& out) {
            int n, l, c;
            string str;
            while(in>>n>>l>>c){
                int ans = 1;
                int num = 0;
                int f = 0;
               // cout<<endl;
                rep(i,n){
                    in>>str;
                    int len = str.length();
                    if(num == l){
                        num = 0;
                        ans ++;
                    }
                    if(f + len <= c){
                        f += len + 1;
                    }else{
                        f = len + 1;
                        num++;
                    }
                   // cout<<ans<<" "<<num<<" "<<f<<endl;
                }
                if(num == l) ans++;
                out<<ans<<endl;
            }
		}
};