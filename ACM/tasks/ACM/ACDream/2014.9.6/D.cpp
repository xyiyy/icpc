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
int w[100010];
int p[100010];
int main()
{
	//ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	int cas=1;
	//cin>>t;
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&w[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		sort(w,w+n);
		sort(p,p+n);
		ll temp=0;
		ll sum=1;
		for(int i=0;i<n;i++)
		{
			temp=upper_bound(w,w+n,p[i])-w-i;
		//	if(temp==0)sum=0;
		
			sum=sum*temp%1000000007;
		}
		printf("Case #%d: %lld\n",cas++,sum);
	}
		
	return 0;
}



