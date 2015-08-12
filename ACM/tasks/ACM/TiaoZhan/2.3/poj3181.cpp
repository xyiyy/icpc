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
unsigned long long dp[110][1010];
unsigned long long dp2[110][1010];
//ll dp3[110][1010];
const ll maxn=1000000000000000000;
int main()
{
	ios::sync_with_stdio(false);
//	CLR(dp,0);
//	CLR(dp2,0);
	for(int i=0;i<1001;i++)
	{
		dp[1][i]=1;
	}
	for(int i=2;i<101;i++)
	{
		for(int j=0;j<1001;j++)
		{
			for(int k=0;k*i<=j;k++)
			{
				//dp3[i][j]=((dp2[i][j]+dp2[i-1][j-k*i])/maxn+dp3[i][j]+dp3[i-1][j-k*i])%maxn;
				dp2[i][j]=(dp[i][j]+dp[i-1][j-k*i])/maxn+dp2[i][j]+dp2[i-1][j-k*i];
				dp[i][j]=(dp[i][j]+dp[i-1][j-k*i])%maxn;
				
			}
		}
	}
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//if(dp3[m][n])cout<<dp3[m][n];
		if(dp2[m][n])printf("%lld",dp2[m][n]);
		printf("%lld\n",dp[m][n]);
	}
	
	return 0;
}
