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
const int maxn=1010;
int bit[maxn][maxn];
void init()
{
	CLR(bit,0);
}
void _add(int x,int y,int d)
{
	for(int i=x;i<=n;i+=i&-i)
	{
		for(int j=y;j<=n;j+=j&-j)
		{
			bit[i][j]+=d;
			bit[i][j]%=2;
		}
	}
}
int _sum(int x,int y)
{
	int s=0;
	for(int i=x;i;i-=i&-i)
	{
		for(int j=y;j;j-=j&-j)
		{
			s+=bit[i][j];
		}
	}
	s%=2;
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	int m;
	scanf("%d",&t);
	while(t--)
	{
		init();
		char a[10];
		int x1,x2,y1,y2;
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%s",a);
			if(a[0]=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				_add(x1,y1,1);
				_add(x1,y2+1,1);
				_add(x2+1,y1,1);
				_add(x2+1,y2+1,1);
			}
			else
			{
				scanf("%d%d",&x1,&y1);
				printf("%d\n",_sum(x1,y1));
			}
		}
		if(t)printf("\n");
	}
	return 0;
}


