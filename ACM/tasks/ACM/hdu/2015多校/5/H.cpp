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
int a[100010];
ll b[100010];
int n;
ll dfs(int i,int j){
	if(i==1&&j==1)return 0;
	if(i<1||j<1||j+i>n+1)return INF;
	if(j==1)return dfs(i-1,j+1);
	return min(dfs(i-1,j+1),dfs(i,(j+1)/2)+b[i]);
}
ll dp[100010][20];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		REP2(i,1,n)cin>>a[i];
		b[n] = a[n];
		for(int i=n-1;i>0;i--)b[i] = b[i+1] + a[i];
		ll ans = dfs(n,1);
		//cout<<ans<<endl;
		for(int i=2;i<20;i++)dp[1][i] = dp[1][i-1]+b[1];
		for(int i=2;i<=n;i++){
			for(int j = 1;j<20;j++){
				dp[i][j] = min(dp[i-1][j+1],dp[i][j-1]+b[j]);
			}
		}
		cout<<dp[n][1]<<"                   "<<ans<<endl;
	}
		
	return 0;
}



