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
#define MAXN 10010
struct Node
{
	Node *parent,*child[2];
	bool rev;
}_memory[MAXN],*EMPTY=_memory;
inline bool _splay_parent(Node* x,Node *(&y))
{
	return (y=x->parent)!=EMPTY&&(y->child[0]==x||y->child[1]==x);
}
inline void rotate(Node* const x,const int c)
{
	Node* y=x->parent;
	y->child[c^1]=x->child[c];
	if(x->child[c]!=EMPTY)
	x->child[c]->parent=y;
	x->parent=y->parent;
	if(y->parent->child[0]==y)x->parent->child[0]=x;
	else if(y->parent->child[1]==y)x->parent->child[1]=x;
	y->parent=x;
	x->child[c]=y;
//	update(y);
}
void clear(Node *x)
{
	if(x==EMPTY)return;
	if(x->rev)
	{
		x->child[0]->rev^=1;
		x->child[1]->rev^=1;
		x->rev=0;
		swap(x->child[0],x->child[1]);
	}
}
inline void splay(Node* const x)
{
	clear(x);
	Node *y,*z;
	while(_splay_parent(x,y))
	{
		if(_splay_parent(y,z))
		{
			clear(z),clear(y),clear(x);
			const int c=(y==z->child[0]);
			if(x==y->child[c])rotate(x,c^1),rotate(x,c);
			else rotate(y,c),rotate(x,c);
		}
		else 
		{
			clear(y),clear(x);
			rotate(x,x==y->child[0]);
			break;
		}
	}
//	update(x);
}

Node * access(Node* u)
{
	Node *v=EMPTY;
	for(;u!=EMPTY;u=u->parent)
	{
		//printf("ok\n");
		splay(u);
		u->child[1]=v;
		v=u;
		//update(v=u);
	}
	//printf("ok1\n");
	return v;
}
Node * _access(Node* u)
{
	Node *v=EMPTY;
	for(;u!=EMPTY;u=u->parent)
	{
		splay(u);
		u->child[1]=v;
		v=u;
	//	update(v=u);
	}
	splay(u);
	return v;
}
inline void makeroot(Node* const x)
{
	access(x)->rev^=1;
	splay(x);
}
Node* getroot(Node* x)
{
	//printf("OK\n");
	for(x=access(x);clear(x),/*printf("ok\n"),*/x->child[0]!=EMPTY;x=x->child[0]);//printf("ok\n");
	//printf("%d\n",x-_memory);
	return x;
}
inline void link(Node* const x,Node* const y)
{
	makeroot(x);
	x->parent=y;
	access(x);
}
inline void cut(Node* const x,Node* const y)
{//以x为树根，把y到x的路径分离出来 
	makeroot(x);
	access(y);
	splay(y);
	y->child[0]->parent=EMPTY;
	y->child[0]=EMPTY;
	//update(y);
}
inline void query(Node*x,Node*y)
{
	Node*ra=getroot(x),*rb=getroot(y);
	if(ra==rb&&ra!=EMPTY)printf("Yes\n");
	else printf("No\n");
}
void Init(int n)
{
	Node *node;	
	for(int i=1;i<=n;i++)
	{
		node=_memory+i;
		node->parent=node->child[0]=node->child[1]=EMPTY;
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	int n,m;
	char a[10];
	int u,v;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		Init(n);
		for(int i=0;i<m;i++)
		{
			scanf("%s%d%d",a,&u,&v);
			if(a[0]=='C')link(_memory+u,_memory+v);
			else if(a[0]=='D')cut(_memory+u,_memory+v);
			else if(a[0]=='Q')query(_memory+u,_memory+v);
		}
	}
	
	return 0;
}


