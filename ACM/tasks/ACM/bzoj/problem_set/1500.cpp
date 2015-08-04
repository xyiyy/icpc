#include <stdio.h>
using namespace std;
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define Key_value ch[ch[root][1]][0]
const int maxn=500010;
int num[maxn];
int sum[maxn],key[maxn],lsum[maxn],rsum[maxn],add[maxn],ss[maxn],msum[maxn],size[maxn];
int ch[maxn][2],pre[maxn];
bool rev[maxn],same[maxn];
int root,tot,tot2;
void newnode(int &r,int father,int k)
{
	if(tot2)r=ss[--tot2];
	else r=++tot;
	key[r]=k;
	ch[r][0]=ch[r][1]=0;
	rev[r]=same[r]=0;
	add[r]=0;
	size[r]=1;
	lsum[r]=rsum[r]=msum[r]=sum[r]=k;
	pre[r]=father;
}
void update_same(int r,int k)
{
	if(!r)return;
	sum[r]=size[r]*k;
	key[r]=k;
	lsum[r]=msum[r]=rsum[r]=max(k,k*size[r]);
	same[r]=1;
}
void update_rev(int r)
{
	if(!r)return;
	swap(lsum[r],rsum[r]);
	swap(ch[r][0],ch[r][1]);
	rev[r]^=1;
}
void push_up(int x)
{
	int lson=ch[x][0],rson=ch[x][1];
	size[x]=size[lson]+size[rson]+1;
	sum[x]=sum[lson]+sum[rson]+key[x];
	lsum[x]=max(lsum[lson],sum[lson]+key[x]+max(0,lsum[rson]));
	rsum[x]=max(rsum[rson],sum[rson]+key[x]+max(0,rsum[lson]));
	msum[x]=max(max(lsum[rson],0)+key[x]+max(rsum[lson],0),max(msum[lson],msum[rson]));
}
void push_down(int r)
{
	if(same[r])
	{
		update_same(ch[r][0],key[r]);
		update_same(ch[r][1],key[r]);
		same[r]=0;
	}
	if(rev[r])
	{
		update_rev(ch[r][0]);
		update_rev(ch[r][1]);
		rev[r]=0;
	}
}
void build(int &x,int l,int r,int father)
{
	if(l>r)return;
	int mid=(l+r)/2;
	newnode(x,father,num[mid]);
	build(ch[x][0],l,mid-1,x);
	build(ch[x][1],mid+1,r,x);
	push_up(x);
}
void init(int n)
{
	root=tot=tot2=0;
	key[root]=sum[root]=0;
	rsum[root]=lsum[root]=msum[root]=-10000;
	size[root]=rev[root]=same[root]=add[root]=0;
	pre[root]=0;
	ch[root][0]=ch[root][1]=0;
	newnode(root,0,-1);
	newnode(ch[root][1],root,-1);
	build(Key_value,1,n,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
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
	push_up(x);
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
int get_kth(int r,int k)
{
	push_down(r);
	int d=size[ch[r][0]]+1;
	if(d==k)return r;
	else if(d<k)return get_kth(ch[r][1],k-d);
	else return get_kth(ch[r][0],k);
}
void get_interval(int l,int t)
{
	splay(get_kth(root,l),0);
	splay(get_kth(ch[root][1],t),root);
}
void Insert(int pos,int t)
{
	get_interval(pos+1,1);
	build(Key_value,1,t,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
void erase(int r)
{
	if(!r)return;
	ss[tot2++]=r;
	erase(ch[r][0]);
	erase(ch[r][1]);
}
void Delete(int pos,int t)
{
	get_interval(pos,t+1);
	erase(Key_value);
	Key_value=0;
	push_up(ch[root][1]);
	push_up(root);
}
void Make_same(int pos,int t,int k)
{
	get_interval(pos,t+1);
	update_same(Key_value,k);
	push_up(ch[root][1]);
	push_up(root);
}
void Reverse(int pos,int t)
{
	get_interval(pos,t+1);
	update_rev(Key_value);
}
void Get_sum(int pos,int t)
{
	get_interval(pos,t+1);
	printf("%d\n",sum[Key_value]);
}
int get_min()
{
	int r=root;
	while(ch[r][0])
	{
		push_down(r);
		r=ch[r][0];
	}
	return r;
}
int get_max()
{
	int r=root;
	while(ch[r][1])
	{
		push_down(r);
		r=ch[r][1];
	}
	return r;
}
void Max_sum()
{
	get_interval(1,size[root]-1);
	printf("%d\n",msum[Key_value]);
}
void Treavel(int x)
{	
	if(x)
	{
		Treavel(ch[x][0]);
		printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d sum = %2d maxsum=%2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],key[x],sum[x],msum[x]);
		printf("lsum %d   rsum%d\n",lsum[x],rsum[x]);
		Treavel(ch[x][1]);
	}
}
void debug()
{
	printf("root%d\n",root);
	Treavel(root);
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
		char a[50];
		int pos,t,k;
		while(m--)
		{
			scanf("%s",a);
			if(!strcmp(a,"INSERT"))
			{
				scanf("%d%d",&pos,&t);
				for(int i=1;i<=t;i++)
				{	
					scanf("%d",&num[i]);
				}
				Insert(pos,t);
			}
			else if(!strcmp(a,"DELETE"))
			{
				scanf("%d%d",&pos,&t);
				Delete(pos,t);
			}
			else if(!strcmp(a,"MAKE-SAME"))
			{
				scanf("%d%d%d",&pos,&t,&k);
				Make_same(pos,t,k);
			}
			else if(!strcmp(a,"REVERSE"))
			{
				scanf("%d%d",&pos,&t);
				Reverse(pos,t);
			}
			else if(!strcmp(a,"GET-SUM"))
			{
				scanf("%d%d",&pos,&t);
				Get_sum(pos,t);
			}
			else 
			{
				Max_sum();
			}
		}
	}
	return 0;
}



