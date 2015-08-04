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
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
#define MAXN 3000000

int pa[MAXN]; // parent
int ra[MAXN]; // rank
 
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
int main()
{
//	ios::sync_with_stdio(false);
	int n,k,ans;
	int cas,x,y;
	scanf("%d%d",&n,&k);
//	while(cin>>n>>k)
//	{
		ans=0;
		init(3*n+100);
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&cas,&x,&y);
			//cin>>cas>>x>>y;
	//		x--;y--;
			if((x<=0)||(x>n)||(y<=0)||(y>n)||(x==y && cas==2))
			{
				ans++;
			}
			else if(cas==1)
			{
				if(same(x,y+n)||same(x,y+2*n))
				{
					ans++;
				}
				else 
				{
					unite(x,y);
					unite(x+n,y+n);
					unite(x+2*n,y+2*n);
				}	
			}
			else 
			{
				if(same(x,y)||same(x,y+2*n))
				{
					ans++;
				}
				else 
				{
					if(x==y)
					{
						ans++;
						continue;
					}
					unite(x,y+n);
					unite(x+n,y+2*n);
					unite(x+2*n,y);
				}
			}
		}
		printf("%d\n",ans);
		//cout<<ans<<endl;
//	}
			 
	return 0;
}


