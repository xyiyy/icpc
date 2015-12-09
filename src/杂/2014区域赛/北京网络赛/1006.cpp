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
int num[200010];
int dp[200010];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		int n,m,l;
		scanf("%d%d%d",&n,&m,&l);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		num[n]=m;
		n++;
		sort(num,num+n);
		int i;
		CLR(dp,0);
		for(i=0;num[i]==1;i++)
		{
			dp[i]=0;
		}
		int k;
		for(;i<n;i++)
		{
			k=lower_bound(num,num+n,num[i]-l)-num;
			dp[i]=dp[k]+1;
		}
		printf("Case #%d: ",cas++);
		printf("%d\n",dp[n-1]);
	}
		
			
	return 0;
}



