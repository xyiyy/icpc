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
int pa[MAXN],ra[MAXN],num[MAXN];
void init()
{
	for(int i =0;i<MAXN;i++)
	{
		pa[i]=i;
		ra[i]=0;
	
	}
}
int find(int x)
{
	if(pa[x]!=x)
	{
		int tmp=pa[x];
		pa[x]=find(pa[x]);
		ra[x]+=ra[tmp];
	}
	return pa[x];
}
int unite(int x,int y)
{
	int tx=find(x);
	int ty=find(y);
	if(tx==ty)
	return 0;
	pa[tx]=y;
	ra[tx]=1;
	return 1;
}

bool same(int x,int y)
{
	return find(x)==find(y);
}
int main()
{
	ios::sync_with_stdio(false);
//	freopen("1880.in","r",stdin);
//	freopen("1880.out","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		int t,x,y;
		while(m--)
		{
			scanf("%d%d%d",&t,&x,&y);
			x--;
			y--;
			if(t==1)
			{
				unite(x,y);
			}
			else{
				if(same(x,y))
				{
					printf("Yes ");
					find(x);
					find(y);
					printf("%d\n",ra[y]-ra[x]);
				}
				else printf("No\n");
			}
		}
	}
			
		
	return 0;
}



