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
int n;
const int maxn=20010;

struct node
{
	int v,x;
	bool operator<(const node &b)const 
	{
		return v<b.v;
	}
}a[maxn];
ll bit0[maxn],bit1[maxn];

void init()
{
	CLR(bit0,0);
	CLR(bit1,0);
}
void add(ll *b,int i,int x)
{
	while(i<=maxn)
	{
		b[i]+=x;
		i+=i&-i;
	}
}
ll sum(ll *b,int i)
{
	ll s=0;
	while(i>0)
	{
		s+=b[i];
		i-=i&-i;
	}
	return s;
}
int main()
{
//	ios::sync_with_stdio(false);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i].v,&a[i].x);
		}
		sort(a+1,a+n+1);
		init();
		ll ans=0,cnt,tot=0,s;
		for(int i=1;i<=n;i++)
		{
			cnt=sum(bit0,a[i].x);
			s=sum(bit1,a[i].x);
			ans+=a[i].v*(tot-2*cnt+(2*s-i+1)*a[i].x);
			add(bit0,a[i].x,a[i].x);
			add(bit1,a[i].x,1);
			tot+=a[i].x;
		}
		printf("%lld\n",ans);
	}
	
	
		
		
		
	return 0;
}


