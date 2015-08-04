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
#define MOD 51061
//vector<int >G[MAXN];
//typedef unsigned int long long;
struct Node
{
	Node *parent,*child[2];
	bool rev;
	int size;
	long long add,sum,mul,key;
	void update_add(long long x)
	{
		sum=(size*x+sum)%MOD;
		key=(key+x)%MOD;
		add=(add+x)%MOD;
	}
	void update_mul(long long x)
	{
		sum=(sum*x)%MOD;
		key=(key*x)%MOD;
		mul=(mul*x)%MOD;
		add=(add*x)%MOD;
	}
}lct[MAXN],*EMPTY=lct;
inline bool _splay_parent(Node *x,Node *(&y))
{
	return (y=x->parent)!=EMPTY&&(y->child[0]==x||y->child[1]==x);
}
inline void push_down(Node *x)
{
	if(x==EMPTY)return;
	if(x->rev)
	{
		x->child[0]->rev^=1;
		x->child[1]->rev^=1;
		swap(x->child[0],x->child[1]);
		x->rev=0;
	}
	if(x->mul!=1)
	{
		if(x->child[0]!=EMPTY)x->child[0]->update_mul(x->mul);
		if(x->child[1]!=EMPTY)x->child[1]->update_mul(x->mul);
		x->mul=1;
	}
	if(x->add)
	{
		if(x->child[0]!=EMPTY)x->child[0]->update_add(x->add);
		if(x->child[1]!=EMPTY)x->child[1]->update_add(x->add);
		x->add=0;
	}
	
}
inline void update(Node *x)
{
	x->size=1;
	x->sum=x->key;
	if(x->child[0]!=EMPTY)
	{
		x->size+=x->child[0]->size;
		x->sum+=x->child[0]->sum;
	}
	if(x->child[1]!=EMPTY)
	{
		x->size+=x->child[1]->size;
		x->sum+=x->child[1]->sum;
	}
//	x->size=x->child[0]->size+x->child[1]->size+1;
//	x->sum=x->child[0]->sum+x->child[1]->sum+x->key;
}
inline void rotate(Node* const x,const int c)
{
	Node *const y=x->parent;
	y->child[c^1]=x->child[c];
	if(x->child[c]!=EMPTY)
	x->child[c]->parent=y;
	x->parent=y->parent;
	if(y->parent->child[0]==y)x->parent->child[0]=x;
	else if(y->parent->child[1]==y)x->parent->child[1]=x;
	y->parent=x;
	x->child[c]=y;
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
			const int c=(y==z->child[0]);
			if(x==y->child[c])
			{
				rotate(x,c^1);
				rotate(x,c);
			}
			else 
			{
				rotate(y,c);
				rotate(x,c);
			}
		}
		else 
		{
			push_down(y);
			push_down(x);
			rotate(x,x==y->child[0]);
			break;
		}
	}
	update(x);
}
inline Node* access(Node *u)
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
	for(x=access(x);push_down(x),x->child[0]!=EMPTY;x=x->child[0]);
	return x;
}
inline void makeroot(Node* x)
{
	access(x)->rev^=1;
	splay(x);
}
inline void link(Node * x,Node* y)
{
	makeroot(x);
	x->parent=y;
	//access(x);
}
inline void cut(Node*  x,Node*  y)
{
	//makeroot(x);
	//access(y);
	//splay(y);
	access(y);
	splay(x);
	if(x->parent==y)x->parent=EMPTY;
	else 
	{
		access(x);
		splay(y);
		y->parent=EMPTY;
	}	
	/*y->child[0]->parent=EMPTY;
	y->child[0]=EMPTY;
	update(y);*/
}
inline void Add(Node* x,Node *y,long long add)
{
	makeroot(x);
	access(y);
	splay(y);
	y->update_add(add);
}
inline void Mul(Node*const  x,Node* const y,long long mul)
{
	makeroot(x);
	access(y);
	splay(y);
	y->update_mul(mul);
//	printf("%lld\n",y->key);
}
/*void Init(int n)
{
	lct->key=lct->sum=lct->size=lct->add=0;
	lct->mul=1;
	for(int i=1;i<=n;i++)
	{
		(lct+i)->parent=(lct+i)->child[0]=(lct+i)->child[1]=EMPTY;
		(lct+i)->size=(lct+i)->mul=1;
		(lct+i)->add=0;
		(lct+i)->sum=(lct+i)->key=1;
	}
}*/
inline void query(Node* x,Node *y)
{
	makeroot(x);
	/*if(x==y)
	{
		printf("%lld\n",y->sum);
		return ;
	}*/
	access(y);
	splay(y);
	printf("%lld\n",y->sum%MOD);
}/* 
bool vis[MAXN];
void dfs(int son,int fa)
{
	vis[son]=1;
	(lct+son)->parent=(lct+fa);
	(lct+son)->child[0]=(lct+son)->child[1]=EMPTY;
	(lct+son)->key=(lct+son)->sum=(lct+son)->size=(lct+son)->mul=1;
	(lct+son)->add=0;
	for(int i=0;i<G[son].size();i++)
	{
		if(!vis[G[son][i]])
		{
			dfs(G[son][i],son);
		}
	}
}
*/
bool vis[MAXN];
struct Edge
{
	int v;
	Edge *next;
}G[MAXN*2],*head[MAXN];
int tot;
inline void addedge(const int from,const int to)
{
//	static int tot;
	Edge* const x=G+(tot++);
	x->v=to;
	x->next=head[from];
	head[from]=x;
}
void dfs(int son,int fa)
{
	Node *const  x=lct+son;
	vis[son]=1;
	x->key=x->sum=x->mul=x->size=1;
	x->add=0;
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
	//ios::sync_with_stdio(false);
	int n,m;
	
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		EMPTY->parent=EMPTY->child[0]=EMPTY->child[1]=EMPTY;
	//	Init(n);
		CLR(vis,0);
	//	for(int i=0;i<=n;i++)
	//	{
	//		G[i].clear();
	//	}
	//	lct->key=lct->sum=lct->size=lct->add=0;
	//	lct->mul=1;
		tot=0;
		int u,v;
		ll k;
		int nu,nv;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		//	G[u].PB(v);
			//init(u,v);
		//	(lct+v)->parent=(lct+u);
			//link(lct+u,lct+v);
		}
		dfs(1,0);
		char a[10];
		for(int i=0;i<m;i++)
		{
			scanf("%s",a);
			if(a[0]=='+')
			{
				scanf("%d%d%lld",&u,&v,&k);
				Add(lct+u,lct+v,k);
			}
			else if(a[0]=='*')
			{
				scanf("%d%d%lld",&u,&v,&k);
				Mul(lct+u,lct+v,k);
			}
			else if(a[0]=='-')
			{
				scanf("%d%d%d%d",&u,&v,&nu,&nv);
				cut(lct+u,lct+v);
				link(lct+nu,lct+nv);
			}
			else if(a[0]=='/')
			{
				scanf("%d%d",&u,&v);
				query(lct+u,lct+v);
			/*	for(int i=1;i<=n;i++)
				{
					printf("%lld\n",(lct+i)->sum);
				}*/
			}
		}
	}	
	return 0;
}


