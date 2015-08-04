//#####################
//Author:fraud
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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
string s1,s2;
char a[10010];
char b[100010];
class ABBA{
	public:
		string canObtain(string initial, string target){
			s1 = initial;
			s2 = target;
			int len1 = s1.size();
			int len2 = s2.size();
			for(int i=0;i<len1;i++){
				a[i]=s1[i];
			}
			for(int i=0;i<len2;i++){
				b[i] = s2[i];
			}
			while(len2>len1){
				if(b[len2-1]=='A'){
					;
				}else{
					reverse(b,b+len2-1);
				}
				len2--;
			}
			int f = 0;
			for(int i=0;i<len1;i++){
				if(a[i]!=b[i])f=1;
			}
			string ans;
			if(f)ans = "Impossible";
			else ans = "Possible";
			return ans;
		}
};
	
int main()
{
	ios::sync_with_stdio(false);

	return 0;
}



