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
PII p[1010];
int dp[1<<16]; 
const int maxn=16;
int x[maxn],y[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		int id=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(i==j)continue;
				int x1=min(x[i],x[j]);
				int x2=max(x[i],x[j]);
				int y1=min(y[i],y[j]);
				int y2=max(y[i],y[j]);
				int s;
				if(x1==x2)
				{
					s=y2-y1;
				}
				else if(y[i]==y[j])
				{
					s=x2-x1;
				}
				else
				{
					s=(x2-x1)*(y2-y1);
				}
				int t=0;
				for(int k=0;k<n;k++)
				{
					if(x[k]>=x1&&x[k]<=x2&&y[k]>=y1&&y[k]<=y2)
					{
						t|=(1<<k);
					}
				}
				p[id++]=MP(s,t);
			}
		}
		fill(dp,dp+(1<<n),INF);
		dp[0]=0;
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<id;j++)
			{
				dp[i|p[j].second]=min(dp[i|p[j].second],dp[i]+p[j].first);
			}
		}
		cout<<dp[(1<<n)-1]<<endl;
	}
		
	return 0;
}


