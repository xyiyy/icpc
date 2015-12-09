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
#define MAXN 100010
int ch[MAXN][2],key[MAXN],pre[MAXN],size[MAXN],ss[MAXN];
int rev[MAXN];
void push_down(int r){
	if(!r)return;
	if(rev[r]){
		rev[ch[r][0]]^=1;
		rev[ch[r][1]]^=1;
		swap(ch[r][0],ch[r][1]);
		rev[r]=0;
	}
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
}
int access(int u){
	int v=0;
	for(;u;u=pre[u]){
		splay(u);
		ch[u][1]=v;
		v=u;
	}
	//splay(u);
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
	makeroot(x);
	access(y);
	splay(y);
	pre[ch[y][0]]=0;
	ch[y][0]=0;
}
void init(int n){
	for(int i=0;i<=n;i++)
		ch[i][0]=ch[i][1]=pre[i]=0;
}
void query(int x,int y){
	int ra=getroot(x);
	int rb=getroot(y);
	if(ra==rb&&ra)printf("Yes\n");
	else printf("No\n");
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init(n);
		int x,y;
		char a[110];
		for(int i=0;i<m;i++){
			scanf("%s%d%d",a,&x,&y);
			if(a[0]=='C')link(x,y);
			else if(a[0]=='D')cut(x,y);
			else query(x,y);
		}
	}
	return 0;
}



