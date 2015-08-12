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
const int maxn=10010;
int b[maxn];
int n,k;
int main()
{
	//ios::sync_with_stdio(false);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		double a;
		for(int i=0;i<n;i++) 
		{
			scanf("%lf",&a);
			
			b[i]=(int)(a*100);
		}
		int ans=0;
		int l=1,r=1e9;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int num=0;
			for(int i=0;i<n;i++)
			{
				num+=b[i]/mid;
			}
			if(num>=k)
			{
				ans=max(ans,mid);
				l=mid+1;
			}
			else 
			{
				r=mid-1;
			}
		}
		printf("%d.%02d\n",ans/100,ans%100);
		
	}
			
		
		
	return 0;
}


