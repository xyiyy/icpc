//gaoshenbaoyou  ------ pass system test
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
int dp[110][110]; 
int a[110][110];
int b[110];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,t;
	cin>>t;
	while(t--) 
	{
		cin>>n>>m;
		CLR(dp,0);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++)cin>>b[i];
		for(int i=1;i<n;i++)
		{
			if(b[i-1]>0)
			{
				if(b[i]>0)
				{
					dp[i][b[i]]=dp[i-1][b[i-1]]+a[b[i-1]][b[i]];
				}
				else
				{
					for(int j=1;j<=m;j++)
					{
						dp[i][j]=dp[i-1][b[i-1]]+a[b[i-1]][j];
					}
				}
			}
			else 
			{
				if(b[i]>0)
				{
					for(int j=1;j<=m;j++)
					{
						dp[i][b[i]]=max(dp[i-1][j]+a[j][b[i]],dp[i][b[i]]);
					}
				}
				else
				{
					for(int j=1;j<=m;j++)
					{
						for(int k=1;k<=m;k++)
						{
							dp[i][k]=max(dp[i-1][j]+a[j][k],dp[i][k]);
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			ans=max(dp[n-1][i],ans);
		}
		cout<<ans<<endl;
	}
		
	return 0;
}



