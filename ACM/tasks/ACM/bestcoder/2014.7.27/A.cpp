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
#define lson t<<1,l,m
#define rson t<<1|1,m+1,r

class SEGTREE{
	private:
		ll* num;
		ll* sum;
		int sz;
		void build(int t, int l, int r)
		{
			num[t] = sum[t] = 0;
			if(l==r) return;
			int m = (l+r)>>1; 
			build(lson);
			build(rson);
		}
		void seg_add(int t, int l, int r, int pl, int pr, ll inc)
		{
			sum[t]+=inc*(pr-pl+1);
			if(l==pl && r==pr){num[t]+=inc;return;}
			int m = (l+r)>>1;
			if(pl>m) seg_add(rson, pl, pr, inc);
			else if(pr<=m) seg_add(lson, pl, pr, inc);
			else seg_add(lson, pl, m, inc),seg_add(rson, m+1, pr, inc);
		}
		ll seg_query(int t, int l, int r, int pl, int pr)
		{
			if(l==pl && r==pr) return sum[t];
			ll ret = num[t] * (pr-pl+1);
			int m = (l+r)>>1;
			if(pl>m)
				return ret + seg_query(rson, pl, pr);
			else if(pr<=m)
				return ret + seg_query(lson, pl, pr);
			else
				return ret + seg_query(lson, pl, m) + seg_query(rson, m+1, pr);
		}
	public:
		SEGTREE(int size)
		{
			sz = size > 0? size : 0;
			num = new ll[sz*3+1];
			sum = new ll[sz*3+1];
			this->init(sz); // initialize
		}
		~SEGTREE()
		{
			delete[] num;
			delete[] sum;
		}
		void resize(int size)
		{
			size = size > 0? size : 0;
			if(size <= sz) return;
			else{
				ll* tmp;
				tmp = new ll[size*3+1];
				delete[] num;
				num = tmp;
				tmp = new ll[size*3+1];
				delete[] sum;
				sum = tmp;
			}
			sz = size;
		}
		void init(int size)
		{
			build(1,0,sz);
		}
		void add(int l, int r, ll inc)
		{
			seg_add(1,0,sz,l,r,inc);
		}
		ll query(int l, int r)
		{
			return seg_query(1,0,sz,l,r);
		}
};
int main()
{
	ios::sync_with_stdio(false);
	int t,n,num;
	ll maxx;
	int h1,m1,h2,m2,t1,t2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=-1;
		SEGTREE seg(1<<12);
		seg.init(1<<12);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d:%d %d:%d",&num,&h1,&m1,&h2,&m2);
			t1=h1*60+m1;
			t2=h2*60+m2;
			seg.add(t1,t2-1,num);
		}
		for(int i=0;i<=60*24;i++)
		{
			maxx=max(seg.query(i,i),maxx);
		}
		printf("%I64d\n",maxx);
	}
		
	return 0;
}


