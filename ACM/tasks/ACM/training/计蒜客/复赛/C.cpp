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
typedef pair<ll,ll> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
ll a[10],l[10],r[10];
map<ll,ll>ms;
const ll MOD = 47;
PII gao[1110];
map<ll,ll>dp[5];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<3;i++){
			cin>>a[i]>>l[i]>>r[i];
		}
		ll n;
		cin>>n;
		dp[0].clear();
		for(ll i=l[0];i<=r[0];i++){
			if(a[0]-l[0]>2209)break;
			ll ans = 1;
			ll tmp = 1;
			for(ll j=a[0];j>(a[0]-l[0]);j--){
				tmp = tmp * (j%MOD)%MOD;
			}
			dp[0][i] = tmp;
			cout<<tmp<<endl;
		}
		//cout<<"ok"<<endl;
		int tot;
		for(int i=1;i<3;i++){
			dp[i].clear();
			//tot = 0;
			cout<<"   "<<i<<endl;
			for(map<ll,ll>::iterator it = dp[i-1].begin();it!=dp[i-1].end();it++){
				dp[i][it->first]=it->second;
			}
			for(ll j=l[i];j<=r[i];j++){
				if(a[i]-l[i]>=47)break;
				ll tmp = 1;
				for(ll k=a[i];k>(a[i]-l[i]);k--){
					tmp = tmp*(j%MOD)%MOD;
				}
				cout<<j<<endl;
				//gao[tot++] = MP(j,tmp);
				for(map<ll,ll>::iterator it = dp[i-1].begin();it!=dp[i-1].end();it++){
					ll num = it->first;
					ll c = it->second;
					dp[i][num+j]+=c*tmp%47;
				}
			}
		}
		ll ans = 0;
		for(map<ll,ll>::iterator it=dp[2].begin();it!=dp[2].end();it++){
			ll num = it->first;
			if(num>n)break;
			ans = (ans + it->second)%MOD;
		}
		cout<<ans<<endl;
	}
			
					
		
		
	return 0;
}



