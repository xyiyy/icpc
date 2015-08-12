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
#define mod 100000000  
int dp[12][1<<12];
int pre[12];
bool check1(int x)
{
	return !(x&(x>>1));
}
bool check2(int a,int b)
{
	return !(a&b);
}
int a[12][12];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		CLR(dp,0);
		CLR(pre,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				if(a[i][j])pre[i]=(pre[i]|(1<<j));
			}
		}
		for(int i=0;i<(1<<m);i++)
		{
			if((pre[0]|i)==pre[0]&&check1(i))
			{
				dp[0][i]=1;
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<(1<<m);j++)
			{
				if((pre[i]|j)==pre[i]&&check1(j))
				{
					for(int k=0;k<(1<<m);k++)
					{
						if(check2(j,k))
						{
							dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<(1<<m);i++)
		{
			ans+=dp[n-1][i];
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}


