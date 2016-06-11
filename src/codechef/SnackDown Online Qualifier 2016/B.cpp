#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010];
ll dp[100010][2];
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)cin >> a[i];
        ll INF = 1LL << 50;
         INF = - INF;
        ll ans = a[1];
         dp[1][0] = a[1];
         dp[1][1] = 0;
        for(int i = 2; i <= n ;i ++){
            dp[i][0] = dp[i][1] = INF;
            dp[i][0] = max(a[i],dp[i-1][0] + a[i]);
            dp[i][1] = max(dp[i-1][1] + a[i],dp[i-2][0]+a[i]);
            ans = max(ans,max(dp[i][0],dp[i][1]));
        }
        cout << ans << endl;
    }
    return 0;
}
