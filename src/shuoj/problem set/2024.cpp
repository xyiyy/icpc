//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
int dp[1010][1010];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep2(i,1,n){
        int now = 0;
        rep2(j,1,m){
            cin >> dp[i][j];
            now += dp[i][j];
            dp[i][j] = dp[i-1][j] + now;
        }
    }
    int a,b;
    cin >> a >> b;
    int ans = 0;
    rep2(i,1,n){
        rep2(j,1,m){
            int x = max(0,i-a);
            int y = max(0,j-b);
            ans = max(ans,dp[i][j] - dp[x][j] - dp[i][y] + dp[x][y]);
        }
    }
    cout << ans << endl;
    return 0;
}


