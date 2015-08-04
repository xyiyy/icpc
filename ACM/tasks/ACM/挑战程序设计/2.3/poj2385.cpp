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
int dp[40][1010];
int a[1010];
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	while(cin>>t>>n)
	{
		for(int i=1;i<=t;i++)
		{
			cin>>a[i];
		}
		CLR(dp,0);
		for(int i=1;i<=t;i++)
		{
			if(a[i]==1)
			{
				dp[0][i]=dp[0][i-1]+1;
			}
			else dp[0][i]=dp[0][i-1];
		//	cout<<dp[0][i];
		}
		//cout<<endl;
	//	for(int i=0;i<=n;i++)
	//	{
	//		if(i%2!=(a[i]%2))dp[i][1]=1;
	//	}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=t;j++)
			{
				if((i%2)==(a[j]%2))dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j-1]);
				else dp[i][j]=max(dp[i-1][j-1],dp[i][j-1]+1);
		//		cout<<dp[i][j]<<"  ";			
			}
		//	cout<<endl;
		}
		cout<<dp[n][t]<<endl;
	}
	return 0;
}


