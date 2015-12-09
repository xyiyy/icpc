#include "../../xyiyy/lib.hpp"
char a[50010];
char b[50010];
int p[50010];
int n,m;
void getp(){
	p[0]=-1;
	int j= -1;
	int i = 0;
	while(i<m){
		if(j==-1||b[i]==b[j]){
			i++;j++;
			p[i] = j;
		}else j = p[j];
	}
}
int kmp()
{
	int i=0,j=0,cnt=0;
	while(i<n){
		if(b[j] == a[i] || j==-1){
			i++;j++;
		}else j = p[j];
	}
	while(j){
		j = p[j];
		cnt++;
	}
	return cnt;
}
class TaskG {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			while(t--){
				in>>a;
				in>>b;
				n = strlen(a), m = strlen(b);
				getp();
				out<<kmp()+1<<endl;
			}
		}
};