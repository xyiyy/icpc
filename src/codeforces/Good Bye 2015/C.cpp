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

char a[510][510];
ll dp[510][510];
ll dpr[510][510];
ll dpc[510][510];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    while(cin>>n>>m){
        rep2(i,1,n)rep2(j,1,m)cin>>a[i][j];
        dp[1][1] = 0;
        rep2(i,1,n){
            rep2(j,1,m){
                dpr[i][j] = dpr[i][j-1];
                dpc[i][j] = dpc[i-1][j];
                if(a[i][j]=='#'){
                    dpr[i][j] = dpr[i-1][j] + dpr[i][j-1] - dpr[i-1][j-1];
                    dpc[i][j] = dpc[i-1][j] + dpc[i][j-1] - dpc[i-1][j-1];

                }else{
                    dpr[i][j] = dpr[i-1][j] + dpr[i][j-1] - dpr[i-1][j-1];
                    dpc[i][j] = dpc[i-1][j] + dpc[i][j-1] - dpc[i-1][j-1];
                    if(a[i-1][j]=='.'){
                        dpr[i][j]++;
                    }
                    if(a[i][j-1]=='.')dpc[i][j]++;
                }
                /*//if(i==0&&j==0)continue;
                dpc[i][j] = dpc[i-1][j];
                dpr[i][j] = dpr[i][j-1];
                if(a[i][j]=='#'){
                   // if(i==0){
                   //     dp[i][j] = dp[i][j-1];
                    //}else if(j==0){
                    //    dp[i][j] = dp[i-1][j];
                    //}else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                    //}
                }else{
                    dp[i][j] = 0;
                    //if(i){
                        dp[i][j]+=dp[i-1][j];

                        if(a[i-1][j]=='.'){
                            dp[i][j]++;
                            dpr[i][j]++;
                        }
                    //}
                    //if(j){
                        dp[i][j]+=dp[i][j-1];
                        if(a[i][j-1]=='.')dp[i][j]++,dpc[i][j]++;
                    //}
                    dp[i][j]-=dp[i-1][j-1];
                }*/
            }
        }
        int q;
        int r1,r2,c1,c2;
        cin>>q;
        while(q--){
            cin>>r1>>c1>>r2>>c2;
            cout << (dpr[r2][c2] - dpr[r2][c1-1] - dpr[r1][c2] + dpr[r1][c1-1]) + (dpc[r2][c2] -dpc[r1-1][c2]-dpc[r2][c1]+dpc[r1-1][c1]) << endl;
            //r1--;c1--;
            //r2--;c2--;
            //cout << dp[r2][c2] - dp[r2][c1] - dp[r1][c2] + dp[r1][c1] - (dpr[r1][c2] - dpr[r1][c1]) - (dpc[r2][c1] - dpc[r1][c1])<< endl;
        }
    }
    return 0;
}

