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
int a[1010][1010];
int dp1[1010][1010];
int dp2[1010][1010];
int dp3[1010][1010];
int dp4[1010][1010];
ll dp[1010][1010];
int n,m;
ll maxx;

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(dp3,0,sizeof(dp3));
		memset(dp4,0,sizeof(dp4));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		dp1[1][1]=a[1][1];
		for(int i=2;i<=n;i++)
		{
			dp1[i][1]=dp1[i-1][1]+a[i][1];
		}
		for(int j=2;j<=m;j++)
		{
			dp1[1][j]=dp1[1][j-1]+a[1][j];
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
			}
		}
		dp2[n][1]=a[n][1];
		for(int i=n-1;i>0;i--)
		{
			dp2[i][1]=dp2[i+1][1]+a[i][1];
		}
		for(int j=2;j<=m;j++)
		{
			dp2[n][j]=dp2[n][j-1]+a[n][j];
		}
		for(int i=n-1;i>0;i--)
		{
			for(int j=2;j<=m;j++)
			{
				dp2[i][j]=max(dp2[i+1][j],dp2[i][j-1])+a[i][j];
			}
		}
		dp3[1][m]=a[1][m];
		for(int i=2;i<n;i++)
		{
			dp3[i][m]=dp3[i-1][m]+a[i][m];
		}
		for(int j=m-1;j>0;j--)
		{
			dp3[1][j]=dp3[1][j+1]+a[1][j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m-1;j>0;j--)
			{
				dp3[i][j]=max(dp3[i-1][j],dp3[i][j+1])+a[i][j];
			}
		}
		dp4[n][m]=a[n][m];
		for(int i=n-1;i>0;i--)
		{
			dp4[i][m]=dp4[i+1][m]+a[i][m];
		}
		for(int j=m-1;j>0;j--)
		{
			dp4[n][j]=dp4[n][j+1]+a[n][j];
		}
		for(int i=n-1;i>0;i--)
		{
			for(int j=m-1;j>0;j--)
			{
				dp4[i][j]=max(dp4[i+1][j],dp4[i][j+1])+a[i][j];
			}
		}
		maxx=0;
		for(int i=2;i<n;i++)
		{
			for(int j=2;j<m;j++)
			{
				dp[i][j]=max(dp1[i][j-1]+dp4[i][j+1]+dp3[i-1][j]+dp2[i+1][j],dp1[i-1][j]+dp4[i+1][j]+dp2[i][j-1]+dp3[i][j+1]);
			}
		}		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				maxx=max(dp[i][j],maxx);
			}
		}
		cout<<maxx<<endl;
	}
		
		
	return 0;
	}

