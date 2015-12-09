#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=200010;
int root,tot;
#define INF 1<<30
#define Key_value ch[ch[root][1]][0]
int num[maxn];
int key[maxn],size[maxn],ch[maxn][2],maxx[maxn],pre[maxn];
void newnode(int &r,int father,int k)
{
	r=++tot;
	pre[r]=father;
	ch[r][0]=ch[r][1]=0;
	key[r]=k;
	size[r]=1;
	maxx[r]=k;
}
void push_up(int x)
{
	size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
	maxx[x]=max(key[x],max(maxx[ch[x][0]],maxx[ch[x][1]]));
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
}
void splay(int x,int goal)
{
	while(pre[x]!=goal)
	{
		if(pre[pre[x]]==goal)
		{
			rotate(x,ch[pre[x]][0]==x);
		}
		else 
		{
			int y=pre[x];
			int d=ch[pre[y]][0]==y;
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
	int mid=(l+r)/2;
	newnode(x,fa,num[mid]);
	build(ch[x][0],l,mid-1,x);
	build(ch[x][1],mid+1,r,x);
	push_up(x);
}
void init(int n)
{
	root=tot=0;
	key[root]=size[root]=0;
	ch[root][0]=ch[root][1]=0;
	maxx[root]=0;
	pre[root]=0;
	newnode(root,0,-INF);
	newnode(ch[root][1],root,-INF);
	build(Key_value,1,n,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
int get_kth(int r,int k)
{
	int d=size[ch[r][0]]+1;
	if(d==k)return r;
	else if(k>d) return get_kth(ch[r][1],k-d);
	else return get_kth(ch[r][0],k); 
}
void update(int r,int k)
{
	r=get_kth(root,r+1);
	key[r]=k;
	push_up(r);
	splay(r,0);
}
void query(int l,int r)
{
	splay(get_kth(root,l),0);
	//printf("%d\n",key[root]);
	splay(get_kth(root,r+2),root);
	printf("%d\n",maxx[Key_value]);
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		init(n);
		char a[10];
		int x,y;
		while(m--)
		{
			scanf("%s",a);
			scanf("%d%d",&x,&y);
			if(a[0]=='Q')
			{
				query(x,y);
			}
			else 
			{
				update(x,y);
			}
		}
	}
	return 0;
}
	
	

