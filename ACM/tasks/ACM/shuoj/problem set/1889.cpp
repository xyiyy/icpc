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
int key[MAXN],size[MAXN],lson[MAXN],rson[MAXN];
int sum[MAXN];
int p[MAXN];
int del[MAXN];
int tmp[10];
int tot=0,tot1=0;
void init(){
	key[0]=size[0]=lson[0]=rson[0]=0;
	tot=0;
}
int newnode(int k){
	int r;
	if(tot1){
		r=del[tot1--];
	}else r=++tot;
	key[r]=k;
	sum[r]=k;
	p[r]=rand();
	size[r]=1;
	lson[r]=rson[r]=0;
	return r;
}
int change(int t,int l,int r){
	size[t]=size[l]+size[r]+1;
	sum[t]=sum[l]+sum[r]+key[t];
	lson[t]=l;
	rson[t]=r;
	return t;
}
void splitsize(int t,int s,int *ret){
	if(s<=0){
		ret[0]=0;
		ret[1]=t;
	}else if(s<=size[lson[t]]){
		splitsize(lson[t],s,ret);
		ret[1]=change(t,ret[1],rson[t]);
	}else {
		splitsize(rson[t],s-size[lson[t]]-1,ret);
		ret[0]=change(t,lson[t],ret[0]);
	}
}
void splitkey(int t,int k,int *ret){
	if(!t){
		ret[0]=ret[1]=0;
	}else if(k<key[t]){
		splitkey(lson[t],k,ret);
		ret[1]=change(t,ret[1],rson[t]);
	}else {
		splitkey(rson[t],k,ret);
		ret[0]=change(t,lson[t],ret[0]);
	}
}
int merge(int t1,int t2){
	if(!t1)return t2;
	if(!t2)return t1;
	if(p[t1]<p[t2])return change(t1,lson[t1],merge(rson[t1],t2));
	return change(t2,merge(t1,lson[t2]),rson[t2]);
}	
int num[MAXN];
int id[MAXN];	
void build(int l,int r,int &x){
	if(l>r)return;
	int mid=(l+r)>>1;
	x=newnode(num[mid]);
	build(l,mid-1,lson[x]);
	build(mid+1,r,rson[x]);
	change(x,lson[x],rson[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int root=0;
		init();
		for(int i=0;i<n;i++){
			scanf("%d",num+i);
		}
		build(0,n-1,root);
		int type=0;
		int x,y,z;
		for(int i=0;i<m;i++){
			scanf("%d",&type);
			if(type==2){
				scanf("%d%d%d",&x,&y,&z);
				if(z>y){
					splitsize(root,z,tmp);
					splitsize(tmp[0],y,tmp+2);
					splitsize(tmp[2],x-1,tmp+4);
					tmp[2]=merge(tmp[3],tmp[5]);
					tmp[0]=merge(tmp[2],tmp[1]);
					root=merge(tmp[4],tmp[0]);
				}else{
					splitsize(root,y,tmp);
					splitsize(tmp[0],x-1,tmp+2);
					splitsize(tmp[2],z,tmp+4);
					tmp[2]=merge(tmp[4],tmp[3]);
					tmp[0]=merge(tmp[2],tmp[5]);
					root=merge(tmp[0],tmp[1]);
				}
			}else{
				scanf("%d%d",&x,&y);
				splitsize(root,y,tmp);
				splitsize(tmp[0],x-1,tmp+2);
				printf("%d\n",sum[tmp[3]]);
				tmp[0]=merge(tmp[2],tmp[3]);
				root=merge(tmp[0],tmp[1]);
			}
		}
	}
	return 0;
}



