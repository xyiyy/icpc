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
ll dp[2020];
ll f[2020];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        rep2(i,1,n - 1)cin>>f[i];
        clr(dp,0);
        dp[0] = n * f[1];
        rep2(i,2,n-1){
            rep2(j,i-1,n-2){
                dp[j] = max(dp[j], dp[j - i + 1] + f[i] - f[1]);
            }
        }
        cout << dp[n - 2] << endl;
    }
    return 0;
}




