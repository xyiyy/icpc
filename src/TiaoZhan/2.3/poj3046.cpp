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
int f[1010],dp[1010][10010];
int main()
{
	ios::sync_with_stdio(false);
	int t,a,s,b;
	while(cin>>t>>a>>s>>b)
	{
		CLR(f,0);
		int x;
		for(int i=1;i<=a;i++)
		{
			cin>>x;
			f[x]++;
		}
		CLR(dp,0);
		int sum=0;
		for(int i=0;i<=f[1];i++)dp[1][i]=1;
		for(int i=2;i<=t;i++){
			for(int j=0;j<=b;j++)
			{
				for(int k=0;k<=f[i];k++)
				{
					if(j>=k)dp[i][j]=(dp[i][j]+dp[i-1][j-k])%1000000;
					else break;
				}
			}
			
		}
		for(int j=s;j<=b;j++)
		{
			sum=(sum+dp[t][j])%1000000;
		}
		cout<<sum<<endl;
	}
		
	return 0;
}


