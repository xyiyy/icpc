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

#define MAXN 100
int u,v,cap,sta;
//============================
// union-find
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
//============================

struct Edge{
	int u, v;
	int l;
	Edge(){};
	Edge(int _u, int _v, int len):u(_u),v(_v),l(len){}
	bool operator<(const Edge &e) const
	{
		return this->l > e.l;
	}
}edge[MAXN*MAXN];
int e;

void addEdge(int u, int v, int len)
{
	edge[e++] = Edge(u, v, len);
}

int Kruskal(int n)
{
	init(n);
	priority_queue<Edge> q;
	for(int i = 0; i < e; i++)
		q.push(edge[i]);
	int ans = 0;
	int u,v;
	for(int i = 0; i < n-1; i++)
	{
		Edge e = q.top();
		while(same(e.u, e.v) && !q.empty())
		{
			q.pop();
			e = q.top();
		}
		unite(e.u,e.v);
		ans += e.l;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n)
	{
		e=0;
		for(int i=0;i<n*(n-1)/2;i++)
		{
			cin>>u>>v>>cap>>sta; u--; v--;
			if(sta==1)
			{
				addEdge(u,v,0);
				addEdge(v,u,0);
			}
			else 
			{
				addEdge(u,v,cap);
				addEdge(v,u,cap);
			}
		}
		cout<<Kruskal(n)<<endl;
	}
		
	return 0;
}


