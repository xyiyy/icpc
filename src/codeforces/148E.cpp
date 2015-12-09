#include <iostream>
using namespace std;
int a[110][110];
int b[110][2];
int dp[110][110];
int dp2[10010];
int sum[110];
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        b[0][0]=b[0][1]=0;
        for(int j=1;j<=a[i][0];j++){
            b[j][0]=b[j-1][0]+a[i][j];
            b[j][1]=b[j-1][1]+a[i][a[i][0]-j+1];
        }
        for(int j=0;j<=a[i][0];j++)dp[i][j]=0;
        for(int j=0;j<=a[i][0];j++){
            for(int k=0;j+k<=a[i][0];k++){
                dp[i][j+k]=max(dp[i][j+k],b[j][0]+b[k][1]);
            }
        }
    }
    sum[0]=a[0][0];
    for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i][0];
    for(int i=0;i<=a[0][0];i++)dp2[i]=dp[0][i];
    for(int i=1;i<n;i++){
        for(int j=min(sum[i-1],m);j>=0;j--){
            for(int k=a[i][0];k>=0;k--){
                if(j+k<=m){
                    dp2[j+k]=max(dp2[j+k],dp[i][k]+dp2[j]);
                }
            }
        }
    }
    cout<<dp2[m]<<endl;
    return 0;

}

