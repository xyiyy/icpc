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

ll dp[20][20];
ll a[18];
ll C(int m, int n)
{
	if(m<20&&n<20&&dp[m][n]) return dp[m][n];
	if(m==n||n==0)return 1;
	if(n==1) return m;
	ll ret = C(m-1,n-1)*m/n;
	if(m<20&&n<20)dp[m][n]=ret;
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	a[0]=1;
	for(int i=1;i<18;i++)
	{
		a[i]=a[i-1]*i;
	}
	int t,cas;
//	cout<<a[17]<<endl;
	cin>>t;
	ll ans;
	int n,k;
	while(t--)
	{
		cin>>cas;
		cin>>n>>k;
		ans=a[n];
		for(int i=1;i<=k;i++)
		{
			if(i&1)
			ans-=C(k,i)*a[n-i];
			else ans+=C(k,i)*a[n-i];
		}
		cout<<cas<<" "<<ans<<endl;
	}
		
	return 0;
}


