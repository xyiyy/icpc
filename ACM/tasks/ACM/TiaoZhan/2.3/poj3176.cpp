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
int a[510][510];
int dp[510][510];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		CLR(dp,0);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin>>a[i][j];
			}
		}
		//dp[0][0]=a[0][0];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
			}
		}
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			maxx=max(dp[n][i],maxx);
		}
		cout<<maxx<<endl;
	}
				
	return 0;
}


