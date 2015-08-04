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
const int maxn=4010;
int a[maxn],b[maxn],c[maxn],d[maxn];
int e[maxn*maxn];
int main()
{
	//ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				e[i*n+j]=-a[i]-b[j];
			}
		}
		ll sum=0;
		sort(e,e+n*n);
		ll temp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				temp=upper_bound(e,e+n*n,c[i]+d[j])-lower_bound(e,e+n*n,c[i]+d[j]);
				sum+=temp;
			}
		}
		printf("%lld\n",sum);
	}
			
		
		
	return 0;
}


