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
int f[110],s[110];
int dp[2010*110];
int main()
{
	ios::sync_with_stdio(false);
	int n,ans;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>f[i]>>s[i];
		}
		for(int i=0;i<2010*110;i++)
		{
			dp[i]=-INF;
		}
		dp[100000]=0;
		for(int i=0;i<n;i++)
		{
			if(f[i]<0&&s[i]<0)
			{
				continue;
			}
			if(s[i]>0)
			{
				for(int j=200000;j>=s[i];j--)
				{
					if(dp[j-s[i]]>-INF)
					{
						dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
					}
				}
			}
			else 
			{
				for(int j=s[i];j<=200000+s[i];j++)
				{
					if(dp[j-s[i]]>-INF)
					{
						dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
					}
				}
			}
		}
		ans=-INF;
		for(int i=100000;i<=200000;i++)
		{
			if(dp[i]>=0)
			{
				ans=max(dp[i]+i-100000,ans);
			}
		}
		cout<<ans<<endl;
	}
		
			
			
	return 0;
}


