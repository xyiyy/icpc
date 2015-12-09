#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=500010;
#define INF 2000000000
int key[maxn],ch[maxn][2],pre[maxn];
int root,tot;
void newnode(int &r,int father,int k)
{
	r=++tot;
	pre[r]=father;
	ch[r][0]=ch[r][1]=0;
	key[r]=k;
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
	if(goal==0)root=x;
}
void init()
{
	root=tot=0;
	key[root]=ch[root][0]=ch[root][1]=pre[root]=0;
	//newnode(root,0,-INF);
//	newnode(ch[root][1],root,INF);
}
bool insert(int k)
{
	int r=root;
	//if(key[r]==k)return 0;
	while(ch[r][k>key[r]])
	{	
		if(key[r]==k)
		{
			splay(r,0);
			return 0;
		}
		r=ch[r][k>key[r]];
	}
	newnode(ch[r][k>key[r]],r,k);
	splay(ch[r][k>key[r]],0);
	return 1;
}
	
	
int get_next()
{
	int x=ch[root][1];
	while(ch[x][0])
	{
		x=ch[x][0];
	}
	return x;
}
int get_pre()
{
	int x=ch[root][0];
	while(ch[x][1])
	{
		x=ch[x][1];
	}
	return x;
}
	
#define Key_value ch[ch[root][1]][0]	
int main()
{	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int k;
		init();
		int cas=0;
		long long sum=0;
		while(n--)
		{
			k=0;
			scanf("%d",&k);
			if(!cas)
			{
				newnode(root,0,k);
				//newnode(Key_value,ch[root][1],k);
				sum+=k;
			}
			else
			{
				if(!insert(k))continue;
				int r1=get_pre();
				int r2=get_next();
				//if(!insert(k))continue;
			//	printf("%d    %d\n",key[r1],key[r2]);
				if(r1==0)sum+=abs(key[r2]-k);
				else if(r2==0)sum+=abs(key[r1]-k);
				else 
				{
					sum+=min(abs(key[r1]-k),abs(key[r2]-k));
				}
			}
		//	printf("%d\n",sum);
			cas++;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
