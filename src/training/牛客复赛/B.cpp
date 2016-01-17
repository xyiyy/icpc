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
char a[2][1010];
int dp[2][1010];
char b[2][1010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("B.txt","w",stdout);

    #endif // LOCAL
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int n;
        rep(i,2){
            rep(j,n){
                cin>>a[i][j];
                b[i][j] = a[i][j];
            }
        }
        clr(dp,0);
        rep(i,2){
            rep(j,n){
                if(b[i][j]=='.'){
                    int len = 0;
                    for(int k =j;k<n;k++){
                        if(b[i][k]=='.'){
                            b[i][k]='X';
                            len++;
                        }else break;
                    }
                    dp[i][j]=len;
                }
            }
        }
        int ans = 0;
        rep(j,n){
            if(dp[0][j]!=dp[1][j]){
                int x = dp[0][j];
                int y = dp[1][j];
                if(x == 1 || y == 1){
                    ans++;
                }else{
                    int now = 0;
                    ans++;
                    if(x < y)now = 1;
                    if(x != 0)ans++;
                    int len = dp[now][j];
                    int minn = 1010;
                    int ind = 1010;
                    for(int k = j;k<j+len;k++){
                        if(dp[now^1][k]<=minn){
                            minn = dp[now^1][k];
                            ind = k;
                        }
                    }
                    dp[now^1][ind+1] = minn - 1;
                    dp[now^1][ind] = 0;
                }
            }else{
                int x = dp[0][j];
                int y = dp[1][j];
                if(x == 1){
                    ans++;
                }else if(x == 0)continue;
                else{
                    ans+=2;
                }

            }
        }
        cout << "Case #"<<cas ++ <<": "<<ans << endl;
    }
    return 0;
}

