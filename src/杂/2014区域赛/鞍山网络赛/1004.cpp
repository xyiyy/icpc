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

int a[2000];
int dp[2001][2001];

#define MOD 1000000007

int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int mx=0, s=0;
		REP(i,n)
		{
			cin>>a[i];
			mx=max(mx,a[i]);
			s+=a[i];
		}
		mx=s/2;
		CLR(dp,0);
		dp[0][0]=1;
		REP(i,n)
		{
			REP(j,mx+1) if(dp[i][j])
			{
				REP(k,min(a[i], mx-j)+1)
				{
					(dp[i+1][j+k]+=dp[i][j])%=MOD;
				}
			}
		}
		cout<<dp[n][mx]<<endl;
	}
	return 0;
}



