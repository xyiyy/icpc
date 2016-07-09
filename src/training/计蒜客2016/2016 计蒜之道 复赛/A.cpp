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
int a[310][310];
int dp[310][310];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n){
        rep(j,n)cin >> a[i][j];
    }
    rep(i,n){
        rep(j,n){
            if(a[i][j] == -1)a[i][j] = INF;
            dp[i][j] = a[i][j];
        }
    }
    ll ans = 0;
    for(int k = 0 ; k <= n ; k ++){
        for(int p = k + 1;p< n ; p++){
            rep(i,n){
                if(i == k)continue;
                rep(j,n){
                    if(j == k)continue;
                    dp[i][j] = min(dp[i][j],dp[i][p]+dp[p][j]);
                }
            }
        }
        rep(i,n){
            if(i == k)continue;
            rep(j,n){
                if(j == k)continue;
                if(dp[i][j]==INF)dp[i][j] = -1;
                ans += dp[i][j];
            }
        }
        for(int i = 0; i < n; i ++ ){
            for(int j = 0 ; j <n; j ++){
                a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
                dp[i][j] = a[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
