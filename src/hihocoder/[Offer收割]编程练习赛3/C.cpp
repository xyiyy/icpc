
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
int dp[1010];
int a[1010];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n,m,s,t;
        cin >> n >> m >> s >> t;
        rep(i,n)cin >> a[i];
        rep2(j,0,m){
            dp[j] = 1010;
        }
        dp[0] = 0;
        int p;
        rep(i,n){
            dep(j,m,0){
                dp[j] = 1010;
                int gao = a[i] + s - 1;
                p = gao / s;
                if(j >= p)dp[j] = min(dp[j - p] + p,dp[j]);
                for(int k=0,num = 0;k<a[i];k+=s,num++){
                    p = (a[i] - k + t-1) / t + num;
                    if(j >= p){
                        dp[j] = min(dp[j - p] + num,dp[j]);
                    }
                    //dp[j] = dp[j - num]
                }
            }
        }
        /*rep2(j,0,m){
            rep2(k,0,50)dp[j][k] = 1010;
        }
        dp[0][0] = 0;
        rep(i,n){
            rep2(j,1,m){
                rep(k,a[i]){
                    int temp = min(a[i],k+s);
                    dp[j][temp] = min(dp[j-1][k]+1,dp[j][temp]);
                    temp = min(a[i],k+t);
                    dp[j][temp] = min(dp[j-1][k],dp[j][temp]);
                }
            }
            rep2(j,0,m){
                rep2(k,0,a[i]){
                    cout <<dp[j][k] << " ";
                }
                cout << endl;
            }
            //cout << endl;
            rep2(j,0,m)dp[j][0] = dp[j][a[i]];
            rep2(j,0,m){
                rep2(k,1,a[i])dp[j][k] = 1010;
            }
        }*/
        int ans = 1010;
        rep(i,m+1)ans = min(ans,dp[i]);
        if(ans == 1010)cout << "No" << endl;
        else cout << ans << endl;


    }
    return 0;
}
