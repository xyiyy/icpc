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
ll n,ans;
vector<int>vec;
int vis[1010];
void dfs(int x,ll d){
	if(x==vec.size()){
		ans+=d;
		return;
	}
	ll tmp=1;
	dfs(x+1,d*tmp);
	for(int i=1;i<=vis[x];i++){
		tmp*=vec[x];
		dfs(x+1,d*tmp);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vec.clear();
		CLR(vis,0);
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		ans=0;
		ll tmp=n;
		for(int i=2;i*i<=tmp;i++){
			if(tmp%i==0){
				vec.PB(i);
				while(tmp%i==0){
					vis[vec.size()-1]++;
					tmp/=i;
				}
			}
		}
		if(tmp!=1){
			vec.PB(tmp);
			vis[vec.size()-1]++;
		}
		dfs(0,1);
		cout<<ans<<endl;
			
				
	}
	return 0;
}



