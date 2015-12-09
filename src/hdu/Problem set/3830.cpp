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
#define MAXN 10
ll a[MAXN],b[MAXN];
ll ra[MAXN],rb[MAXN];
void gcd(ll *x,ll &d){
	ll l1=x[1]-x[0];
	ll l2=x[2]-x[1];
	ll t;
	while(l1!=l2){
		if(l1<l2){
			t=(l2-1)/l1;
			ll tmp=t*l1;
			x[0]+=tmp;
			x[1]+=tmp;
		}else{
			t=(l1-1)/l2;
			ll tmp=t*l2; 
			x[1]-=tmp;
			x[2]-=tmp;
		}
		d+=t;
		l1=x[1]-x[0];
		l2=x[2]-x[1];
		//gcd(x,d);
	}
}
void gao(ll *x,ll d){
	ll l1=x[1]-x[0];
	ll l2=x[2]-x[1];
	ll t;
	while(d>0){
		if(l1<l2){
			t=(l2-1)/l1;
			if(t>d)t=d;
			ll tmp=t*l1;
			x[0]+=tmp;
			x[1]+=tmp;
		}else {
			t=(l1-1)/l2;
			if(t>d)t=d;
			ll tmp=t*l2;
			x[1]-=tmp;
			x[2]-=tmp;
		}
		d-=t;
		l1=x[1]-x[0];
		l2=x[2]-x[1];
	}
}
	
int main()
{
	ios::sync_with_stdio(false);
	while(scanf("%I64d%I64d%I64d",&a[0],&a[1],&a[2])!=EOF){
		for(int i=0;i<3;i++)scanf("%I64d",&b[i]);
		sort(a,a+3);
		sort(b,b+3);
		for(int i=0;i<3;i++)ra[i]=a[i];
		for(int i=0;i<3;i++)rb[i]=b[i];
		ll d1=0,d2=0;
		bool flag=0;
		for(int i=0;i<2;i++)if(ra[i]==ra[i+1])flag=1;
		for(int i=0;i<2;i++)if(rb[i]==rb[i+1])flag=1;
		if(flag){
			printf("NO\n");
			continue;
		}
		gcd(ra,d1);
		gcd(rb,d2);
		flag=0;
		for(int i=0;i<3;i++)
			if(ra[i]!=rb[i])flag=1;
		if(flag){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		ll ans = 0;
		ll tmp = 0;
		if(d1>d2)gao(a,d1-d2);
		else gao(b,d2-d1);
		ll l=0,r=min(d1,d2);
		while(l<=r){
			ll mid=(l+r)>>1;
			for(int i=0;i<3;i++)ra[i]=a[i];
			for(int i=0;i<3;i++)rb[i]=b[i];
			gao(ra,mid);
			gao(rb,mid);
			bool flag=0;
			for(int i=0;i<3;i++)
				if(ra[i]!=rb[i])flag=1;
			if(!flag){
				tmp=mid;
				r=mid-1;
			}else {
				l=mid+1;
			}
		}
		printf("%I64d\n",tmp*2+max(d1-d2,d2-d1));
	}	
	return 0;
}

