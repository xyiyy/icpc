#include <iostream>
using namespace std;
#define REP(A,X) for(int A=0;A<X;A++)
int a[1010];
int dp[1010][2];
int main(){
    ios::sync_with_stdio(false);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    char c;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>c;
        if(c=='.')a[j]++;
    }
    for(int i=1;i<=m;i++)a[i]+=a[i-1];
    for(int i=0;i<=m;i++)dp[i][0]=dp[i][1]=0x3fffffff;
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=m;i++){
        //dp[i][0]=dp[i-1][0]+n-a[i]+a[i-1];
        for(int j=0;j<i;j++){
            if(j+x<=i&&j+y>=i){
                dp[i][1]=min(dp[i][1],dp[j][0]+a[i]-a[j]);
                dp[i][0]=min(dp[i][0],dp[j][1]-a[i]+a[j]+n*(i-j));
            }

        }
        //cout<<i<<"  "<<dp[i][0]<<"  "<<dp[i][1]<<endl;
    }
    cout<<min(dp[m][0],dp[m][1])<<endl;
    return 0;
}

