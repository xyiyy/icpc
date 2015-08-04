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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int id[1005];
double x[1005],y[1005],t[1005];
double dp[1005];
double ex[1005];
bool cmp(int a,int b)
{
	return t[a]<t[b];	
}
double dist(double x1,double y1,double x2,double y2)
{
	return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));	
}
int main()
{
	//ios::sync_with_stdio(false);
	
	
	int tst;
	cin>>tst;
	while(tst--)
	{
		int n,v;
		cin>>n>>v;
		t[0]=-1;
		id[0] = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i]>>t[i]>>ex[i];
			id[i] = i;
		}
		
		sort(id,id+n+1,cmp);
		
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			if( t[id[i]] == 0)
				dp[1] = max( dp[1], ex[id[i]]);	
		}
		double ans = 0;
		for(int i=1;i<=n;i++)
		{
			dp[i] = ex[id[i]];
			for(int j=1;j<i;j++)
			{
				if( dist( x[id[i]],y[id[i]],x[id[j]],y[id[j]] ) / v < (t[id[i]]-t[id[j]]))
				{
					dp[i] = max( dp[i],dp[j]+ex[id[i]]);
				}
				
			}
			ans = max(ans,dp[i]);
		}
		printf("%.6f\n",ans);
	}
	
	return 0;
}

