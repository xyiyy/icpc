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
const int N=103;
int dp[N][N];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int temp;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>temp;
				dp[i][j]=dp[i][j-1]+temp;
			}
		}	
		int maxn=-128;
		int sum=0,k=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				for(sum=0,k=1;k<=n;k++)
				{
					sum=(sum>0?sum:0)+dp[k][j]-dp[k][i-1];
					maxn=max(maxn,sum);
				}
			}
		}
		cout<<maxn<<endl;
	}
	
		
	return 0;
}

