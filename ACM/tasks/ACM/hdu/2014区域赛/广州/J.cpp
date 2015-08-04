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
const int maxn=100010;
ll dp[maxn];
ll num[maxn];
const int mod=1000000007;
ll inv(int x)
{
	int n=mod-2;
	ll temp=x;
	ll ret=1;
	while(n)
	{
		if(n&1)ret=ret*temp%mod;
		temp=temp*temp%mod;
		n>>=1;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	ll inv_2,inv_3;
	inv_2=inv(2);
	inv_3=inv(3);
	dp[0]=num[0]=1;
	dp[1]=num[1]=1;
	for(int i=2;i<maxn;i++)
	{
		dp[i]=(num[i-1]*dp[i-2]%mod+(num[i-1]+1)*num[i-1]%mod*inv_2%mod)%mod;
		dp[i-1]+=dp[i-2];
		dp[i-1]%=mod;
		num[i]=dp[i];
	}
	int n;
	while(cin>>n&&n)
	{
		ll ans; 
		if(n==1)ans=1;
		else if(n==2)ans=1;
		else if(n&1)
		{
			ans=num[n/2]*(num[n/2]+1)%mod*inv_2%mod*dp[n/2-1]%mod;
			ans+=num[n/2]*(num[n/2]+1)%mod*(num[n/2]+2)%mod*inv_2%mod*inv_3%mod;
			ans%=mod;
		}
		else 
		{
			ans=(num[n/2]*(num[n/2]+1))%mod*inv_2%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}



