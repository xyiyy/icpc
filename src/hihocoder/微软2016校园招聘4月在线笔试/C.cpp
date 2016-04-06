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
char a[110][110];
int dp[110][110][2];
int n,m;
bool in(int x,int y){
    if(x >= n || y >= m || x < 0 || y < 0 )return 0;
    return 1;
}
bool in2(int x,int y){
    if(x >= n || y >= m || x < 0 || y < 0  || a[x][y] == 'b')return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //int n,m;
    cin >> n >> m;
    rep(i,n+1){
        rep(j,m+1)a[i][j] = 'b';
    }
    rep(i,n){
        rep(j,m){
            cin >> a[i][j];
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,m){
            //if(i==0 && j == 0)continue;
            //if(in(i,j)){
                //if(in(i,j+1)){
                    dp[i][j][1] = min(dp[i][j][0] + (a[i][j+1]!='b'),dp[i][j][1]);
                //}
                //if(in(i+1,j)){
                    dp[i][j][0] = min(dp[i][j][1] + (a[i+1][j]!='b'),dp[i][j][0]);
                //}
               // if(in(i,j+1)){
                    dp[i][j+1][0] = min(dp[i][j][0] + (a[i][j+1] == 'b'), dp[i][j+1][0]);
                //}
               // if(in(i+1,j)){
                    dp[i+1][j][1] = min(dp[i][j][1] + (a[i+1][j] == 'b'), dp[i+1][j][1]);
               // }


                //dp[i][j][0]
            //}
        }
    }
 /*   rep(i,n){
        rep(j,m){
            cout << dp[i][j][0] << " ";
        }
        cout << endl;
    }
    cout << endl;
    rep(i,n){
        rep(j,m){
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }*/
    int ans = min(dp[n-1][m-1][0],dp[n-1][m-1][1]);
    cout << ans << endl;
    return 0;
}

