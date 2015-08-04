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
const ll MOD = 1000000007;
void extgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){
        d=a;x=1;y=0;
    }else{
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll inv(ll a){
    ll d,x,y;
    extgcd(a,MOD,d,x,y);
    return d==1?(x+MOD)%MOD:-1;
}
ll qpow(ll m,int n){
	ll ret = 1;
	while(n){
		if(n&1)ret = ret * m % MOD;
		m = m * m % MOD;
		n>>=1;
	}
	return ret;
}
PII a[2010];
int dp[2010];
ll fa[200010];
ll fac[200010];
ll C(int a,int b){
	if(a<b||b<0)return 0;
	ll ret = fa[a];
	//ret  = ret*(qpow(fa[b]*fa[a-b]%MOD,MOD-2))%MOD;
	ret = ret*fac[b]%MOD*fac[a-b]%MOD;
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	int h,w,n;
	fa[0] = 1;
	for(int i=1;i<200010;i++){
		fa[i] = fa[i-1]*(ll)i%MOD;
	}
	for(int i=0;i<200010;i++){
		fac[i] = inv(fa[i]);
	}
	scanf("%d%d%d",&h,&w,&n);
	int x,y;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		scanf("%d",&y);
		x--;y--;
		a[i].first = x;
		a[i].second = y;
		//cin>>a[i].first>>a[i].second;
	}
	sort(a,a+n);
	a[n].first = h-1;
	a[n].second = w-1;
	n++;
	for(int i=0;i<n;i++){
		x = a[i].first;
		y = a[i].second;
		dp[i] = C(x+y,y);
		for(int j=0;j<i;j++){
			if(a[j].second<=y){
				dp[i]=(dp[i]+MOD-dp[j]*C(x+y-a[j].first-a[j].second,x-a[j].first)%MOD)%MOD;
			}
		}
	}
	cout<<dp[n-1]<<endl;	
	return 0;
}



