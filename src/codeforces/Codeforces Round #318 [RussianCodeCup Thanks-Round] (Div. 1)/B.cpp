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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int h[100010];
int dp[100010];
int dp2[100010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(i,n)cin>>h[i];
	int maxx = 0;
	dp[0] = dp2[n-1] = 1;
	rep2(i,1,n-1)dp[i] = min(h[i],dp[i-1]+1);
	dep(i,n-2,0)dp2[i] = min(h[i],dp2[i+1]+1);
	rep(i,n)dp[i] = min(dp[i],dp2[i]);
	rep(i,n)maxx = max(dp[i],maxx);
	cout<<maxx<<endl;
	return 0;
}



