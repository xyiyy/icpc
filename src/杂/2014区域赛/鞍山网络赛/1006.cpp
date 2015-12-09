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
struct Node
{
	Node *parent,*child[2];
	bool same,rev;
	int size;
	int add,key,mx,maxx;
	void update_add(int x)
	{
		key=(key+x);
		add+=x;
	}
}lct[MAXN],*EMPTY=lct;
inline bool _splay_parent(Node *x,Node *(&y))
{
	return (y=x->parent)!=EMPTY&&(y->child[0]==x||y->child[1]==x);
}
inline void push_down(Node *x)
{
}
inline void update(Node *x)
{
}
inline void rotate(Node *const x,const int d)
{
	Node *const y=x->parent;
	y->child[!d]=x->child[d];
	if(x->child[c]!=EMPTY)
	x->child[c]->parent=y;
	x->parent=y->parent;
	if(y->parent->child[0]==y)x->parent->child[0]=x;
	else if(y->parent->child[1]==y)x->parent->child[1]=x;
	y->parent=x;
	x->child[d]=y;
	update(y);
}
inline void splay(Node *x)
{
	push_down(x);
	Node *z,*y;
	while(_splay_parent(x,y))
	{
		if(_splay_parent(y,z))
		{
			push_down(z);
			push_down(y);
			push_down(x);
			int d=(y==z->child[0]);
			if(x==y->child[d])
			{
				rotate(x,!d);
				rotate(x,d);
			}
			else 
			{
				rotate(y,d);
				rotate(x,d);
			}
		}
		else 
		{
			push_down(y);
			push_down(x);
			rotate(x,x==y->child[0]);
			rotate(x,y);
			break;
		}
	}
	update(x);
}
inline Node *access(Node *u)
{
	Node *v=EMPTY;
	while(u!=EMPTY)
	{
		splay(u);
		u->child[1]=v;
		update(v=u);
		u=u->parent;
	}
	return v;
}
inline Node *getroot(Node *x)
{
	for(x=accsess(x);push_down(x),x->child[0]!=EMPTY;x=x->child[0]);
	return x;
}
inline void makeroot(Node *x)
{
	access(x)->rev^=1;
	splay(x);
}
inline void link(Node *x,Node *y)
{
	makeroot(x);
	x->parent=y;
}
inline void cut(Node *x,Node *y)
{
	access(y);
	splay(x);
	if(x->parent==y)x->parent=EMPTY;
	else 
	{
		aaccess(x);
		splay(y);
		y->parent=EMPTY;
	}
}
inline void Add(Node *x,Node *y,int inc)
{
	makeroot(x);
	access(y);
	splay(y);
	y->update_add(inc);
}
inline void Make_same(Node *x,Node *y,int inc)
{
	makeroot(x);
	access(y);
	splay(y);
	
}
inline void query(Node *x,Node *y)
{
	makeroot(x);
	access(y);
	splay(y);
}
bool vis[MAXN];
struct Edge
{
	int v;
	Edge *next;
}G[MAXN*2],*head[MAXN];
int tot;
inline void add_edge(const int from,const int to)
{
	Edge *const x=G+(tot++);
	x->v=to;
	x->next=head[from];
	head[from]=x;
}
void dfs(int son,int fa)
{	
	Node *const x=lct+son;;
	vis[son]=1;
	x->key=x->size=1;
	x->add=0;
	x->same=x->rev=0;
	x->parent=lct+fa;
	x->child[0]=x->child[1]=EMPTY;
	for(Edge *e=head[son];e;e=e->next)
	{
		if(e->v!=fa&&!vis[e->v])
		{
			dfs(e->v,son);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	return 0;
}



