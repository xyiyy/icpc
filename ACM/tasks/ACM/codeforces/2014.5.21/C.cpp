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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int n,k,d;
ll dp[10010];
ll sol(int a,int b)
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			dp[i+j+1]+=dp[i];
			dp[i+j+1]%=1000000007;
		}
	}
	return dp[a];
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n>>k>>d;
	ll ans=sol(n,k)-sol(n,d-1);
	ans+=1000000007;
	ans%=1000000007;
	cout<<ans<<endl;
	
	return 0;
}

