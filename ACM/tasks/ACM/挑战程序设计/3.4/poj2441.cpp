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
const int maxn=22;
int dp[2][1<<maxn];
int a[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0];
			for(int j=1;j<=a[i][0];j++)
			{
				cin>>a[i][j];
				a[i][j]--;
			}
		}
		for(int i=1;i<=a[1][0];i++)
		{
			dp[1][1<<a[1][i]]=1;
		}
		int l=1;
		int r=l^1;
		for(int i=2;i<=n;i++)
		{
			l=r;
			r=l^1;
			CLR(dp[l],0);
			for(int j=1;j<=a[i][0];j++)
			{
				int x=a[i][j];
				for(int k=0;k<(1<<m);k++)
				{
					if(k&(1<<x))continue;
					dp[l][k|(1<<x)]+=dp[r][k];
				}
			}
		}
		int ans=0;
		for(int i=0;i<(1<<m);i++)
		{
			ans+=dp[l][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}


