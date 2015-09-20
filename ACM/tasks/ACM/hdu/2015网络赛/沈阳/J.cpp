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
const int MOD = 530600414;
int dp[2200000];
int num[2200000];
int dp2[2200000];
int len[2200000];
int dp3[2200000];
const int MAXN = 201500;
int main()
{
	ios::sync_with_stdio(false);
	len[1] = 1,len[2] = 2;
	rep(i,MAXN){
        len[i+3] = len[i+2] + len[i+1];
        len[i+3] %= MOD;
	}
	num[3] = 1,num[4] = 1;
	rep(i,MAXN){
        num[i+5] = num[i+4] + num[i+3];
        num[i+5] %= MOD;
	}
	//for(int i=0;i<10;i++)cout<<num[i]<<endl;
	dp[5] = 5;
	dp2[4] = 2;
	dp2[5] = 9;
	dp3[4] = 3;
	dp3[5] = 7;
	rep2(i,6,MAXN){
        dp[i] = ((dp[i-1] + dp[i-2]) % MOD + ((ll)num[i-1]*dp2[i-2] % MOD) + ((ll)num[i-2]*dp3[i-1]%MOD))%MOD;
        dp2[i] = dp2[i-1] + dp2[i-2] + (ll)num[i-2]*len[i-1] % MOD;
        dp2[i]%=MOD;
        dp3[i] = dp3[i-1] + dp3[i-2] + (ll)num[i-1] * len[i-2]%MOD;
        dp3[i]%=MOD;
	}
	int n;
	int t;
	cin>>t;
	int cas = 1;
	while(t--){
        cin>>n;
        cout<<"Case #"<<cas++<<": ";
        cout<<dp[n]<<endl;
	}
	return 0;
}




