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
int dp[100010][10][2];
int dp2[100010][10][2];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    dp[1][1][0] = dp[1][1][1] = 1;
    rep2(i,2,100000){
        rep(k,2){
            rep2(j,1,6){
                dp[i][j][k] = 0;
                if(j!=1)dp[i][j][k] += dp[i-1][j-1][k];
                else{
                    rep2(l,1,6){
                        dp[i][j][k] += dp[i-1][l][k^1];
                    }
                }
                dp[i][j][k] %= 2015;

            }
        }
    }
    cin>>t;
    int cas = 1;
    while(t--){
        int n;
        cin>>n;
        cout << "Case #" << cas++ << ": ";
        int ans = 0;
        dep(s,min(n,6),1){
            rep(i,10){
                rep(j,2)dp2[s][i][j] = 0;
            }
            dp2[s][s][0] = dp2[s][s][0] = 1;
            rep2(i,s+1,n){
                rep(k,2){
                    rep2(j,1,6){
                        dp2[i][j][k] = 0;
                        if(j!=1)dp2[i][j][k] += dp2[i-1][j-1][k];
                        else{
                            rep2(l,1,6){
                                dp2[i][j][k] += dp2[i-1][l][k^1];
                            }
                        }
                        dp2[i][j][k] %= 2015;
                    }
                }
            }
            rep2(i,1,6)ans+=dp2[n][i][0] + dp2[n][i][1];
            //rep(k,2){
                rep2(j,1,6-s){
                    ans+=dp2[n][j][1]+dp2[n][j][0];
                }
            //}
            ans%=2015;
            cout << ans << endl;
        }
        cout << ans<<endl;

    }
    return 0;
}

