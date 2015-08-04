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
double a[1010],b[1010],c[1010];
int main()
{
	//ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&b[i]);
		}
		double l=0,r=1.0;
	//	double ans=0;
		for(int k=0;k<100;k++)
		{
			double mid=(l+r)/2.0;
			for(int i=0;i<n;i++)
			{
				c[i]=a[i]-mid*b[i];
			}
			sort(c,c+n);
			double sum=0;
			for(int i=m;i<n;i++)
			{
				sum+=c[i];
			}
			if(sum>=0)
			{
				//ans=max(mid,ans);
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		printf("%.0lf\n",l*100);
	}
			
		
	return 0;
}


