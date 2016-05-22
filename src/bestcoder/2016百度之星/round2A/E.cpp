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
ll dp[110];
ll len[110];
ll query(ll x){
    int f = 1;
    ll ans = 0;
    int last = 110;
    while(x){
        int now = lower_bound(len,len+61,x) - len;
       // cout << now  << " "<< ans << endl;
        if(now == last - 1){
            f = 0;
        }else f = 1;
        if(x == len[now]){
            x = 0;
            ans += dp[now];
            break;
        }
        ll p = len[now] + 1;
        p /= 2;
        x -= p;
        ans += dp[now - 1] + f;
        last = now;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin >> t;
    dp[1] = 1LL;
    len[1] = 1LL;
    rep2(i,2,65){
        dp[i] = dp[i-1] * 2;
        len[i] = len[i-1] * 2 + 1;
    }
    while(t--){
        ll x,y;
        cin >> x >> y;
        cout <<query(y) - query(x - 1) << endl;
    }
    return 0;
}


