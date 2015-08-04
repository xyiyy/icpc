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
const int maxn=110;
int dp[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int len=s.length();
		CLR(dp,0);
		for(int i=0;i<len;i++)
		{
			dp[i][i]=1;
		}
		for(int l=1;l<len;l++)
		{
			for(int i=0;i<len;i++)
			{
				int j=i+l;
				if(j>=len)break;
				dp[i][j]=INF;
				if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
				for(int k=i;k<j;k++)
				{
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}



