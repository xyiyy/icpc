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
PII p[100010];
int dp[100010];
int vis[100010];
int a[100010];
stack<PII>s;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        rep2(i,1,n)cin>>p[i].first>>p[i].second;
        sort(p+1,p+n+1);
        rep2(i,1,n)a[i] = -p[i].first;
        a[0] = INF;
        reverse(a,a+n+1);
        clr(vis,0);
        int ans = n - 1;
        //while(!s.empty())s.pop();
      //  a[0] = INF;
     // rep(i,n+1)cout << a[i] << " ";
      //cout << endl;
        dp[0] = 0;
        rep2(i,1,n){
            //if(!vis[i]){
                int id = n - (upper_bound(a,a+n + 1,-p[i].first+p[i].second) - a);
                dp[i] = dp[id] + 1;
                //cout << p[i].first << " " << p[i].second<<endl;
        //        cout << i << " " << id << " " << dp[i] << endl;
                ans = min(ans,n-i+(i-dp[i]));
            //}
        }
        cout << ans <<endl;
    }
    return 0;
}

