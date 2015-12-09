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
int a[100010],b[100010];
 
	
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			b[n-i+1]=-a[i];
		}
		b[n+1]=INF;
		a[n+1]=INF;
		b[0]=-INF;
		a[0]=-INF;
		int x;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&x);
			int y=b+n+1-upper_bound(b,b+n+2,-x);
			if(y)printf("%d ",y);
			else printf("-1 ");
			y=b+n+1-lower_bound(b,b+n+2,-x);
			if(y)printf("%d ",y);
			else printf("-1 ");
			y=upper_bound(a,a+n+2,x)-a;
			if(y==n+1)printf("-1 ");
			else printf("%d ",y);
			y=lower_bound(a,a+n+2,x)-a;
			if(y==n+1)printf("-1");
			else printf("%d",y);
			printf("\n");
		}
			
			
	}
	return 0;
}



