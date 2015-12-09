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
const int maxn=100010;
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		ll sum=(n-1)*n/2;
		int l=0,r=1000000000;
		int ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			ll num=0;
			for(int i=0;i<n;i++)
			{
				num+=(a+n)-lower_bound(a+i+1,a+n,a[i]+mid);
			//	cout<<num<<endl;
				
			}
			if(num>sum/2)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	
				
	 
	return 0;
}


