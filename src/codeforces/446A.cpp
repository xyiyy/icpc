#include <iostream>
using namespace std;
#define MAXN 100010
int a[MAXN];
int dp1[MAXN];
int dp2[MAXN],dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp1[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1])dp1[i]=dp1[i-1]+1;
        else dp1[i]=1;
    }
    dp2[n]=1;
    for(int i=n-1;i;i--){
        if(a[i]<a[i+1])dp2[i]=dp2[i+1]+1;
        else dp2[i]=1;
    }
    int ans=1;
    if(n==1){
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i==1)ans=max(ans,dp2[i+1]+1);
        else if(i==n)ans=max(ans,dp1[i-1]+1);
        else if(a[i+1]-a[i-1]>1)ans=max(ans,dp1[i-1]+dp2[i+1]+1);
        else ans=max(ans,max(dp1[i-1],dp2[i+1])+1);
    }
    cout<<ans<<endl;
    return 0;
}
