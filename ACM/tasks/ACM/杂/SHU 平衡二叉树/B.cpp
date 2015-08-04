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
#define N 100005
struct SBT{
	int left,right,size,key;
	void init()
	{
		left=right=key=0;
		size=1;
	}
}sbt[N];
int root,tot;
void left_rot(int &x){
	int k=sbt[x].right;
	sbt[x].right=sbt[k].left;
	sbt[k].left=x;
	sbt[k].size=sbt[x].size;
	sbt[x].size=sbt[sbt[x].left].size+sbt[sbt[x].right].size+1;
	x=k;
}
void right_rot(int &x){
	int k=sbt[x].left;
	sbt[x].left=sbt[k].right;
	sbt[k].right=x;
	sbt[k].size=sbt[x].size;
	sbt[x].size=sbt[sbt[x].left].size+sbt[sbt[x].right].size+1;
	x=k;
}
void maintain(int &r,bool flag)
{
	if(flag)
	{
		if(sbt[sbt[sbt[r].right].right].size>sbt[sbt[r].left].size)
			left_rot(r);
		else if(sbt[sbt[sbt[r].right].left].size>sbt[sbt[r].left].size)
		{
			right_rot(sbt[r].right);
			left_rot(r);
		}
		else 
			return ;
	}
	else {
		if(sbt[sbt[sbt[r].left].left].size>sbt[sbt[r].right].size)
			right_rot(r);
		else if(sbt[sbt[sbt[r].left].right].size>sbt[sbt[r].right].size)
		{
			left_rot(sbt[r].left);
			right_rot(r);
		}
		else 
			return;
	}
	maintain(sbt[r].left,false);
	maintain(sbt[r].right,true);
	maintain(r,false);
	maintain(r,true);
}

void insert(int &r,int k)
{
	if(r==0){
		r=++tot;
		sbt[r].init();
		sbt[r].key=k;
	}
	else 
	{
		sbt[r].size++;
		if(k<sbt[r].key)
			insert(sbt[r].left,k);
		else 
			insert(sbt[r].right,k);
		maintain(r,k>=sbt[r].key);		
	}
}
void del(int &r,int delay,int m){
	if(!r)return;
	if(sbt[r].key+delay<m){
		r=sbt[r].right;
		del(r,delay,m);
	}
	else 
	{
		del(sbt[r].left,delay,m);
		sbt[r].size=sbt[sbt[r].right].size+sbt[sbt[r].left].size+1;
	}
}
int query(int &r,int k){
	int t=sbt[sbt[r].right].size+1;
	if(t==k)return sbt[r].key;
	if(t<k)return query(sbt[r].left,k-t);
	else   return query(sbt[r].right,k);
}

int main()
{
	//ios::sync_with_stdio(false);
	int n,m,delay,b;
	char str[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		tot=root=delay=0;
		for(int i=0;i<n;i++)
		{
			CLR(str,0);
			scanf("%s%d",str,&b);
			if(str[0]=='I')
			{
				if(b>=m)insert(root,b-delay);
			}
			else if(str[0]=='A')delay+=b;
			else if(str[0]=='S')
			{
				delay-=b;
				del(root,delay,m);
			}
			else if(str[0]=='F')
			{
				if(sbt[root].size<b)printf("-1\n");
				else printf("%d\n",query(root,b)+delay);
			}
		}
		printf("%d\n",tot-sbt[root].size);
	}
	return 0;
}


