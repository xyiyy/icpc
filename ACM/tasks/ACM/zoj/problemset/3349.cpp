#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define MAXN 100010
int a[MAXN],b[MAXN],maxx[MAXN*3];
int p[MAXN],c[MAXN];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	int n,d;
	while(scanf("%d%d",&n,&d)!=EOF){
		memset(maxx,0,sizeof(maxx));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			p[i]=i;
		}
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++)b[i]=a[p[i]];
		c[p[0]]=0;
		for(int i=1;i<n;i++){
			c[p[i]]=c[p[i-1]];
			if(b[i]!=b[i-1])++c[p[i]];
		}
		int len=unique(b,b+n)-b;
		int M=1;
		while(M<=len)M<<=1;
		int ret=0;
		for(int i=0;i<n;i++){
			int x=c[i]+M+1;
			int lx=lower_bound(b,b+len,a[i]-d)-b+M;
			int rx=upper_bound(b,b+len,a[i]+d)-b+M+1;
			ret=0;
			for(;lx^rx^1;lx>>=1,rx>>=1){
				if(~lx&1)ret=max(ret,maxx[lx^1]);
				if(rx&1)ret=max(ret,maxx[rx^1]);
			}
			ret++;
			for(maxx[x]=ret,x>>=1;x;x>>=1)
				maxx[x]=max(maxx[x<<1],maxx[x<<1|1]);
		}
		printf("%d\n",maxx[1]);
	}
	return 0;
}
		
			
