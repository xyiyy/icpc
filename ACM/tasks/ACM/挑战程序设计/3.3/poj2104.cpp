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
int n,m;
const int maxn=100010;
int a[maxn];
int num[maxn];
vector<int> dat[ST_SIZE];
void init(int l,int r,int cur)
{
	if(r==l)
	{
		dat[cur].PB(a[l]);
		return;
	}
	int mid=(l+r)/2;
	init(l,mid,cur<<1);
	init(mid+1,r,cur<<1|1);
	dat[cur].resize(r-l+1);
	merge(dat[cur<<1].begin(),dat[cur<<1].end(),dat[cur<<1|1].begin(),dat[cur<<1|1].end(),dat[cur].begin());
}
int query(int curl,int curr,int l,int r,int cur,int x)
{
	if(curr<l||curl>r)return 0;
	else if(curl<=l&&curr>=r)
	{
		return upper_bound(dat[cur].begin(),dat[cur].end(),x)-dat[cur].begin();
	}
	else
	{
		int mid=(l+r)/2;
		int sum=0;
		sum+=query(curl,curr,l,mid,cur<<1,x);
		sum+=query(curl,curr,mid+1,r,cur<<1|1,x);
		return sum;
	}
}
	
int main()
{
	//ios::sync_with_stdio(false);
	
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			num[i]=a[i];
		}
		sort(num,num+n);
		init(0,n-1,1);
		int l,r,k;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&l,&r,&k);
			l--;r--;
			int lb=0,ub=n-1;
			while(lb<ub)
			{
				int mid=(lb+ub)/2;
				int c=query(l,r,0,n-1,1,num[mid]);
				if(c>=k)ub=mid;
				else lb=mid+1;
			}
			printf("%d\n",num[ub]);
		}
	}		
	return 0;
}


