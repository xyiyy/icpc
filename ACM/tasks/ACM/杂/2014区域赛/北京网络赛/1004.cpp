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

int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		double a,sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a);
			sum+=a;
		}
		int b;
		for(int i=0;i<n;i++)scanf("%d",&b);
		double ans=(n+1)*1.0/sum;
		printf("Case #%d: %.6lf\n",cas++,ans);
		//cout<<fixed<<setprecicision(10)<<(n+1)/sum<<endl;
	}
	return 0;
}



