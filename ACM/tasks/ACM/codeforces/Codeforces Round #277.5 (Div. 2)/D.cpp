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
int dp[510][510];
int deg[510];
int x,y;
int n,m,MOD;
int dfs(int a,int b)
{
	if(a+b>n)return 0;
	if(a<0)return 0;
	if(dp[a][b])return dp[a][b];
	if(a+2*b<=x+2*y)return dp[a][b];
	if(b>1)dp[a][b]+=(a+2)*(a+1)/2*dfs(a+2,b-2);
	dp[a][b]%=MOD;
	dp[a][b]+=a*(n-a-b+1)*dfs(a,b-1);
	dp[a][b]%=MOD;
	if(a>1)dp[a][b]+=(n-a-b+2)*(n-a-b+1)/2*dfs(a-2,b);
	dp[a][b]%=MOD;
	return dp[a][b];
	
}
int main()
{
	ios::sync_with_stdio(false);
	
	while(cin>>n>>m>>MOD)
	{
		CLR(dp,0);
		int a,b;
		char ch;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>ch;
				if(ch=='1')
					deg[j]++;
			}
		}
		a=0,b=0;
		for(int i=0;i<n;i++)
		{
			if(deg[i]==1)a++;
			else if(deg[i]==2)b++;
		}
		dp[a][b]=1;
		x=a,y=b;
		cout<<dfs(0,n)<<endl;
	}
	return 0;
}



