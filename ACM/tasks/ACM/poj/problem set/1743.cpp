#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
//#include <algorithm>
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
#define MAXN 40010

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[MAXN*2],wb[MAXN*2],wv[MAXN*2],ww[MAXN*2];

int c0(int *r, int a, int b) {
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k, int *r, int a, int b)
{
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}
void rsort(int *r, int *a, int *b, int n, int m) {
    REP(i,n) wv[i]=r[a[i]];
    REP(i,m) ww[i]=0;
    REP(i,n) ww[wv[i]]++;
    REP(i,m-1) ww[i+1]+=ww[i];
    DEP(i,n-1,0) b[--ww[wv[i]]]=a[i];
}

void dc3(int *r, int *sa, int n, int m) {
    int j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    REP(i,n) if(i%3!=0) wa[tbc++]=i;
    rsort(r+2,wa,wb,tbc,m);
    rsort(r+1,wb,wa,tbc,m);
    rsort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,j=1;j<tbc;j++)
        rn[F(wb[j])]=c0(r,wb[j-1],wb[j])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else REP(i,tbc) san[rn[i]]=i;
    REP(i,tbc) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    rsort(r,wb,wa,ta,m);
    REP(i,tbc) wv[wb[i]=G(san[i])]=i;
    int i;
    for(i=j=p=0;i<ta&&j<tbc;p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
}

int ra[MAXN*2], height[MAXN*2];
void calheight(int *r,int *sa,int n) {
    int i,j,k=0;
    for(i=1;i<=n;i++) ra[sa[i]]=i;
    for(i=0;i<n;height[ra[i++]]=k)
        for(k?k--:0,j=sa[ra[i]-1];r[i+k]==r[j+k];k++);
}
/*
int n,k;
int rank[MAXN],tmp[MAXN],height[MAXN],sa[MAXN];
bool cmp(int i,int j){
	if(rank[i]!=rank[j])return rank[i]<rank[j];
	else{
		int ri = i+k <= n ? rank[i+k] : -100;
		int rj = j+k <= n ? rank[j+k] : -100;
		return ri < rj;
	}
}
void build(int len,int *s){
	n=len;  
	for(int   i=0;i<=n;i++)sa[i]=i,rank[i]= i<n ? s[i] : -100;
	for(k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,cmp);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++)tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i]) ? 1 : 0);
		for(int i=0;i<=n;i++)rank[i]=tmp[i];
	}
}
void calheight(int len,int *s){
	n=len;
	for(int i=0;i<=n;i++)rank[sa[i]]=i;
	int h=0;
	height[0]=0;
	for(int i=0;i<=n;i++){
		int j=sa[rank[i]-1];
		if(h>0)h--;
		for(;j+h<n&&i+h<n;h++){
			if(s[i+h]!=s[j+h])break;
		}
		height[rank[i]-1]=h;
	}
}
	*/
int num[MAXN];
int sa[MAXN*2];
int a[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++)scanf("%d",&num[i]);
		//dc3(num,ca,n,88);
		for(int i=1;i<n;i++)a[i-1]=num[i]-num[i-1]+90;
		a[n-1]=0;
		dc3(a,sa,n,180);
		calheight(a,sa,n-1);
		int L=4,R=	MAXN;
		int last,now;
		int minn,maxx;
		int ans=0;
		bool flag;
		while(L<=R){
			int mid=(L+R)>>1;
			now=-1;
			flag=0;
			minn=INF,maxx=-1;
			for(int i=1;i<n;i++){
				if(height[i]<mid)continue;
				for(int j=i-1;j>=1;j--){
					if(abs(sa[i]-sa[j])>=mid){
						flag=1;
						break;
					}
					if(height[j]<mid)break;
				}
				
			}
			if(flag){
				ans=mid;
				L=mid+1;
			}else R=mid-1;
		}
		if(ans>=4)
		printf("%d\n",ans+1);
		else printf("0\n");
	}
	return 0;
}



