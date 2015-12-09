//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
const int MAXN = 100010;
const ll MOD = 1000000007;
int a[MAXN];
int pos[MAXN];
ll b[MAXN];
ll c[MAXN];
vector<int>G[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<=10000;i++){
		for(int j=1;j*j<=i;j++){
			int y = i/j;
			if(j*y==i){
				G[i].PB(j);
				if(y!=j)G[i].PB(y);
			}
		}
	}		
	int n;
	while(cin>>n){
		ll ans = 0;
		for(int i=1;i<=10000;i++)pos[i] = -1;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++){
			int maxx = -1;
			int x = a[i];
			for(int j=0;j<G[x].size();j++){
				int y = G[x][j];
				maxx = max(maxx,pos[y]);
			}
			b[i] = i - maxx;
			pos[x] = i;
		}
		for(int i=0;i<=10000;i++)pos[i] = n;
		for(int i=n-1;i>=0;i--){
			int minn = n;
			int x = a[i];
			for(int j=0;j<G[x].size();j++){
				int y = G[x][j];
				minn = min(minn,pos[y]);
			}
			c[i] = minn - i;
			pos[x] = i;
		}
		for(int i=0;i<n;i++)
			ans = (ans + b[i] * c[i]) % MOD;
		cout<<ans<<endl;
	}
	return 0;
}



