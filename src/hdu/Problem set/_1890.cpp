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

const int maxn=100010;
struct node
{
	int num,id;
}in[maxn];
int pos[maxn];
int ch[maxn][2],pre[maxn],size[maxn],rev[maxn],id[maxn];
#define Key_value ch[ch[root][1]][0]
int root,tot;
void newnode(int &r,int fa)
{
	r=++tot;
	size[r]=1;
	ch[r][0]=ch[r][1]=0;
	rev[r]=0;
	pre[r]=fa;
//	pos[id[k]]=r;
}
void push_up(int r)
{
	size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
}
void push_down(int r)
{
	if(rev[r])
	{
		swap(ch[r][0],ch[r][1]);
		if(ch[r][0])rev[ch[r][0]]^=1;
		if(ch[r][1])rev[ch[r][1]]^=1;
		rev[r]=0;
	}
}
void rotate(int x,int d)
{
	int y=pre[x];
	ch[y][!d]=ch[x][d];
	pre[ch[x][d]]=y;
	if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
	pre[x]=pre[y];
	ch[x][d]=y;
	pre[y]=x;
	push_up(y);
	push_up(x);
}
void splay(int x,int goal)
{
	push_down(x);
	while(pre[x]!=goal)
	{
		int y=pre[x];
		int z=pre[y];
		push_down(z);
		push_down(y);
		if(z==goal)
		{
			rotate(x,ch[y][0]==x);
		}
		else 
		{
			int d=ch[z][0]==y;
			if(ch[y][d]==x)
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
	}
	push_up(x);
	if(goal==0)root=x;
}
void build(int &x,int l,int r,int fa)
{
	if(l>r)return ;
	int mid=(l+r)>>1;
	newnode(x,fa);
	pos[id[mid]]=x;
	build(ch[x][0],l,mid-1,x);
	build(ch[x][1],mid+1,r,x);
	push_up(x);
}
void init(int n)
{
	root=tot=0;
	size[0]=ch[0][0]=ch[0][1]=0;
	pre[0]=0;
	rev[0]=0;
	build(root,1,n,0);
}
void Treavel(int x)
{
	if(x)
	{
		Treavel(ch[x][0]);
		printf("结点%2d:左儿子 %2d 右儿子 %2d 父节点 %2d size = %2d\n",x,ch[x][0],ch[x][1],pre[x],size[x]);
		Treavel(ch[x][1]);
	}
}
void debug()
{
	printf("root%d\n",root);
	Treavel(root);
}

bool cmp(node x,node y)
{
	if(x.num==y.num)return x.id<y.id;
	return x.num<y.num;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&in[i].num);
			in[i].id=i;
		}
		sort(in+1,in+n+1,cmp);
		for(int i=1;i<=n;i++)id[in[i].id]=i;
		init(n);
		for(int i=1;i<n;i++)
		{
			splay(pos[i],0);
			//push_down(root);
			printf("%d ",size[ch[root][0]]+i);
			int t=root;
			rev[ch[root][0]]^=1;
			if(ch[root][1])
			{
				root=ch[root][1];
				int r=root;
				push_down(r);
				while(ch[r][0])
				{
					r=ch[r][0];
					push_down(r);
				}
				splay(r,0);
				ch[root][0]=ch[t][0];
				if(ch[t][0])pre[ch[t][0]]=root;
				
			}
			else 
			{
				root=ch[root][0];
			}
			pre[root]=0;
			push_up(root);
	
		}
		printf("%d\n",n);
	}	
	return 0;
}



