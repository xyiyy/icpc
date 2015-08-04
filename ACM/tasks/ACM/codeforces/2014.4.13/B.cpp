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
long long a[50010][5];
//int vis[50010][5];
long long dp[50010][5];

int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		//	sum+=a[i][j];
		}
	}
/*	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//for(int i=0;i<sum)
	dp[0][0]=a[0][0];
	for(int i=1;i<m;i++)
	{
		dp[i][0]=dp[i-1][0]+a[i][0];
	}
	for(int i=1;i<n;i++)
	{
		dp[0][i]=dp[0][i-1]+a[0][i];
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(dp[i-1][j]>=dp[i][j-1])dp[i][j]=dp[i-1][j]+a[i][j];
			else
			{dp[i][j]=dp[i][j-1]+a[i][j];}
			
		}
	}
	if(m>1)
	for(int i=0;i<m-1;i++)
	{
		cout<<dp[i][n-1]<<" ";
	}
	
	cout<<dp[m-1][n-1];
	cout<<endl;

	
		
	
	return 0;
}

