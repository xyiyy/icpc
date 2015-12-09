#include "../../xyiyy/lib.hpp"
string str;
int num[1010];
char s[10][1010];
class TaskA {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			while(t--){
				in>>str;
				int n = 0;
				int len = str.length();
				num[n++] = str[0] - '0';
				rep2(i,1,len-1){
					int m = str[i] - '0';
					int p = num[n-1];
					if(m==p)num[n++] = m;
					else if(m>p){
						while(m>p)
							num[n++] = ++p;
					}else{
						while(m < p)num[n++] = --p;
					}
				}
				int x= 0;
				rep(i,10){
					rep(j,n)s[i][j]='*';
				}
				while(1){
					bool ok = 0;
					rep(j,n){
						if(num[j]){
							s[x][j] ='+';
							num[j]--;
							ok = 1;
						}
					}
					if(!ok)break;
					x++;
				}
				dep(i,x-1,0){
					rep(j,n)out<<s[i][j];
					out<<endl;
				}

			}
		}
};