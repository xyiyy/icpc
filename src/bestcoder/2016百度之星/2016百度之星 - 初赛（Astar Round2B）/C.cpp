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
typedef vector<PII> vii;
typedef vector<int> vi;
ll dp[200020];
const ll MOD = 1000000007;
void extgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

ll inv(ll a) {
    ll d, x, y;
    extgcd(a, MOD, d, x, y);
    return d == 1 ? (x + MOD) % MOD : -1;
}
ll C(int n,int m){
    ll ret = dp[n];
    ret = ret * inv(dp[m]) % MOD * inv(dp[n - m]) % MOD;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    //cin >> n >> m;
    dp[0] = 1;
    rep2(i,1,200010){
        dp[i] = dp[i - 1] * i  % MOD;
    }
    //cout << dp[3]<< " " << dp[5] << endl;
    while(cin >> n >> m){
        n-= 2;
        m-= 2;
        cout << C(n+m,m)%MOD << endl;;
    }
    return 0;
}
