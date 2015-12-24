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
typedef vector<PII> VII;
typedef vector<int> VI;
int dp[1010][1010];
int a[1010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        clr(a,0);
        rep2(i,1,n){
            cin>>a[i];
        }
        rep2(i,1,n)dp[i][i] = 1;
        rep2(i,1,n){
            dep(j,i-1,1){
                dp[j][i] = INF;
                for(int k = j;k<=i;k++){
                    dp[j][i] = min(dp[j][i],dp[j][k]+dp[k+1][i]);
                }

                //for(int k=j;k<=i;k++){
                //    if(a[k]==a[j])
                //}
                //dp[j][i] = dp[j+1][i-1]+2;
                dp[j][i] = min(dp[j][i],dp[j+1][i-1]+2);
                //if(a[j]==a[j+1])dp[j][i] = min(dp[j][i],dp[j][j+1]+dp[j+2][i]);
                dp[j][i] = min(dp[j][i-1]+1,dp[j][i]);
                dp[j][i] = min(dp[j][i],dp[j+1][i]+1);
                int f = 2;
                if(a[i] == a[j])f--;
                if(j+1<=i-1&&f==1)f=0;
                dp[j][i] = min(dp[j][i],dp[j+1][i-1]+f);
                //cout << j << " " << i << " " << dp[j][i] << endl;;
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}

