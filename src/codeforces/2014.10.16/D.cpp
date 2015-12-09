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
ll dp[200010];
int main()
{
	ios::sync_with_stdio(false);
	int r,g;
	while(cin>>r>>g)
	{
		ll ans=0;
		int h=1;
		for(;h*(h+1)/2<=r+g;h++);
		h--;
		int s1=h*(h+1)/2;
		//cout<<h<<endl;
			ans=0;
			s1=h*(h+1)/2;
			CLR(dp,0);
			dp[0]=1;
			for(int i=1;i<=h;i++)
			{
				int w=i*(i+1)/2;
				for(int j=w;j>=i;j--)
				{
					dp[j]+=dp[j-i];
					dp[j]%=1000000007LL;
				}
			}
			for(int i=0;i<=s1&&i<=r;i++)
			{
				if(s1-i<=g)
				{
					ans+=dp[i];
					ans%=1000000007LL;
				}
			}
		cout<<ans<<endl;
	}
			
		
	return 0;
}



