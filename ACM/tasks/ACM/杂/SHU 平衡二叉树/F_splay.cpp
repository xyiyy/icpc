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
#define Key_value ch[ch[root][1]][0]
const int maxn[20010];
#define lson ch[r][0]
#define rson ch[r][1]
int root,pre[maxn],ch[maxn][2],key[maxn],size[maxn]; 
void newnode(int &r,int father,int ran,int k)
{
	r=ran;
	pre[r]=father;
	ch[r][0]=ch[r][1]=0;
	key[r]=k;
	size[r]=1;
}
void push_up(int r)
{
	size[r]=size[lson]+size[rson]+1;
}
void push_down()
{
}
void rotate(int x,int d)
{
	int y=pre[x];
	push_down(y);
	push_down(x);
	ch[y][!d]=ch[x][d];
	pre[ch[x][d]]=y;
	if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
	pre[x]=pre[y];
	pre[y]=x;
	ch[x][d]=y;
	push_up(y);
}
void splay(int r,int goal)
{
	push_down(r);
	while(pre[r]!=goal)
	{
		if(pre[pre[r]]==goal)
		{
		//	push_down(pre[r]);
		//	push_down(r);
			rotate(r,ch[pre[r]][0]==r);
		}
		else 
		{
		//	push_down(pre[pre[r]]);
		//	push_down(pre[r]);
		//	push_down(r);
			int y=pre[r];
			int d=(ch[pre[y]][0]==y);
			if(ch[y][d]==r)
			{
				rotate(r,!d);
				rotate(r,d);
			}
			else 
			{
				rotate(y,d);
				rotate(r,d);
			}
		}
	}
	push_up(r);
	if(goal==0) root=r;
}
void init()
{
	root=0;
	ch[root][0]=ch[root][1]=key[root]=pre[root]=0;
	newnode(root,)
}
int get_kth(int r,int k)
{
	push_down(r);
	int d=size[ch[r][0]]+1;
	if(d==k)return r;
	else if(d<k)return get_kth(ch[r][1],k-d);
	else return get_kth(ch[r][0],k);
	
}
int main()
{
	ios::sync_with_stdio(false);
	int cas=1;
	while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v);
			add_value(i,v);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&edge[i].u,&edge[i].v);
		}
		char c;
		int x,k;
		while(scanf(" %c",&c)!=EOF)
		{
			if(c=='E')break;
			scanf("%d",&x);
			else if(c=='D')
			{
				 vis[x]=1;
			}
			else if(c=='Q')
			{
				scanf("%d",&k);
			}
			else if(c=='C')
			{
				scanf()
		
	return 0;
}


