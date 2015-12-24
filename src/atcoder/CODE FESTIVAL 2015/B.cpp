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
int dp[51][500010];
int a[110],b[110];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,x,y;
    cin>>n>>x>>y;
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    rep2(i,0,n){
        rep2(j,0,200010)dp[i][j] = -INF;
    }
    dp[0][0] = 0;
    rep(i,n){
            for(int j =i+1;j>=0;j--){
                for(int k = 0;k<=x+y;k++){
                        if(dp[j][k]==-INF)continue;
                        dp[j+1][min(x+y,k+a[i]+b[i])] = max(dp[j+1][min(x+y,k+a[i]+b[i])],dp[j][k]+b[i]);
                }
            }
    }
    int ans = -1;
    for(int i = 1;i<=n;i++){
        if(dp[i][x+y]>=y){
            ans = i;
            break;
        }
    }
    cout << ans <<endl;

    return 0;
}

