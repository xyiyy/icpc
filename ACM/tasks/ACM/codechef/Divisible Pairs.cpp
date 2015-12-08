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

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll a = n / m;
        ll b = n % m;
        ll ans = 0;
        if(m&1){
            ans = a * (m - 1) * a / 2 + b * a ;
            ans += b > m / 2 ? b - m / 2 : 0;
            if(a)ans += a * (a - 1) / 2;
        }
        else{
            ans = a * (m - 2) * a / 2 + b * a;
            ans += b > m / 2 ? b - m / 2 : 0;
            if(a) ans += a * (a - 1);
        }
        cout << ans << endl;
    }
    return 0;
}

