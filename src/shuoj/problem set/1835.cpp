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
ll dp[130][130];
int main()
{
	ios::sync_with_stdio(false);
	dp[1][1]=1;
	for(int i=2;i<121;i++)
	{
		dp[i][i]=1;
		for(int j=1;j<=i&&j<=(i+1)/2;j++)
		{
			for(int k=j;k<=i-j;k++)
			{
				dp[i][j]+=dp[i-j][k];
			}
		}
	}
	for(int i=1;i<121;i++)
	{
		for(int j=1;j<i+1;j++)
		{
			dp[i][j+1]+=dp[i][j];
		}
	}
	int n;
	while(cin>>n)
	{
		cout<<dp[n][n+1]<<endl;
	}
	return 0;
}



