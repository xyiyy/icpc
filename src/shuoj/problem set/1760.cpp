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
/**********************************
	���鼯ģ�� 
	2014.3.18
**********************************/

#define MAXN 300
int ans;
int pa[MAXN]; // parent
int ra[MAXN]; // rank
 
void init(int n)
{
	ans=1;
	for(int i = 0; i <n; i++)
	{
		pa[i] = i;
		ra[i] = 1;
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
//	ans=max(ra[x],ra[y]);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y])
		{
			ra[x]++;
		//	ans++;
		}
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	ios::sync_with_stdio(false);
	int n,a;
	while(cin>>n)
	{
		init(n);
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			unite(i,a-1);
		}
		for(int i=0;i<n;i++)
		{
			if(i==find(i))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}


