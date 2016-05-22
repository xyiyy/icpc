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
ll a[100010];
ll b[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    ll n,k;
    while(cin >> n >> k){
        rep(i,n)cin >> a[i];
        rep(i,n)cin >> b[i];
        ll l = 0, r = 2000000000;
        ll ans = 0;
        while(l <= r){
            ll mid = (l + r) >> 1;
            bool flag = 1;
            ll gao = k;
            rep(i,n){
                ll tmp = a[i] * mid;
                if(tmp > b[i]){
                    gao -= tmp - b[i];
                    if(gao < 0){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;

        }
        cout << ans << endl;
    }
    return 0;
}
