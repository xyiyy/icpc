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
const int maxn=1000010;
int key[maxn],ss[maxn],num[maxn],ch[maxn][2],pre[maxn];
int root,tot1,tot2;
void newnode(int &r,int father,int k,int n)
{
	if(tot2)r=ss[tot2--];
	else r=++tot1;
	pre[r]=father;
	key[r]=k;
	num[r]=n;
	ch[r][0]=ch[r][1]=0;
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
}
void splay(int r,int goal)
{
	while(pre[r]!=goal)
	{
		if(pre[pre[r]]==goal)
			rotate(r,ch[pre[r]][0]==r);
		else 
		{
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
	if(goal==0)root=r;
}
int insert(int k,int n)
{
	int r=root;
	while(ch[r][k>key[r]])
	{
		r=ch[r][k>key[r]];
	}
	//printf("%d\n",r);
	newnode(ch[r][k>key[r]],r,k,n);
//	splay(ch[r][k>key[r]],0);
}
int get_min(int r)
{
	int d=r;
	while(ch[d][0])
	{
		d=ch[d][0];
	}
	return d;
}
int get_max(int r)
{
	int d=r;
	while(ch[d][1])
	{
		d=ch[d][1];
	}
	return d;
}
void erase(int k)
{
	ss[++tot2]=k;
	int y=pre[k];
//	if(root==k)root=ch[y][ch[y][0]==y];
	ch[y][ch[y][1]==y]=0;
	pre[k]=0;
}
void init()
{
	root=tot1=tot2=0;
	ch[root][0]=ch[root][1]=pre[root]=0;
	newnode(root,0,-INF,0);
	newnode(ch[root][1],root,INF,0);
}
int main()
{
	ios::sync_with_stdio(false);
	int x,y,z;
	int size=0;
	int k;
	//init();
	while(scanf("%d",&x)!=EOF)
	{
		if(x==0)break;
		else if(x==1)
		{
			scanf("%d%d",&y,&z);
			//printf("%d\n",key[root]);
			if(!size)
			{
				//root=1;
				newnode(root,0,z,y);
			}
			else 
			insert(z,y);
			size++;
			
		}
		else if(x==2)
		{
			if(!size)
			{
				printf("0\n");
			}
			else 
			{
				k=get_max(root);
				splay(pre[k],0);
				splay(k,ch[root][key[k]>key[pre[k]]]);
				printf("%d\n",num[k]);
				erase(k);
				//printf("%d\n",k);
				size--;
			}
		}
		else if(x==3)
		{
			if(!size)
			{
				printf("0\n");
			}
			else 
			{
				cout<<key[ch[root][0]]<<endl;
				
			//	printf("%d %d\n",num[root],key[root]);
				k=get_min(root);
			//	printf("%d\n",k);
				splay(pre[k],0);
				splay(k,ch[root][key[k]>key[pre[k]]]);
				//printf("ok\n");
				printf("%d\n",num[k]);
				erase(k);
				size--;
			}
		}
	}
	return 0;
}


