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
const int maxn=2010;
int dp[maxn+1][maxn+1];
int mon[maxn+1]; 
int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	while(cin>>m>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>mon[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(j<mon[i])
				{
					dp[i+1][j]=dp[i][j];
				}
				else 
				{
					dp[i+1][j]=max(dp[i][j],dp[i][j-mon[i]]+mon[i]);
				}
			}
		}
		cout<<dp[n][m]<<endl;
	}
		
	return 0;
}

