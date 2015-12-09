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
ll a[100010];
int n,m;
ll goal;
void solve()
{
	int lb=-1,ub=n;
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if(a[mid]>=goal)
		{
			ub=mid;
		}
		else 
		{
			lb=mid;
		}
	}
//	if(ub!=n)
	printf("%lld\n",a[ub]);
	//else 
	//printf("-1\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	//	memset(a,-1,sizeof(a));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		a[n]=-1;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%lld",&goal);
			solve();
		}
	}
		
	return 0;
}

