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

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d,w,x,y,z;
		cin>>a>>b>>c>>d>>w>>x>>y>>z;
		ll tmp1 = a*w;
		ll tmp2 = b*x;
		ll tot = c*y+d*z;
		ll l1 = 0;
		ll r1 = c;
		ll ans = max(tmp1+tot,tmp2+tot);
		while(l1<=r1){
			ll mid = (l1+r1)>>1;
			ll l2 = 0;
			ll r2 = d;
			ll tz;
			while(l2<=r2){
				ll midl = (2*l2+r2)/3;
				ll midr = (2*r2+l2)/3;
				ll tmpl = mid * y + midl * z;
				ll tmpr = tot - tmpl +tmp2;
				tmpl += tmp1;
				ans = min(ans,max(tmpl,tmpr));
				if(tmpl>=tmpr){
					tz = midr;
					l2 = midl + 1;
				}else{
					r2 = midr - 1;
				}
			}
			ll gao1 = tz*z + l1 * y;
			ll gao2 = tot - gao1 + tmp2;
			gao1 += tmp1;
			ans = min(ans , max(gao1,gao2));
			if(gao1<=gao2){
				l1 = mid + 1;
			}else {
				r1 = mid - 1;
			}
		}
		cout<<ans<<endl;
	}
			
				
	return 0;
}



