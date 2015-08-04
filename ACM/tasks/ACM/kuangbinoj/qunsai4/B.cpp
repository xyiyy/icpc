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

int a[100010];
int main()
{
	ios::sync_with_stdio(false);
	int x,y;
	bool flag=0;
	int tot=0;
	fill(a,a+100010,INF);
	int tmp;
	for(int i=10;i<=2222222;i++){
		x=i%10;
		tmp=i;
		tmp/=10;
		while(tmp){
			if(tmp%10!=x){
				break;
			}
			tmp/=10;
		}
		if(!tmp)a[tot++]=i;
	}
	while(scanf("%d%d",&x,&y)!=EOF){
		int s=x+x;
		int t=y+y;
		s=lower_bound(a,a+tot,s)-a;
		t=upper_bound(a,a+tot,t)-a;
		int tx,ty;
		ll ans=0;
		for(int i=s;i<t;i++){
			tx=a[i]/2;
			ty=(a[i]+1)/2;
			if(x<=tx)ans+=min(tx-x+1,y-ty+1);
		//	cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
			
	return 0;
}



