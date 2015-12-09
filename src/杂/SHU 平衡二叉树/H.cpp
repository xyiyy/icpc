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
const int maxn=220000;
const int INF=0x3f3f3f3f;
int n,m,a[maxn],tot1,tot2,root;
int ch[maxn][2],rev[maxn],key[maxn],size[maxn],add[maxn],minn[maxn],ss[maxn],pre[maxn];
void newnode(int &r,int father,int k)
{
	if(tot2)r=ss[tot2--];
	else r=++tot1;
	pre[r]=father;
	key[r]=minn[r]=k;
	ch[r][0]=ch[r][1]=rev[r]=add[r]=0;
	size[r]=1;
}
void erase(int r)
{
	if(!r)return ;
	ss[++tot2]=r;
	erase(ch[r][0]);
	erase(ch[r][1]);
}
void update_rev(int r)
{
	if(!r)return ;
	swap(ch[r][0],ch[r][1]);
	rev[r]^=1;
}
void update_add(int r,int d)
{
	if(!r)return ;
	add[r]+=d;
	minn[r]+=d;
	key[r]+=d;
}
void push_up(int r)
{
	//int ch[r][0]=ch[r][0],ch[r][1]=ch[r][1];
	size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
	minn[r]=key[r];
	if(ch[r][0])minn[r]=min(minn[ch[r][0]],minn[r]);
	if(ch[r][1])minn[r]=min(minn[r],minn[ch[r][1]]);
}
void push_down(int r)
{
	if(rev[r])
	{
		update_rev(ch[r][0]);
		update_rev(ch[r][1]);
		rev[r]=0;
	}
	if(add[r])
	{
		update_add(ch[r][0],add[r]);
		update_add(ch[r][1],add[r]);
		add[r]=0;
	}
}
void build(int &x,int l,int r, int father)
{
	if(l>r)return; 
	int mid=(l+r)/2;
	newnode(x,father ,a[mid]);
	build(ch[x][0],l,mid-1,x);
	build(ch[x][1],mid+1,r,x);
	push_up(x);
}

void init()
{
	root=tot1=tot2=0;
	ch[root][0]=ch[root][1]=pre[root]=size[root]=0;
	minn[root]=key[root]=INF;
	newnode(root,0,INF);
	newnode(ch[root][1],root,INF);
//	push_up(root);
	//cout<<"ok"<<rl;
	build(Key_value,1,n,ch[root][1]);
//	cout<<"ok"<<rl;
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

int get_kth(int r,int k)
{
	push_down(r);
	int d=size[ch[r][0]]+1;
	if(d==k)return r;
	else if(d<k)return get_kth(ch[r][1],k-d);
	else return get_kth(ch[r][0],k);
	
}
void insert(int r,int k)
{
	splay(get_kth(root,r+1),0);
	splay(get_kth(root,r+2),root);
	newnode(Key_value,ch[root][1],k);
	push_up(ch[root][1]);
	push_up(root);
}/*
int get_min(int r, int k)
{
	push_down(r);
	while(ch[r][0])
	{
		r=ch[r][0];
		push_down(r);
	}
	return r;
}*/
void get_add(int l,int r,int d)
{
	splay(get_kth(root,l),0);
	splay(get_kth(root,r+2),root);
	update_add(Key_value,d);
	push_up(ch[root][1]);
	push_up(root);
}
void revolve(int l,int r,int d)
{
	int len=r-l+1;
	d=(d%len+len)%len;
	if(d==0)return;
	int t=r-d+1;
	splay(get_kth(root,t),0);
	splay(get_kth(root,r+2),root);
	int temp=Key_value;
	Key_value=0;
	push_up(ch[root][1]);//艹，更新！！！ 
	push_up(root);
	
	splay(get_kth(root,l),0);
	splay(get_kth(root,l+1),root);
	Key_value=temp;
	pre[Key_value]=ch[root][1];
	push_up(ch[root][1]);
	push_up(root);
}
void Reverse(int l,int r)
{
	splay(get_kth(root,l),0);
	splay(get_kth(root,r+2),root);
	update_rev(Key_value);
	push_up(ch[root][1]);
	push_up(root);
}

void Delete(int l)
{
	splay(get_kth(root,l),0);
	splay(get_kth(root,l+2),root);
	erase(Key_value);
	pre[Key_value]=0;
	Key_value=0;
	push_up(ch[root][1]);
	push_up(root);
}
void get_Min(int l,int r)
{
	splay(get_kth(root,l),0);
	splay(get_kth(root,r+2),root);
	printf("%d\n",minn[Key_value]);
//	return minn[Key_value];
}
/*
void Treavel(int x)
{	
	if(x)
	{
		Treavel(ch[x][0]);
		printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d \n",x,ch[x][0],ch[x][1],pre[x],size[x],key[x]);
		Treavel(ch[x][1]);
	}
}
void debug()
{
	printf("root%d\n",root);
	Treavel(root);
}*/
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
int main()
{
//	ios::sync_with_stdio(false);
	int l,r,d;
	char str[100];
	//scanf("%d",&n);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			//scanf("%d",a+i);
			scan_d(a[i]);
		//	getchar();
		}
		//cout<<"ok"<<rl;
		init();
		scan_d(m);
		//scanf("%d",&m);
		while(m--)
		{
			scanf("%s",str);
			if(strcmp(str,"ADD")==0)
			//if(str[0]=='A')
			{
				scan_d(l);
				scan_d(r);
				scan_d(d);
				//scanf("%d%d%d",&l,&r,&d);
				if(l>r)swap(l,r);
				get_add(l,r,d);
			}
			 else if(strcmp(str,"REVERSE")==0)
			//else if(str[3]=='E')
			{
				scan_d(l);
				scan_d(r);
				//scanf("%d%d",&l,&r);
				if(l>r)swap(l,r);
				Reverse(l,r);
			}
			else if(strcmp(str,"REVOLVE")==0)
			//else if(str[3]=='O')
			{
				scan_d(l);
				scan_d(r);
				scan_d(d);
				//scanf("%d%d",&l,&r,&d);
				if(l>r)swap(l,r);
				revolve(l,r,d);
			}
			else if(strcmp(str,"INSERT")==0)
			//else if(str[0]=='I')
			{
				scan_d(l);
				scan_d(d);
				//scanf("%d%d",&l,&d);
				insert(l,d);
			}
			else if(strcmp(str,"DELETE")==0)
			//else if(str[0]=='D')
			{
				scan_d(l);
				//scanf("%d",&l);
				Delete(l);
			}
			else if(strcmp(str,"MIN")==0)
			//else if(str[0]=='M')
			{
				scan_d(l);
				scan_d(r);
				//out(get_Min(l,r));
				//putchar('\n');
				//scanf("%d%d",&l,&r);
				if(l>r)swap(l,r);
				get_Min(l,r);
			//	printf("%d\n",get_Min(l,r));
			}
			
			//debug();
		}
	}	 
	return 0;
}


