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
ll bit1[MAXN],bit2[MAXN];
int tot;
ll sum(ll *bit,int i){
	ll s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(ll *bit,int i,ll x){
	while(i<=tot){
		bit[i]+=x;
		i+=i&-i;
	}
}
	
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int tmp;
		tot=n;
		memset(bit1,0,sizeof(bit1));
		memset(bit2,0,sizeof(bit2));
		REP(i,n){
			scanf("%d",&tmp);
			add(bit1,i+1,tmp);
		}
		int x,y,z,type;
		ll temp;
		while(m--){
			scanf("%d",&type);
			if(type==1){
				scanf("%d%d%d",&x,&y,&z);
				temp=((ll)-z)*(x-1);
				add(bit1,x,temp);
				add(bit2,x,z);
				temp=z*y;
				add(bit1,y+1,temp);
				add(bit2,y+1,-z);
			}else{
				scanf("%d%d",&x,&y);
				ll ans=0;
				ans+=sum(bit1,y)+sum(bit2,y)*y;
				ans-=sum(bit1,x-1)+sum(bit2,x-1)*(x-1);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}



