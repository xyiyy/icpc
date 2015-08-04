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
#define MAXN 700010
int key[MAXN],sum[MAXN],rx[MAXN],lx[MAXN],rev[MAXN],mx[MAXN],size[MAXN];
int tot,tot1;
int lson[MAXN],rson[MAXN];
bool same[MAXN];
int del[MAXN];
int p[MAXN];
int tmp[110];
int root=0;
int newnode(int k){
	int r;
	if(tot1)r=del[--tot1];
	else r=++tot;
	key[r]=k;
	rx[r]=lx[r]=sum[r]=mx[r]=k;
	rev[r]=0;
	same[r]=0;
	p[r]=rand();
	lson[r]=rson[r]=0;
	size[r]=1;
	return r;
}
void init(){
	key[0]=size[0]=lson[0]=rson[0]=sum[0]=0;
	lx[0]=rx[0]=mx[0]=0;
	tot=0;tot1=0;
}
void update_same(int t,int v){
	if(!t)return ;
	key[t]=v;
	sum[t]=v*size[t];
	lx[t]=rx[t]=mx[t]=max(v,v*size[t]);
	same[t]=1;
}
void update_rev(int t){
	if(!t)return ;
	swap(lson[t],rson[t]);
	swap(lx[t],rx[t]);
	rev[t]^=1;
}
int change(int t,int l,int r){
	size[t]=size[l]+size[r]+1;
	sum[t]=sum[l]+sum[r]+key[t];
	lson[t]=l;
	rson[t]=r;
	lx[t]=max(lx[l],sum[l]+key[t]+max(0,lx[r]));
	rx[t]=max(rx[r],sum[r]+key[t]+max(0,rx[l]));
	mx[t]=max(0,rx[l])+key[t]+max(0,lx[r]);
	mx[t]=max(mx[t],max(mx[l],mx[r]));
	return t;
}
void pushdown(int t){
	if(same[t]){
		update_same(lson[t],key[t]);
		update_same(rson[t],key[t]);
		same[t]=0;
	}
	if(rev[t]){
		update_rev(lson[t]);
		update_rev(rson[t]);
		rev[t]=0;
	}
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
void splitkey(int t ,int k,int *ret){
	if(!t){
		ret[0]=ret[1]=0;
	}else if(k<key[t]){
		pushdown(t);
		splitkey(lson[t],k,ret);
		ret[1]=change(t,ret[1],rson[t]);
	}else {
		pushdown(t);
		splitkey(rson[t],k,ret);
		ret[0]=change(t,lson[t],ret[0]);
	}
}
int merge(int t1,int t2){
	if(!t1)return t2;
	if(!t2)return t1;
	if(p[t1]<p[t2]){
		pushdown(t1);
		return change(t1,lson[t1],merge(rson[t1],t2));
	}
	pushdown(t2);
	return change(t2,merge(t1,lson[t2]),rson[t2]);
}
int num[MAXN];
void get_sum(){
	int l,len;
	scanf("%d%d",&l,&len);
	splitsize(root,l-1,tmp);
	splitsize(tmp[1],len,tmp+2);
	printf("%d\n",sum[tmp[2]]);
	tmp[1] = merge(tmp[2],tmp[3]);
	root = merge(tmp[0],tmp[1]);
}
void Insert(){
	int n,m;
	scanf("%d%d",&n,&m);
	splitsize(root,n,tmp);
	int temp;
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		tmp[0]=merge(tmp[0],newnode(temp));
	}
	root=merge(tmp[0],tmp[1]);
}
void make_same(){
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	splitsize(root,x-1,tmp);
	splitsize(tmp[1],y,tmp+2);
	update_same(tmp[2],z);
	tmp[1]=merge(tmp[2],tmp[3]);
	root=merge(tmp[0],tmp[1]);
}
void make_rev(){
	int x,y;
	scanf("%d%d",&x,&y);
	splitsize(root,x-1,tmp);
	splitsize(tmp[1],y,tmp+2);
	update_rev(tmp[2]);
	tmp[1]=merge(tmp[2],tmp[3]);
	root=merge(tmp[0],tmp[1]);
}
void update_del(int r){
	if(!r)return ;
	del[tot1++]=r;
	update_del(lson[r]);
	update_del(rson[r]);
}
void Del(){
	int x,y;
	scanf("%d%d",&x,&y);
	splitsize(root,x-1,tmp);
	splitsize(tmp[1],y,tmp+2);
	update_del(tmp[2]);
	root=merge(tmp[0],tmp[3]);
}
void max_sum(){
	printf("%d\n",mx[root]);
}	
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)scanf("%d",num+i);
		init();
		root=0;
		for(int i=0;i<n;i++)
			if(!root)root=newnode(num[i]);
			else root=merge(root,newnode(num[i]));
		char str[110];
		for(int i=0;i<m;i++){
			scanf("%s",str);
			if(!strcmp(str,"GET-SUM")){
				get_sum();
			}else if(!strcmp(str,"MAX-SUM")){
				max_sum();
			}else if(!strcmp(str,"INSERT")){
				Insert();
			}else if(!strcmp(str,"DELETE")){
				Del();
			}else if(!strcmp(str,"MAKE-SAME")){
				make_same();
			}else if(!strcmp(str,"REVERSE")){
				make_rev();
			}
		}
	}
	return 0;
}



