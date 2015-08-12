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
char a[2010];
int cost[27];
int dp[2010][2010];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		CLR(a,0);
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		char b;
		int c,d;
		for(int i=0;i<n;i++)
		{
			cin>>b;
			cin>>c>>d;
			cost[b-'a']=min(c,d);
		}
		CLR(dp,0);
		for(int j=1;j<=m;j++)
		{
			for(int i=j+1;i>0;i--)
			{
				dp[i][j]=min(dp[i+1][j]+cost[a[i]-'a'],dp[i][j-1]+cost[a[j]-'a']);
				if(a[i]==a[j])dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			}
		}
		cout<<dp[1][m]<<endl;
	}
		
	return 0;
}


