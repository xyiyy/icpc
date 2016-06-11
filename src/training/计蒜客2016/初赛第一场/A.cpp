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
int dp[510][510];
bool ok[510][510];
int a[510];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int u , v;
    rep(i,n)cin >> a[i];
    rep(i,n){
        rep(j,n)dp[i][j]=INF;
    }
    for(int i = 0 ; i < n - 1; i ++){
        cin >> u >> v;
        u--;v--;
        dp[u][v] = 1;
        dp[v][u] = 1;
    }
    rep(i,n)
    rep(j,n){
        if(i == j)continue;
        if(__gcd(a[i],a[j])==1)ok[i][j] = 1;
    }
    for(int k = 0 ;k  < n ; k ++){
        for(int i = 0 ; i < n; i ++){
            for(int j = 0 ; j < n ; j++){

                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i,n){
        rep(j,n){
           // cout << dp[i][j] << " ";
            if(i == j)continue;
            if(ok[i][j])ans += dp[i][j];
        }
        //cout << endl;
    }
    cout << ans / 2 << endl;

    return 0;
}

