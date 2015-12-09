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
const int maxn=100010;
const int null=-1;
struct Treap{
	int root,ch[2][maxn],key[maxn],vn[maxn],rd[maxn],size[maxn],tot;
	void init()
	{
		root=null;
		tot=0;
		CLR(size,0);
		CLR(ch,null);
	}
	int newnode(int x)
	{
		//++tot;
		key[tot]=x;
		size[tot]=vn[tot]=1;
		rd[tot]=rand();
		return tot++;
	}
	int cmp(int r,int x)
	{
		if(key[r]==x)return -1;
		return key[r]<x? 0 :1;
	}
	void pushup(int r)
	{
		size[r]=size[ch[0][r]]+size[ch[1][r]]+vn[r];
	}
	void rotate(int &r,int d)
	{
		int k=ch[d^1][r];
		ch[d^1][r]=ch[d][k];
		ch[d][k]=r;
		pushup(r);
		pushup(k);
		r=k;
	}
	void insert(int &r,int x)
	{
		if(r==null)r=newnode(x);
		else{
			int d=cmp(r,x);
			if(d==-1)
			{
				vn[r]++;
				size[r]++;
			}
			else {
				insert(ch[d][r],x);
				if(rd[ch[d][r]]>rd[r])rotate(r,d^1);
			}
		}
		pushup(r);
	}
	void remove (int &r,int x)
	{
		int d=cmp(r,x);
		if(d==-1){
			if(vn[r]>1){
				vn[r]--;
				size[r]--;
			}
			else if(ch[0][r]==null)r=ch[1][r];
			else if(ch[1][r]==null)r=ch[0][r];
			else {
				int d2=(rd[ch[0][r]]>rd[ch[1][r]] ? 1 : 0);
				rotate(r,d2);
				remove(ch[d2][r],x);
			}
		}
		else remove(ch[d][r],x);
		if(r!=null)pushup(r);
	}
	int query(int &r,int k){
		int d=size[ch[1][r]];
		if(k>d&&k<=d+vn[r])return r;
		else if(d>=k)return query(ch[1][r],k);
		else return query(ch[0][r],k-d-vn[r]);
	}
	void del_below(int k,int delta)
	{
		while(1){
			if(size[root]==0)return;
			int d=query(root,1);
			if(key[d]+delta<k)
			{
				remove(root,key[d]);
			}
			else return;
		}
	}
}treap;
		
		
	
	
int main()
{
	ios::sync_with_stdio(false);
	int n,m,b,delta;
	char a[10];
	while(scanf("%d%d",&n,&m)!=EOF){
		treap.init();
		delta=0;
		int num=0;
		for(int i=0;i<n;i++)
		{
			CLR(a,0);
			scanf("%s%d",a,&b);
			if(a[0]=='I')
			{
				if(b>=m){
					treap.insert(treap.root,b-delta);
					num++;
				}
			}
			else if(a[0]=='A')delta+=b;
			else if(a[0]=='S')
			{
				delta-=b;
				treap.del_below(m,delta);
			}
			else{
				if(treap.size[treap.root]<b)printf("-1\n");
				else printf("%d\n",treap.key[treap.query(treap.root,treap.size[treap.root]-b+1)]+delta);
			}
		}
		printf("%d\n",num-treap.size[treap.root]);
	}
			
	return 0;
}


