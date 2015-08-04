#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
const int maxn=500010;
int key[maxn],size[maxn];
int ch[maxn][2],pre[maxn];
int root,tot;
void newnode(int &r,int father,int k)
{
	r=++tot;
	pre[r]=father;
	ch[r][0]=ch[r][1]=0;
	size[r]=1;
	key[r]=k;
}
void push_up(int r)
{
	size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
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
void init()
{
	root=tot=0;
	ch[root][0]=ch[root][1]=0;
	pre[root]=0;
	key[root]=0;
	size[root]=0;
	newnode(root,0,0);
}
int get_kth(int r,int k)
{
	int d=size[ch[r][0]]+1;
	if(d==k)return r;
	else if(k>d)return get_kth(ch[r][1],k-d);
	else return get_kth(ch[r][0],k);
}
void insert(int pos,int k)
{
	splay(get_kth(root,pos+1),0);
	int r=ch[root][1];
	while(ch[r][0])
	{
		r=ch[r][0];
	}
	newnode(ch[r][0],r,k);
	//push_up(r);
	splay(ch[r][0],0);
}
void show(int x)
{
	if(x)
	{
		show(ch[x][0]);
		printf(" %d",key[x]);
		show(ch[x][1]);
	}
}
stack<int> s;
int main()
{
	int n;
	int pos,k;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&pos,&k);
			if(pos<i)
			insert(pos,k);
			else 
			{
				int r=root;
				while(ch[r][1])
				{
					r=ch[r][1];
				}
				newnode(ch[r][1],r,k);
				splay(ch[r][1],0);
			}
		}
		s.clear();
		splay(get_kth(root,2),0);
		printf("%d",key[root]);
		//show(ch[root][1]);
		
		printf("\n");
	}
	return 0;
}
		



