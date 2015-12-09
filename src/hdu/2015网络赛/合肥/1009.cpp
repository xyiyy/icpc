
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
int dp[31][31][2000];
int a[31][31];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas = 1;
    while(t--){
        int n,m;
        cin>>n>>m;
        rep(i,n)
        rep(j,m)cin>>a[i][j];
        rep(i,n)
        rep(j,m)
        rep(k,2000)dp[i][j][k] = INF;
        dp[0][0][a[0][0]] = a[0][0] * a[0][0];
        rep(i,n){
            rep(j,m){
                rep(k,1801){
                    if(k<a[i][j])continue;
                    if(i){
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k-a[i][j]]+a[i][j]*a[i][j]);
                    }
                    if(j){
                        dp[i][j][k] = min(dp[i][j][k],dp[i][j-1][k-a[i][j]]+a[i][j]*a[i][j]);
                    }
                }
            }
        }int ans = INF;
        rep(i,1801){
            ans = min((n+m-1)*dp[n-1][m-1][i]-i*i,ans);
        }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;

    }
	return 0;
}


