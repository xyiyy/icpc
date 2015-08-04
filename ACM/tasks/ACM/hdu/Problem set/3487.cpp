#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define Key_value ch[ch[root][1]][0]
const int maxn=300010;
int key[maxn],rev[maxn],ch[maxn][2],pre[maxn];
int size[maxn];
int tot,root;
void newnode(int &r,int father,int k)
{
	r=++tot;
	key[r]=k;
	ch[r][0]=ch[r][1]=0;
	size[r]=1;
	rev[r]=0;
	pre[r]=father;
}
void update_rev(int r)
{
	if(!r)return ;
	//swap(ch[r][0],ch[r][1]);
	rev[r]^=1;
}
void push_down(int r)
{
	if(rev[r])
	{
		swap(ch[r][0],ch[r][1]);
		update_rev(ch[r][0]);
		update_rev(ch[r][1]);
		rev[r]=0;
	}
}
void push_up(int r)
{
	size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
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
	ch[x][d]=y;
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
	if(l>r)return;
	int mid=(l+r)/2;
	newnode(x,fa,mid);
	build(ch[x][0],l,mid-1,x);
	build(ch[x][1],mid+1,r,x);
	push_up(x);
}
void init(int n)
{
	root=tot=0;
	size[root]=key[root]=rev[root]=0;
	ch[root][0]=ch[root][1]=pre[root]=0;
	newnode(root,0,0);
	newnode(ch[root][1],root,n+1);
	build(Key_value,1,n,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
int get_kth(int r,int k)
{
	push_down(r);
	int d=size[ch[r][0]]+1;
	if(d==k)return r;
	else if(d<k)return get_kth(ch[r][1],k-d);
	else return get_kth(ch[r][0],k);
}
void get_interval(int l,int r)
{
	splay(get_kth(root,l),0);
	splay(get_kth(root,r+2),root);
}
void Cut(int l,int r,int pos)
{
	get_interval(l,r);
	int temp=Key_value;
	Key_value=0;
	push_up(ch[root][1]);
	push_up(root);
	splay(get_kth(root,pos+1),0);
	splay(get_kth(ch[root][1],1),root);
	//printf("%d",key[ch[root][1]]);
	pre[temp]=ch[root][1];
	Key_value=temp;
	push_up(ch[root][1]);
	push_up(root);
}
void Flip(int l,int r)
{
	get_interval(l,r);
	update_rev(Key_value);
}
bool scan_d(int &ret){
	char c;int sgn;
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9')
	{
		ret=ret*10+(c-'0');
	}
	ret*=sgn;
	return 1;
}
void out(int x)
{
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
bool flag=0;
void show(int x)
{
	if(x)
	{
		push_down(x);
		show(ch[x][0]);
		if(flag)printf(" ");
		//if(flag)putchar(' ');
		//out(key[x]);
		printf("%d",key[x]);
		flag=1;
		show(ch[x][1]);
	}
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==-1&&m==-1)break;
		char a[10];
		int l,r,pos;
		init(n);
		flag=0;
		while(m--)
		{
			scanf("%s",a);
			if(!strcmp(a,"CUT"))
			{
				scanf("%d%d%d",&l,&r,&pos);
			//	scan_d(l);
			//	scan_d(r);
			//	scan_d(pos);
				Cut(l,r,pos);
			}
			else 
			{
				scanf("%d%d",&l,&r);
				//scan_d(l);
				//scan_d(r);
				Flip(l,r);
			}
		}
		splay(get_kth(root,1),0);
		splay(get_kth(root,n+2),root);
		show(Key_value);
		printf("\n");
		//puts("");
	}
	return 0;
}
