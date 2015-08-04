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
const int maxn=220000;
int n;
int ch[maxn][2],key[maxn],size[maxn],pre[maxn];
int root,tot;
void newnode(int &r,int father,int k)
{
	r=++tot;
	pre[r]=father;
	key[r]=k;
	size[r]=1;
	ch[r][0]=ch[r][1]=0;
}
void push_up(int r)
{
	size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
}
void init()
{
	root=tot=0;
	ch[root][0]=ch[root][1]=pre[root]=size[root]=0;
	newnode(root,0,-INF);
	newnode(ch[root][1],root,INF);
	push_up(ch[root][1]);
	push_up(root);
}
void rotate(int x,int d)
{
	int y=pre[x];
	ch[y][!d]=ch[x][d];
	pre[ch[x][d]]=y;
	if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
	pre[x]=pre[y];
	pre[y]=x;
	ch[x][d]=y;
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
			int d=(ch[pre[y]][0]==y);
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
}
int get_min(int r)
{
	while(ch[r][0])
	{
		r=ch[r][0];
	}
	return r;
}
int get_max(int r)
{
	while(ch[r][1])r=ch[r][1];
	return r;
}
int minn;
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
void print(int r)
{
	if(r)
	{
		print(ch[r][0]);
		if(r!=minn)printf(" ");
		out(key[r]);
		print(ch[r][1]);
	}
}

int main()
{
//	ios::sync_with_stdio(false);
	int pos,k;
	while(~scanf("%d",&n)&&n>0)
	{
		init();
		for(int i=0;i<n;i++)
		{
			scan_d(pos);
			scan_d(k);
			insert(pos,k);
		}
		splay(get_min(root),0);
		splay(get_max(ch[root][1]),root);
		minn=get_min(Key_value);
		print(Key_value);
		printf("\n");		
	}
	return 0;
}


