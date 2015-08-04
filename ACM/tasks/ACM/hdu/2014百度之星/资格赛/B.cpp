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
const int N=1010;
int dp[N][370];

int dis(int a,int b)
{
	return min(abs(a-b),360-abs(a-b));
}

int main()
{
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n+5;i++)
		{
			for(int j=0;j<370;j++)
			{
				dp[i][j]=INF;
			}
		}
		dp[0][0]=0;
		int l=0,s,t,maxt=0;
		for(int i=0;i<n;i++)
		{
			cin>>t>>s;
			for(int j=0;j<360;j++)
			{
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+dis(s,l));
				dp[i+1][l]=min(dp[i+1][l],dp[i][j]+dis(s,j));
			}
			maxt=max(t,maxt);
			l=s;
		}
		int ans=INF;
		for(int i=0;i<360;i++)
		{
			ans=min(ans,dp[n][i]+dis(s,i));
		}
		//cout<<ans<<endl;
		cout<<maxt*400*2+n*10+ans<<endl;
	}
	
		
		
	return 0;
}

