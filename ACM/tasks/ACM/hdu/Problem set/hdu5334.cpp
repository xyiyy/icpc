//#####################
//Author:xyiyy
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;


class hdu5334 {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll k;
		while(in>>k){
			int a,b,c;
			int f = 0;
			rep(i,33334){
				int tmp = k + i*i;
				int minn = sqrt(tmp*1.0) + 1e-3;
				minn = min(minn, tmp / (i + i - 1));
				dep(j,minn,i){
					if(tmp % j == 0){
						c = i-1;
						a = tmp/j - i;
						b = j - i;
						if(a + b + c <= 100000) f = 1;
						if(f)break;
					}
				}
				if(f)break;
			}
			out<<a+b+c<<endl;
			rep(i,a){
				if(i)out<<" ";
				out<<'1';
			}
			rep(i,b){
				if(i+a)out<<" ";
				out<<'2';
			}
			rep(i,c){
				if(i+a+b)out<<" ";
				out<<'1';
			}
			out<<endl;
		}
	}
};
