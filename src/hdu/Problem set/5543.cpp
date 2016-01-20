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
ll dp[4010][3];
int a[1010],v[1010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,t,cas = 1;
    cin >> t;
    while(t--){
        int l;
        cin>>n >> l;
        rep(i,n)cin>>a[i] >> v[i];
        l <<= 1;
        ll ans = 0;
        clr(dp,0);
        rep(i,n){
            ans = max(1LL * v[i],ans);
            int num = a[i];
            a[i] <<= 1;
            dep(j,l,num){
                rep(k,3){
                    if(j >= a[i]){
                        dp[j][k] = max(dp[j][k],dp[j - a[i]][k] + v[i]);
                    }
                    if(k){
                        dp[j][k] = max(dp[j][k],dp[j - num][k - 1] + v[i]);
                    }
                    ans = max(ans,dp[j][k]);
                }
            }
        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }


    return 0;
}



