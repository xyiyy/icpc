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
typedef vector<PII> vii;
typedef vector<int> vi;
ll dp[110];
const ll MOD = (1LL<<32);
int a[110];
int C = 0;
bool check(int n){
    C++;
    for(int i = 1; i < n ; i+=2){
        int l = (i+1) / 2;
        bool flag = 1;
        for(int j = 0;j < l ; j ++){
            if(a[j]!=a[j+l])flag = 0;
        }
        if(flag)return false;
    }
   // cout << "ok" << endl;
    return true;
}
int dfs(int n,int m,int now){
    int ret = 0;
    if(now >= n)return 0;
    for(int i = 0 ; i < m ; i ++){
        a[now] = i;
        if(check(now+1))ret++;
        ret += dfs(n,m,now+1);
    }
    return ret;
}
ll solve(ll n,ll m){
    dp[0] = 0;
    dp[1] = m;
    ll ans = m;
    for(int i = 2 ; i <= n ; i++){
        if(i&1)dp[i] = dp[i-1] * m % MOD;
        else dp[i] = (dp[i-1] * m % MOD - dp[i/2] + MOD) % MOD;
        ans += dp[i];
        ans %= MOD;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    //unsigned int n, m;
   // cout << MOD <<endl;
    //while(cin >> n >> m){
    //    cout << solve(n,m) << endl;
    //}
   // while(cin >> n >> m){
   for(int n = 1; n <=8 ;n++){
        for(int m = 1; m <= 10 ; m++){
            if(dfs(n,m,0) != solve(n,m))cout << n << " " << m << endl;
        }
   ///      //   cout << C << endl;
   }
    //}
    return 0;
}

