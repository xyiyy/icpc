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

//1st  模仿邝神的代码 
const int maxn=500010;
#define Key_value ch[ch[root][1]][0]
int n,q,a[maxn];
int pre[maxn],ch[maxn][2],key[maxn],size[maxn];
int sum[maxn],re[maxn],same[maxn];
int lx[maxn],rx[maxn],mx[maxn];
int root,tot1,tot2;
int s[maxn];

void newnode(int &r,int father,int k)
{
	if(tot2)r=s[tot2--];
	else r=++tot1;
	pre[r]=father;
	ch[r][0]=ch[r][1]=0;
	key[r]=k;
	sum[r]=k;
	re[r]=same[r]=0;
	lx[r]=rx[r]=mx[r]=k;
	//size[r]=1;
	//cout<<"r : "<<key[r]<<endl;
}
void update_same(int r, int v)
{
	if(!r)return;
	key[r]=v;
	sum[r]=v*size[r];
	lx[r]=rx[r]=mx[r]=max(v,v*size[r]);
	same[r]=1;
}
void update_rev(int r)
{
	if(!r)return ;
	swap(ch[r][0],ch[r][1]);
	swap(lx[r],rx[r]);
	re[r]^=1;
}
void push_up(int r )
{
	int lson=ch[r][0],rson=ch[r][1];
	size[r]=size[lson]+size[rson]+1;
	sum[r]=sum[lson]+sum[rson]+key[r];
	lx[r]=max(lx[lson],sum[lson]+key[r]+max(0,lx[rson]));
	rx[r]=max(rx[rson],sum[rson]+key[r]+max(0,rx[lson]));
	mx[r]=max(0,rx[lson])+key[r]+max(0,lx[rson]);
	mx[r]=max(mx[r],max(mx[lson],mx[rson]));
}
void push_down(int r)
{
	if(same[r])
	{
		update_same(ch[r][0],key[r]);
		update_same(ch[r][1],key[r]);
		same[r]=0;
	}
	if(re[r])
	{
		update_rev(ch[r][0]);
		update_rev(ch[r][1]);
		re[r]=0;
	}
}
	

void build(int &x,int l,int r,int father)
{
	if(l>r)return;
	int mid=(l+r)/2;
	newnode(x,father,a[mid]);
	build(ch[x][0],l,mid-1,x);
	build(ch[x][1],mid+1,r,x);
	push_up(x);
}
void init()
{
	root=tot1=tot2=0;
	ch[root][0]=ch[root][1]=pre[root]=size[root]=same[root]=re[root]=sum[root]=key[root]=0;
	lx[root]=rx[root]=mx[root]=-INF;
	newnode(root,0,-1);
	newnode(ch[root][1],root,-1);
	push_up(root);
	build(Key_value,1,n,ch[root][1]);
	//push_up(root);
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
	if(pre[y])
		ch[pre[y]][ch[pre[y]][1]==y]=x;
	pre[x]=pre[y];
	ch[x][d]=y;
	pre[y]=x;
	push_up(y);
}
void splay(int r,int goal)
{
	push_down(r);
	while(pre[r]!=goal)
	{
		if(pre[pre[r]]==goal)
		{
			//push_down(pre[r]);
			//push_down(r);
			rotate(r,ch[pre[r]][0]==r);
		}
		else 
		{
			//push_down(pre[pre[r]]);
			//push_down(pre[r]);
			//push_down(r);
			int y=pre[r];
			int d=ch[pre[y]][0]==y;
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
	if(goal==0)root=r;
}
		
int get_kth(int r ,int k)
{
	push_down(r);
	int t=size[ch[r][0]]+1;
	if(t==k)return r;
	if(t>k)return get_kth(ch[r][0],k);
	else return get_kth(ch[r][1],k-t);
}
int get_min(int r)
{
	push_down(r);
	while(ch[r][0])
	{
		r=ch[r][0];
		push_down(r);
	}
	return r;
}
void insert(int pos,int tot)
{
	splay(get_kth(root,pos+1),0);
	splay(get_min(ch[root][1]),root);
	build(Key_value,1,tot,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
void erase(int r)
{
	if(!r)return ;
	s[++tot2]=r;
	erase(ch[r][0]);
	erase(ch[r][1]);
}
void del(int pos,int tot)
{
	splay(get_kth(root,pos),0);
	splay(get_kth(root,pos+tot+1),root);
	erase(Key_value);
	pre[Key_value]=0;
	Key_value=0;
	push_up(ch[root][1]);
	push_up(root);
}
void make_same(int pos,int tot,int c)
{
	splay(get_kth(root,pos),0);
	splay(get_kth(root,pos+tot+1),root);
	update_same(Key_value,c);
	push_up(ch[root][1]);
	push_up(root);
}
void rev(int pos,int tot)
{
	splay(get_kth(root,pos),0);
	splay(get_kth(root,pos+tot+1),root);
	update_rev(Key_value);
	//push_up(ch[root][1]);
	//push_up(root);
}
int get_sum(int pos,int tot)
{
	splay(get_kth(root,pos),0);
	splay(get_kth(root,pos+tot+1),root);
	return sum[Key_value];
}
int get_maxsum(int pos,int tot)
{
	splay(get_kth(root,pos),0);
	splay(get_kth(root,pos+tot+1),root);
	return mx[Key_value];
}

void Treavel(int x)
{	
	if(x)
	{
		Treavel(ch[x][0]);
		printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d sum = %2d maxsum=%2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],key[x],sum[x],mx[x]);
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
	ios::sync_with_stdio(false);
	int m,num,k,pos;
	char str[100];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		init();
	//	debug();
		while(m--)
		{
			CLR(str,0);
			scanf("%s",str);
			if(!strcmp(str,"INSERT"))
			{
				scanf("%d%d",&pos,&k);
				for(int i=1;i<=k;i++)
				{
					scanf("%d",&a[i]);
				}
				insert(pos,k);
			}else if(!strcmp(str,"DELETE"))
			{
				scanf("%d%d",&pos,&k);
				del(pos,k);
			}
			else if(!strcmp(str,"MAKE-SAME"))
			{
				scanf("%d%d%d",&pos,&k,&num);
				make_same(pos,k,num);
			}
			else if(!strcmp(str,"REVERSE"))
			{
				scanf("%d%d",&pos,&k);
				rev(pos,k);
			}
			else if(!strcmp(str,"GET-SUM"))
			{
				scanf("%d%d",&pos,&k);
				printf("%d\n",get_sum(pos,k));
			}
			else 
			{
				printf("%d\n",get_maxsum(1,size[root]-2));
			}
			//inorder(root);
			
		}
	}
	return 0;
}


