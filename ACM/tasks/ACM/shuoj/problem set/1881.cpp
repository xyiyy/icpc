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
const int MAXN =500010;
int pa[MAXN],ra[MAXN],fuc[MAXN];
int tot;
void init()
{
	for(int i=0;i<MAXN;i++)
	{
		pa[i]=i;
		ra[i]=0;
		fuc[i]=i;
	}
}
int find(int x)
{
	if(x!=pa[x]) pa[x]=find(pa[x]);
	return pa[x];
}
int unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return 0;
	if(ra[x]<ra[y])
	{
		pa[x]=y;
	}else{
		pa[y]=x;
		if(ra[x]==ra[y])ra[x]++;
	}
	return 1;
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
void del(int x)
{
	fuc[x]=tot;
	pa[tot]=tot;
	ra[tot]=0;
	tot++;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		tot=n;
		init();
		int t,x,y;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&t,&x,&y);
			x--;
			y--;
			
			if(t==1){x=fuc[x],y=fuc[y];
				unite(x,y);
			}else if(t==2)
			{x=fuc[x],y=fuc[y];
				if(same(x,y))printf("Yes\n");
				else printf("No\n");
			}else{
				del(x);
				x=fuc[x];
				unite(x,fuc[y]);
			}
		}
	}
			
	return 0;
}



