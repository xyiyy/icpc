
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
typedef pair<int,PII>PIII;
#define mmp(X,Y,Z) mp(X,mp(Y,Z))
PIII a[110];
int dp[110][110];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n,m,s;
        cin >> n >> m >> s;
        int w,t,c;
        rep(i,m){
            cin >> w >> t >> c;
            a[i] = mmp(t,w,c);
        }
        sort(a,a+m);
        rep(i,110)rep(j,110)dp[i][j] = INF;
        dp[0][0] = 0;
        rep(i,m){
            t = a[i].first;
            w = a[i].second.first;
            c = a[i].second.second;
            //cout << t << " " << w << " " << c <<endl;
            dep(j,min(t,n),1){
                dep(k,s,w){
                    dp[j][k] = min(dp[j-1][k - w] + c,dp[j][k]);
                   // cout << i << " " << j << " " << k << " " << dp[j][k] << endl;
                }
            }
        }
        int ans = INF;
        rep(i,s+1)ans = min(dp[n][i],ans);
        if(ans == INF)ans = -1;
        cout << ans << endl;

    }
    return 0;
}
