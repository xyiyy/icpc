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
string s = "anniversary";
int dp[110][20][10][2];
class hdu5311 {
public:
	void solve(std::istream& in, std::ostream& out) {
		string str;
		in>>str;
		int len = str.length();
		int n = s.length();
		clr(dp,0);
		dp[0][0][0][0] = 1;
		rep2(i,0,len){
			rep2(j,0,n){
				rep(k,4){
					rep(l,2){
						if(!dp[i][j][k][l])continue;
						if(j==n){
							out<<"YES"<<endl;
							return;
						}
						if(i==len)continue;
						if(j<n&&str[i] == s[j]){
							int nk = k + (!l);
							if(nk<4)dp[i+1][j+1][nk][1] = 1;
						}
						dp[i+1][j][k][0] = 1;
					}
				}
			}
		}
		out<<"NO"<<endl;
		return;
	}
};
