#include <iostream>

using namespace std;
#define REP(A, X) for(int A=0;A<X;A++)
typedef long long ll;
//int dp[1050][2][2][2][2];
ll dp[2][31][31][31][31];
const ll MOD = 1000000009;

int main() {
    ios::sync_with_stdio(false);
    int n, h;
    cin >> n >> h;
    /* REP(i,2)
     REP(j,2)
     REP(k,2)
     REP(l,2)
     if(i+j+k+l==1){
         dp[1][i][j][k][l]=1;
     }
     for(int i=2;i<=n;i++){
         REP(j,2)
         REP(k,2)
         REP(l,2)
         REP(m,2){
             if(j+k+l+m==1){

             }
         }
     }*/
    /* REP(i,4)dp[1][i][1][1][1]=1;
     for(int i=2;i<=n;i++){
         for(int j=0;j<4;j++){
             for(int k=0;k<30;k++){
                 if(i-k<=0)break;
                 for(int l=0;l<30;l++){
                     if(i-l<=0;break;)
                     for(int m=0;m<30;m++){
                         if(i-m<=0)break;
                         if(k!=1&&l!=1&&m!=1)continue;
                         if(k==1){
                             dp[i][j][k][l][m]+=dp[i-1][(j+1)%4][l-1][m-1][]
                         }

                     }
                 }
             }
         }
     }*/
    dp[0][0][0][0][0] = 1;
    int nj, nl, nm, nk;
    ll tmp;
    int x = 0, y = 1;
    for (int i = 1; i <= n; i++) {
        x = x ^ 1, y = y ^ 1;
        REP(j, 2)
            //REP(j,h+1)
            REP(k, h + 1)
                REP(l, h + 1)
                    REP(m, h + 1) {
                        tmp = dp[y][j][k][l][m];
                        dp[y][j][k][l][m] = 0;
                        tmp %= MOD;
                        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<tmp<<endl;
                        nj = j < 1 ? j + 1 : h;
                        nk = min(k + 1, h);
                        nl = min(l + 1, h);
                        nm = min(m + 1, h);
                        if (!j) dp[x][0][nk][nl][nm] += tmp;//,dp[x][0][nk][nl][nm]%=MOD;
                        else dp[x][1][nk][nl][nm] += tmp;//,dp[x][1][nk][nl][nm]%=MOD;
                        if (k != h)dp[x][0][nl][nm][nj] += tmp;//,dp[x][0][nl][nm][nj]%=MOD;
                        else dp[x][1][nl][nm][nj] += tmp;//,dp[x][1][nl][nm][nj]%=MOD;
                        if (l != h)dp[x][0][nm][nj][nk] += tmp;//,dp[x][0][nm][nj][nk]%=MOD;
                        else dp[x][1][nm][nj][nk] += tmp;//,dp[x][1][nm][nj][nk]%=MOD;
                        if (m != h)dp[x][0][nj][nk][nl] += tmp;//,dp[x][0][nj][nk][nl]%=MOD;
                        else dp[x][1][nj][nk][nl] += tmp;//,dp[x][1][nj][nk][nl]%=MOD;
                    }
    }
    /*{
        tmp=dp[y][j][k][l][m];
        //cout<<i<<" "<<j<<" "<<l<<" "<<m<<" "<<tmp<<endl;
        dp[y][j][k][l][m]=0;
        nj=min(j+1,h);//(j+1)%(h+1);
        nk=min(k+1,h);//(k+1)%(h+1);
        nl=min(l+1,h);//(l+1)%(h+1);
        nm=min(m+1,h);//(m+1)%(h+1);
        if(j!=h)dp[x][0][nk][nl][nm]+=tmp,dp[x][0][nk][nl][nm]%=MOD;
        else dp[x][h][nk][nl][nm]+=tmp,dp[x][h][nk][nl][nm]%=MOD;
        if(k!=h)dp[x][nj][0][nl][nm]+=tmp,dp[x][nj][0][nl][nm]%=MOD;
        else dp[x][nj][h][nl][nm]+=tmp,dp[x][nj][h][nl][nm]%=MOD;
        if(l!=h)dp[x][nj][nk][0][nm]+=tmp,dp[x][nj][nk][0][nm]%=MOD;
        else dp[x][nj][nk][h][nm]+=tmp,dp[x][nj][nk][h][nm]%=MOD;
        if(m!=h)dp[x][nj][nk][nl][0]+=tmp,dp[x][nj][nk][nl][0]%=MOD;
        else dp[x][nj][nk][nl][h]+=tmp,dp[x][nj][nk][nl][h]%=MOD;
    }
}
int ans=0;
REP(j,h+1)
REP(k,h+1)
REP(l,h+1)
REP(m,h+1)
if(j<h||k<h||l<h||m<h){
    ans+=dp[n&1][j][k][l][m];
    ans%=MOD;
}*/
    ll ans = 0;
    REP(j, 2)
        REP(k, h + 1)
            REP(l, h + 1)
                REP(m, h + 1)
                    if (j < 1 || k < h || l < h || m < h) {
                        //cout<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<dp[x][j][k][l][m]<<endl;
                        ans += dp[x][j][k][l][m];
                        ans %= MOD;
                    }
    cout << ans << endl;
    /*for(int j=0;j<4;j++){
        if(j==0){
            for(int k=1;k<=h;k++){
                for(int l=1;l<=h;l++){
                    for(int m=1;m<=h;m++){
                        if(k==l)continue;
                        if(k==m)continue;
                        if(l==m)continue;
                        if(k>1&&l>1&&m>1)
                            dp[x][0][k][l][m]+=dp[y][0][k-1][l-1][m-1];
                        if(k==1)
                            dp[x][0][k][l][m]+=dp[y][][0][][]
                    }
                }
            }
        }
    }*/

    return 0;
}
