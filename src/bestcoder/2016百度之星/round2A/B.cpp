//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
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
int p[110],a[110];
int vis[20];
int dp[20][100000];
int vec[20];
int tot,n;
int maxx;
int ans;
void dfs(int u,int now,int v){
    if(now == tot){
        ans = max(maxx,ans);
    }
    int ret;
    if(u <= 1)ret = 0;
    else ret = maxx;
    if(vis[u]!=INF){
        int st = ((1<<(u)) | now);
        maxx = ret + v * vis[u];
        //if(maxx >= dp[u + 1][st]){
        //    dp[u+1][st] = max(maxx,dp[u+1][st]);
        //cout << u + 1 << " " << maxx << endl;
            dfs(u+1,st,vis[u]);
       // }
        return;
    }
    //if(now == tot)return;
    rep(i,n){
        if((1<<i)&now)continue;
        if(p[i+1]!=-1)continue;
        int st = ((1<<i)|now);
        maxx = ret + v * a[i + 1];
        //if(maxx >= dp[u+1][st]){
        //    dp[u+1][st] = max(maxx, dp[u+1][st]);
        //    cout << u + 1 << " " << st <<endl;
            dfs(u+1,st,a[i+1]);
        //}
    }

}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        ans = -INF;
        cin >> n;
        tot = (1 << n) - 1;
        rep(i,20)vis[i] = INF;
        rep2(i,1,n){
            cin >> a[i] >> p[i];
            if(p[i]!=-1)
            vis[p[i]] = a[i];
        }
        dfs(0,0,0);
        cout << ans << endl;
    }
    return 0;
}
