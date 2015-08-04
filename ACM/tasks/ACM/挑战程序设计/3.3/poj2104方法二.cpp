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
const int ST_SIZE=(1<<18)-1;
const int B=1000;
int n,m;
const int maxn=100010;
int a[maxn];
int num[maxn];
vector<int>bucket[maxn/B];
int main()
{
	ios::sync_with_stdio(false);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			bucket[i/B].PB(a[i]);
			num[i]=a[i];
		}
		sort(num,num+n);
		for(int i=0;i<n/B;i++)sort(bucket[i].begin(),bucket[i].end());
		int l,r,k;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&l,&r,&k);
			l--;r--;
			int mid,x;
			int lb=-1,ub=n-1;
			while(ub>lb+1)
			{
				mid=(lb+ub)/2;
				x=num[mid];
				int tl=l,tr=r+1,sum=0;
				while(tl<tr&&tl%B!=0)if(a[tl++]<=x)sum++;
				while(tl<tr&&tr%B!=0)if(a[--tr]<=x)sum++;
				while(tl<tr)
				{
					int b=tl/B;
					sum+=upper_bound(bucket[b].begin(),bucket[b].end(),x)-bucket[b].begin();
					tl+=B;
				}
				if(sum>=k)ub=mid;
				else lb=mid;
			}
			printf("%d\n",num[ub]);
		}
	}
					
					
		
	return 0;
}


