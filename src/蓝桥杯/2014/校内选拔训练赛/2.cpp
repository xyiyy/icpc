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
int a[110];
int dp[10010];
int x[10010];
int main()
{
	ios::sync_with_stdio(false);
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int l,s,t,m;
	cin>>l;
	cin>>s>>t>>m;
	int n=0;
	for(int i=1;i<=m;i++)cin>>a[i];
	sort(a+1,a+m+1);
	if(s==t)
	{
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(a[i]%s==0)ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]-a[i-1]>100)
		{
			n+=100;
			x[n]=1;
		}
		else 
		{
			n+=a[i]-a[i-1];
			x[n]=1;
		}
	}
	n+=100;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=INF;
		for(int j=s;j<=t;j++)
		{
			if(i<j)break;
			dp[i]=min(dp[i],dp[i-j]+x[i]);
		}
	}
	cout<<dp[n]<<endl;
			
		

	return 0;
}



