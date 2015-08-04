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
const ll MOD =1000000007 ;
int a[10010];
ll b[2010];
bool vis[2010];
ll dp[2010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	b[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<2010;i++)b[i]=(b[i-1]*i)%MOD;
	int tx=0,ty=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1)vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			if(vis[i])tx++;
			else ty++;
		}
	}
	dp[0]=1;
	dp[1]=tx*dp[0]%MOD;
	for(int i=2;i<=ty;i++){
		dp[i]=(tx*dp[i-1]%MOD+(i-1)*dp[i-1]%MOD+(i-1)*dp[i-2]%MOD)%MOD;
	}
	cout<<dp[ty]*b[tx]%MOD<<endl;
	
	
	
		
			
	return 0;
}



