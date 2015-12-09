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
int dp1[1010][1010];
int dp2[1010][1010];
PII dpff[1010][1010];
PII dptt[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL

    int n;
    while(scanf("%d",&n)!=EOF){
            int a;
        rep2(i,1,n){
            rep2(j,1,n){
                scanf("%d",&a);
                if(a==0){
                    dp2[i][j] = dp1[i][j] = INF;
                }else{
                    int num = 0;
                    while(a%5==0&&a!=0){
                        num++;
                        a/=5;
                    }
                    dp1[i][j] = num;
                    num = 0;
                    while(a%2==0&&a!=0){
                        num++;
                        a/=2;
                    }
                    dp2[i][j] = num;
                }
            }
        }
        rep2(i,0,n){
            rep2(j,0,n){
                dpff[i][j] = dptt[i][j] = mp(INF,INF);
            }
        }
        dpff[0][1] = dptt[1][0] = mp(0,0);
        rep2(i,1,n){
            rep2(j,1,n){
                if(dp1[i][j]!=INF){
                    dpff[i][j] = min(dpff[i-1][j],dpff[i][j-1]);
                    dpff[i][j].first += dp1[i][j];
                    dpff[i][j].second += dp2[i][j];
                    dptt[i][j] = min(dptt[i-1][j],dptt[i][j-1]);
                    dptt[i][j].first += dp2[i][j];
                    dptt[i][j].second += dp1[i][j];
                    //cout << i <<" " << j<<" ";
                    //cout << dpff[i][j].first  << " " <<dpff[i][j].second << endl;

                    //if((dptt[i-1][j]<dptt[i][j-1])||(dptt[i-1][j]==dptt[i][j-1])&&(dptf[i-1][j]<dptf[i][j-1])){
                    //    dptf[i][j] = dptf[i-1][j] + dp1[i][j];
                    //    dptt[i][j] = dptt[i-1][j] + dp2[i][j];
                    //}else{
                    //    dptf[i][j] = dptf[i][j-1] + dp1[i][j];
                    //    dptt[i][j] = dptt[i][j-1] + dp2[i][j];
                   // }
                    //if((dpff[i-1][j]<dpff[i][j-1])||(dpff[i-1][j]==dpff[i][j-1])&&(dpft[i-1][j]<dpft[i][j-1])){
                    //    dpft[i][j] = dpft[i-1][j] + dp2[i][j];
                    //    dpff[i][j] = dpff[i-1][j] + dp1[i][j];
                    //}else{
                    //    dpft[i][j] = dpft[i][j-1] + dp2[i][j];
                    //    dpff[i][j] = dpff[i][j-1] + dp1[i][j];
                    //}
                }
                //else dpff[i][j] = dptt[i][j] = mp(INF,INF);
            }
        }
        int ans = min(dpff[n][n].second,dpff[n][n].first);
        ans = min(ans,dptt[n][n].first);
        ans = min(ans,dptt[n][n].second);
        cout << ans << endl;

    }
    return 0;
}
