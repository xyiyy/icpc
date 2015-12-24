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
int a[100010];
int dp[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        rep(i,n)cin>>a[i];
        rep(i,n)a[i]--;
        rep(i,n)dp[a[i]] = i;
        int maxx = 0;
        int num = 0;
        rep2(i,1,n-1){
            if(dp[i] > dp[i-1]){
                num++;
            }else num = 0;
            maxx = max(num,maxx);
        }
        cout << n - maxx - 1 << endl;
        /*int f = 0;
        int last = 0;
        rep(i,n){
            if(a[i]==last+1)last++;
        }
        int ans = n - last;
        last = 0;
        dep(i,n-1,0){
            if(a[i] == n - last) last++;
        }
        ans = min(ans,n - last);
        rep(i,n+5)dp[i] = INF;
        rep(i,n)*lower_bound(dp,dp+n,a[i]) = a[i];
        ans = min(n - (lower_bound(dp,dp+n,INF) - dp) ,ans);*/


    }
    return 0;
}

