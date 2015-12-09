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
int key[MAXN],size[MAXN],pa[MAXN],lson[MAXN],rson[MAXN];
int rev[MAXN];
int p[MAXN];
int init(int n){
	for(int i=0;i<=n;i++)
	key[i]=size[i]=lson[i]=pa[i]=rson[i]=0,p[i]=rand();
}
int change(int t,int l,int r){
	size[t]=size[l]+size[r]+1;
	if(l)
	pa[l]=t;
	if(r)pa[r]=t;
	lson[t]=l;
	rson[t]=r;
	return t;
}
//void update_rev(int t){
//	if(t){
//		rev[t]^=1;
//		swap(lson[t],rson[t]);
//		swap(size[lson[t]],size[rson[t]]);
//	}
//}
int pushdown(int t){
	if(!t)return t;
	if(rev[t]){
		rev[lson[t]]^=1;
		rev[rson[t]]^=1;
		swap(lson[t],rson[t]);
		rev[t]=0;
	}
	return t;
}
		
int merge(int t1,int t2){
	if(!t1)return t2;
	if(!t2)return t1;
	if(pa[t1]<p[t2]){
		pushdown(t1);
		return change(t1,lson[t1],merge(rson[t1],t2));
	}
	pushdown(t2);
	return change(t2,merge(t1,lson[t2]),rson[t2]);
}
void push_down(int t){
	if(lson[pa[t]]==t||rson[pa[t]]==t)push_down(pa[t]);
	pushdown(t);
}
int split(int t){
	push_down(t);
	int tmp[2];
	tmp[1]=rson[t];
	tmp[0]=change(t,lson[t],0);
	int tmproot=t;
	for(;;){
		if(lson[pa[t]]==t){
			t=pa[t];
			tmp[1]=change(t,tmp[1],rson[t]);
		}else if(rson[pa[t]]==t){
			t=pa[t];
			tmp[0]=change(t,lson[t],tmp[0]);
		}else{
			pa[tmp[0]]=pa[t];
			pa[tmp[1]]=tmproot;
			return tmp[0];
		}
	}
}	
int access(int t){
	int last=0;
	int tmp;
	for(;t;){
		tmp=split(t);
		t=pa[tmp];
		last=merge(tmp,last);
	}
	pa[last]=0;
	return last;
}
int make_root(int t){
	int ret=access(t);
	rev[ret]^=1;
	//update_rev(ret);
	return ret;
}
int get_root(int t){
	for(t=access(t);lson[pushdown(t)];t=lson[t]);
	return t;
}
void link(int x,int y){
	x=make_root(x);
	pa[x]=y;
	access(x);
}
void cut(int x,int y){
	make_root(x);
	access(y);
	int tmp=split(y);
}
void query(int u,int v){
	int ra=get_root(u);
	int rb=get_root(v);
	if(ra==rb&&ra)printf("YES\n");
	else printf("NO\n");
}
	

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		char a[110];
		init(n);
		int u,v;
		for(int i=0;i<m;i++){
			scanf("%s",a);
			scanf("%d%d",&u,&v);
			if(a[0]=='C')	link(u,v);
			else if(a[0]=='D')	cut(u,v);
			else query(u,v);
		}
	}
	return 0;
}



