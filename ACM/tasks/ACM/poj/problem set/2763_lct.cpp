//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MAXN 400010
int ch[MAXN][2],key[MAXN],pre[MAXN],size[MAXN],ss[MAXN];
int rev[MAXN];
int sum[MAXN];

void push_down(int r){
	if(!r)return;
	if(rev[r]){
		rev[ch[r][0]]^=1;
		rev[ch[r][1]]^=1;
		swap(ch[r][0],ch[r][1]);
		rev[r]=0;
	}
}
void push_up(int r){
	sum[r]=key[r];
	if(pre[ch[r][0]]==r)sum[r]+=sum[ch[r][0]];
	if(pre[ch[r][1]]==r)sum[r]+=sum[ch[r][1]]; 
	//sum[r]=sum[ch[r][0]]+sum[ch[r][1]]+key[r];
}
void rotate(int x,int d){
	int y=pre[x];
	ch[y][!d]=ch[x][d];
	if(ch[x][d])pre[ch[x][d]]=y;
	pre[x]=pre[y];
	if(ch[pre[y]][0]==y)ch[pre[x]][0]=x;
	else if(ch[pre[y]][1]==y)ch[pre[x]][1]=x;
	pre[y]=x;
	ch[x][d]=y;
	push_up(y);
	push_up(x);
}
bool check(int x,int y){
	return y&&(ch[y][0]==x||ch[y][1]==x);
}
void splay(int x){
	push_down(x);
	int y,z;
	while(check(x,y=pre[x])){
		if(check(y,z=pre[y])){
			push_down(z);
			push_down(y);
			push_down(x);
			int d=(y==ch[z][0]);
			if(x==ch[y][d]) {rotate(x,!d),rotate(x,d);}
			else {rotate(y,d),rotate(x,d);}
		}else{
			push_down(y);
			push_down(x);
			rotate(x,ch[y][0]==x);
			break;
		}
	}
	push_up(x);
}
int access(int u){
	int v=0;
	for(;u;u=pre[u]){
		splay(u);
		ch[u][1]=v;
		push_up(v=u);
	}
	splay(u);
	return v;
}
int getroot(int x){
	for(x=access(x);push_down(x),ch[x][0];x=ch[x][0]);
	return x;
}
void makeroot(int x){
	rev[access(x)]^=1;
	splay(x);
}
void link(int x,int y){
	makeroot(x);
	pre[x]=y;
	access(x);
}
void cut(int x,int y){
	//makeroot(x);
	access(y);
	splay(x);
	if(pre[x]==y)pre[x]=0;
	else {
		access(x);
		splay(y);
		pre[y]=0;
	}
}
int u[MAXN],v[MAXN],d[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int n,q,s;
	while(scanf("%d%d%d",&n,&q,&s)!=EOF){
		for(int i=0;i<MAXN;i++){
			key[i]=0;
			sum[i]=0;
			rev[i]=0;
			pre[i]=ch[i][0]=ch[i][1]=0;
		}
		for(int i=0;i<n-1;i++){
			scanf("%d%d%d",u+i,v+i,d+i);
		}
		for(int i=0;i<n-1;i++){
			key[i+n+1]=d[i];
			sum[i+n+1]=d[i];
		}
		for(int i=0;i<n-1;i++){
			link(u[i],i+n+1);
			link(i+n+1,v[i]);
		}
		int last=1;
		for(int i=0;i<q;i++){
			int type;
			int a,b;
			scanf("%d",&type);
			if(type){
				scanf("%d%d",&a,&b);
				makeroot(n+a);
				access(n+a);
				key[n+a]=b;
				sum[n+a]=b;
				splay(n+a);
			}
			else{
				scanf("%d",&a);
				makeroot(last);
				access(a);
				splay(a);
				push_up(a);
				printf("%d\n",sum[a]);
				last=a;
			}
		}
	}
				
			
	return 0;
}

