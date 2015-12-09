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
int dp[1010][1010];
int a[110];
int w[110];
int main()
{
	ios::sync_with_stdio(false);
	int n,c;
	int cas=1;
	while(cin>>n>>c)
	{
		CLR(a,0);
		CLR(w,0);
		cout<<"Case "<<cas++<<":";
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		CLR(dp,0);
	//	dp[0][a[0]]=w[0];
		for(int i=1;i<n+1;i++)
		{
			for(int j=0;j<=c;j++)
			{
				if(j-a[i]>=0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+w[i]);
				else dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[n][c]<<endl;
	}
	return 0;
}


