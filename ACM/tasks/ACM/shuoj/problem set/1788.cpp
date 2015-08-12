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

#define MAXN 100010

int pa[MAXN]; // parent
int ra[MAXN]; // rank
int a[MAXN];
 
void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
}

int find(int x)
{
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}
int n,m;		
map<int ,int >Map;

int main()
{
	//ios::sync_with_stdio(false);
	//freopen("1788.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		Map.clear();
		init(n);
		fill(a,a+n,1);
		map<int,int >::IT it;
		int op;
		int x,y;
		Map[1]=n;
		for(int i=0;i<m;i++)
		{		
			scanf("%d",&op);
			if(!op)
			{
				scanf("%d%d",&x,&y);
				x--,y--;
				if(same(x,y))continue;
				int s=a[find(x)]+a[find(y)];
				Map[a[find(x)]]--;Map[a[find(y)]]--;
				if(!Map[a[find(x)]])Map.erase(a[find(x)]);
				if(!Map[a[find(y)]])Map.erase(a[find(y)]);
				if(Map.count(s))Map[s]++;
				else Map[s]=1;
				unite(x,y);
				a[find(x)]=s;
			}
			else 
			{
				scanf("%d",&x);
				it=Map.end();
				while(x>0)
				{
					it--;
					x-=it->second;	
				}
				printf("%d\n",it->first);
				
			}
		}
	}
				
	return 0;
}



