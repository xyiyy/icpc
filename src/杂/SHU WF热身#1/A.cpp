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
ll dp[110]; 
ll fun(ll K,ll B)
{
	if(K==0)
	{
		if(B>=1)return 1;
		else return 0;
	}
	if(B==(1<<(K)))return dp[K];
	if(B<=(1<<(K-1)))return fun(K-1,B)*2;
	else 
	{
		return 2*dp[K-1]+fun(K-1,B-(1<<(K-1)));
	}
}
	


int main()
{
	ios::sync_with_stdio(false);
	ll K,A,B;
	ll ans;
	dp[0]=1;
	int T;
	for(int i=1;i<31;i++)
	{
		dp[i]=dp[i-1]*3;
	}
	int k=1;
	cin>>T;
	while(T--)
	{
		cin>>K>>A>>B;
		ans=fun(K,B)-fun(K,A-1);
		cout<<"Case "<<k++<<": "<<ans<<endl;
	}
	return 0;
}


