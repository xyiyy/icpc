#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
#define Key_value ch[ch[root][1]][0]
const int maxn=300010;
int num[maxn];
int rev[maxn],key[maxn],add[maxn],ch[maxn][2];
int minn[maxn],ss[maxn],pre[maxn],size[maxn];
int root,tot,tot2;
void newnode(int &r,int father,int k)
{
	if(tot2)r=ss[--tot2];
	else r=++tot;
	size[r]=1;
	pre[r]=father;
	add[r]=ch[r][0]=ch[r][1]=0;
	rev[r]=0;
	minn[r]=k;
	key[r]=k;
}
void update_add(int r,int inc)
{
	if(!r)return;
	key[r]+=inc;
	add[r]+=inc;
	minn[r]+=inc;
}
void update_rev(int r)
{
	if(!r)return;
	swap(ch[r][0],ch[r][1]);
	rev[r]^=1;
}
	 
void push_up(int r)
{
	size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
	minn[r]=min(key[r],min(minn[ch[r][0]],minn[ch[r][1]]));
	//minn[r]=key[r];
	//if(ch[r][0])minn[r]=min(minn[ch[r][0]],minn[r]);
	//if(ch[r][1])minn[r]=min(minn[ch[r][1]],minn[r]);
		
}
void push_down(int r)
{
	if(add[r])
	{
		update_add(ch[r][0],add[r]);
		update_add(ch[r][1],add[r]);
		add[r]=0;
	}
	if(rev[r])
	{
		update_rev(ch[r][0]);
		update_rev(ch[r][0]);
		rev[r]=0;
	}
}
void rotate(int x,int d)
{
	int y=pre[x];
	push_down(y);
	push_down(x);
	ch[y][!d]=ch[x][d];
	pre[ch[x][d]]=y;
	if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
	ch[x][d]=y;
	pre[x]=pre[y];
	pre[y]=x;
	push_up(y);
}
void splay(int x,int goal)
{
	push_down(x); 
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
			if(ch[pre[y]][d]==x)
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
	if(l>r)return;
	int mid=(l+r)/2;
	newnode(x,fa,num[mid]);
	build(ch[x][0],l,mid-1,x);
	build(ch[x][1],mid+1,r,x);
	push_up(x);
}
void init(int n)
{
	root=tot=tot2=0;
	size[root]=pre[root]=0;
	ch[root][1]=ch[root][0]=0;
	minn[root]=1<<30;
	key[root]=1<<30;
	size[root]=rev[root]=add[root]=0;
	newnode(root,0,1<<30);
	newnode(ch[root][1],root,1<<30);
	build(Key_value,1,n,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
int get_kth(int r,int k)
{
	int d=size[ch[r][0]]+1;
	push_down(r);
	if(k==d)return r;
	else if(k>d)return get_kth(ch[r][1],k-d);
	else return get_kth(ch[r][0],k);
}
void get_interval(int l,int r)
{
	splay(get_kth(root,l),0);
	splay(get_kth(root,r+2),root);
}
void Add(int l,int r,int inc)
{
	get_interval(l,r);
	update_add(Key_value,inc);
	push_up(ch[root][1]);
	push_up(root);
}
void Reverse(int l,int r)
{
	get_interval(l,r);
	update_rev(Key_value);
	push_up(ch[root][1]);
	push_up(root);
}
void Revolve(int l,int r,int t)
{
	int len=(r-l)+1;
	t=(t%len+len)%len;
	if(t==0)return;
	t=r-t+1;
	get_interval(t,r);
	int temp=Key_value;
	Key_value=0;
	push_up(ch[root][1]);
	push_up(root);
	splay(get_kth(root,l),0);
	splay(get_kth(root,l+1),root);
	Key_value=temp;
	pre[Key_value]=ch[root][1];
	push_up(ch[root][1]);
	push_up(root);
}
void erase(int r)
{
	if(!r)return ;
	ss[tot2++]=r;
	erase(ch[r][0]);
	erase(ch[r][1]);
}
void Delete(int pos)
{
	get_interval(pos,pos);
	erase(Key_value);
	pre[Key_value]=0;
	Key_value=0;
	push_up(ch[root][1]);
	push_up(root);
}
void Insert(int pos,int k)
{
	get_interval(pos+1,pos);
	newnode(Key_value,ch[root][1],k);
	push_up(ch[root][1]);
	push_up(root);
}
void Query(int l,int r)
{
	get_interval(l,r);
	printf("%d\n",minn[Key_value]);
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		init(n);
		int m;
		scanf("%d",&m);
		char a[10];
		int x,y,z;
		while(m--)
		{
			scanf("%s",a);
			if(!strcmp(a,"ADD"))
			{
				scanf("%d%d%d",&x,&y,&z);
				if(x>y)swap(x,y);
				Add(x,y,z);
			}
			else if(!strcmp(a,"REVERSE"))
			{
				scanf("%d%d",&x,&y);
				if(x>y)swap(x,y);
				Reverse(x,y);
			}
			else if(!strcmp(a,"REVOLVE"))
			{
				scanf("%d%d%d",&x,&y,&z);
				if(x>y)swap(x,y);
				Revolve(x,y,z);
			}
			else if(!strcmp(a,"INSERT"))
			{
				scanf("%d%d",&x,&y);
				Insert(x,y);
			}
			else if(!strcmp(a,"DELETE"))
			{
				scanf("%d%d",&x);
				Delete(x);
			}
			else if(!strcmp(a,"MIN"))
			{
				scanf("%d%d",&x,&y);
				if(x>y)swap(x,y);
				Query(x,y);
			}
		}
	}
	return 0;
}
			

	
