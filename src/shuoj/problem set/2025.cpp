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
int dp[1010][2];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int n = str.length();
        rep(i,n){
            if(str[i] == '-'){
                dp[i+1][0] = min(dp[i][0], dp[i][1] + 1);
                dp[i+1][1] = min(dp[i][0] + 1, dp[i][1] + 2);
            }else{
                dp[i+1][0] = min(dp[i][0] + 2, dp[i][1] + 1);
                dp[i+1][1] = min(dp[i][0] + 1,dp[i][1]);
            }
        }
        cout << min(dp[n][1],dp[n][0] + 1) << endl;
    }
    return 0;
}

