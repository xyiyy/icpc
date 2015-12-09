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

#define MAXN 510

//============================
// union-find
int pa[MAXN]; // parent
int ra[MAXN]; // rank
int cnt; 
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
	cnt++;
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
	//init(n);
	priority_queue<Edge> q;
	for(int i = 0; i < e; i++)
		q.push(edge[i]);
	int ans = 0;
	int u,v;
//	cout<<cnt<<endl;
	if(cnt==n-1)return ans;
	for(int i = 0; cnt < n-1; i++)
	{
		//if(q.empty())return -1;
		Edge e = q.top();
		while(same(e.u, e.v) && !q.empty())
		{
			q.pop();
			e = q.top();
		}
		if(q.empty())return -1;
		unite(e.u,e.v);
		ans += e.l;
		if(cnt==n-1)return ans;
	}
	return ans;
}
int main()
{
	int n,m,k;
	int t;
	scanf("%d",&t);
	int num=0;
	int u,v,c;
	while(t--)
	{
		e=0;cnt=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			addEdge(u,v,c);
			addEdge(v,u,c);
		}
		init(n+1);
		int a,b;
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&num,&a);
			for(int j=1;j<num;j++)
			{
				scanf("%d",&b);
				unite(a,b);
				//if(j)addEdge(a[j],a[j-1],0);
			}	
		}
		printf("%d\n",Kruskal(n));
	}
			
	return 0;
}


