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
//typedef pair<int,pair<int,int> >PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define MAXN 400010
int num[MAXN],maxx[MAXN],minn[MAXN],sum[MAXN];
int bit[MAXN];
int tot;
void add(int i,int x){
	while(i<=tot){
		bit[i]+=x;
		i+=i&-i;
	}
}
int query(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

void push_up(int rt){
	maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
	minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
	//sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int cur){
	if(l==r){
		maxx[cur]=num[r];
		minn[cur]=num[r];
	//	sum[cur]=num[r];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	push_up(cur);
}
void update(int goal,int l,int r,int cur,int inc){
	if(l==r&&goal==l){
		num[l]+=inc;
		maxx[cur]=num[l];
		minn[cur]=num[l];
	//	sum[cur]=num[l];
		return;
	}
	int mid=(l+r)>>1;
	if(goal<=mid)update(goal,l,mid,cur<<1,inc);
	else update(goal,mid+1,r,cur<<1|1,inc);
	push_up(cur);
}
PII query(int curl,int curr,int l,int r,int cur){
	if(curl<=l&&curr>=r)return MP(maxx[cur],minn[cur]);//MP(maxx[cur],MP(minn[cur],sum[cur]));
	int mid=(l+r)>>1;
	int m=-INF,n=INF,s=0;
	PII temp;
	//pair<int ,int >p;
	if(curl<=mid){
		temp=query(curl,curr,l,mid,cur<<1);
		//p=temp.second;
		m=max(temp.first,m);
		n=min(temp.second,n);
	//	s+=p.second;
	}
	if(curr>mid){
		temp=query(curl,curr,mid+1,r,cur<<1|1);
		//p=temp.second;
		m=max(temp.first,m);
		n=min(temp.second,n);
		//s+=p.second;
	}
	return MP(m,n);//MP(m,MP(n,s));
}
int main(){
	ios::sync_with_stdio(false);
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF){
		REP(i,n)scanf("%d",num+i);
		REP(i,MAXN)bit[i]=0;
		tot=n;
		REP(i,n)add(i+1,num[i]);
		REP(i,MAXN)maxx[i]=-INF,minn[i]=INF,sum[i]=0;
		build(0,n-1,1);
		int x,y,z;
		while(m--){
			scanf("%d%d%d",&x,&y,&z);
			if(x==1){
				update(y-1,0,n-1,1,z);
				add(y,z);
			}
			else if(x==2){
				PII p=query(y-1,z-1,0,n-1,1);
				int ans=query(z)-query(y-1);
				//pair<int,int > t=p.second;
				printf("%d %d %d\n",p.first,ans,p.second);
				//printf("%d %d %d\n",p.first,t.second,t.first);
			}
		}
	}
	return 0;
}


