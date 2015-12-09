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
ll cal(ll n,int m){
	ll ret=1;
	while(m){
		if(m&1)ret=ret*n;
		n=n*n;
		m>>=1;
	}
	return ret;
}
ll a[110];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int cnt=0;
	for(int i=0;i<5;i++){
		//ll t=cal(2,i);
		ll t=1LL<<i;
		t=1LL<<t;
		t++;
		a[i]=t;
		if(t<=1000000000)cnt++;
		//cout<<t<<endl;
	}
	while(scanf("%d",&n)!=EOF){
		ll tmp=n;
		while((tmp&1)==0)tmp>>=1;
		if(tmp==1){
			printf("YES\n");
		}else{
			for(int i=0;i<cnt;i++){
				if(n%a[i]==0)n/=a[i];
			}
			while((n&1)==0)n>>=1;
			if(n==1)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}



