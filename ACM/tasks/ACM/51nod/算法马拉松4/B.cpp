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
ll a[140000];
ll b[140010];
ll dp[150][150];
ll f(int n,int m){
	if(n==1||m==1){
		if(n==1)return a[m];
		else return b[n];
	}
	return (f(n-1,m)^f(n,m-1));
}
/*
ll dfs(int n,int m){
	if(n==1)return a[m];
	else if(m==1)return b[n];
	if(n>m) return  (dfs(n-m+1,m)^a[m]);
	else if(n==m)return (a[m]^b[n]);
	else return (dfs(n,m-n+1)^b[n]);
}*/
const int A = 131172;
const int B = 131072;
int main()
{
	ios::sync_with_stdio(false);
//	cout<<(5^5)<<endl;
//cout<<(2^3^6)<<endl;
	//a[1]=b[1] =1;
	for(int i=2;i<=A;i++)cin>>a[i];
	for(int i=2;i<=A;i++)cin>>b[i];
	for(int i=B;i<=A;i++){
		dp[i-B][0] = dp[0][i-B] = 0;
		for(int j=2;j<=i;j++){
			int n = i - j + B - 2;
			int m = B - 2;
			if((n&m)==m){
				dp[i-B][0] ^= b[j];
				if(i==B)continue;
				dp[0][i-B] ^= a[j];
			}	
		}
		for(int j=2;j<=B;j++){
			int n = i - j + B - 2;
			int m = B - j;
			if((n&m)==m){
				dp[i-B][0] ^= a[j];
				if(i==B)continue;
				dp[0][i-B] ^= b[j];
			}
		}		
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			dp[i][j] = (dp[i-1][j]^dp[i][j-1]);
		}
	}
	/*for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		//if(dp[n][m]!=f(n+B,m+B))cout<<"wa"<<endl;
		cout<<dp[n][m]<<endl;//" "<<f(n+2,m+2)<<endl;
	}
	return 0;
}



