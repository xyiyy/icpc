//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X, Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X, N) for(int X=0;X<N;X++)
#define rep2(X, L, R) for(int X=L;X<=R;X++)
#define dep(X, R, L) for(int X=R;X>=L;X--)
#define clr(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;

bool check(int x) {
    if (x < 2)return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)return 0;
    }
    return 1;
}

void getdata() {
    int t = 100;
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        int n = 0;
        rep(i, 4)n = ((n << 7) | (rand() % 128));
        n = (n << (rand() % 3));
        n %= 1000000001;
        int m = 0;
        rep(i, 4)m = ((m << 6) | (rand() % 64));
        m %= 10001;
        int k = 0;
        while (!k && k <= n) {
            k = 0;
            rep(i, 4)k = ((k << 7) | (rand() % 128));
            k = (k << (rand() % 3));
            k %= 1000000008;
        }
        cout << n << " " << m << " " << k << endl;
    }
}

vector<int> vec;
int dp[110];

void extgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

ll inv(ll a, ll mod) {
    ll x, y, d;
    extgcd(a, mod, d, x, y);
    return d == 1 ? (x + mod) % mod : -1;
}

ll quick_power(ll n, ll m, ll mod) {
    ll ret = 1;
    while (m) {
        if (m & 1) ret = ret * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        //freopen("1941.in","w",stdout);
        //getdata();
        freopen("1941.in","r",stdin);
        freopen("1941.out","w",stdout);
    #endif // LOCAL
    int t;
    cin >> t;
    int n, m, k;
    while (t--) {
        cin >> n >> m >> k;
        clr(dp, 0);
        int tmp = k;
        vec.clear();
        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i == 0) {
                int num = 0;
                while (tmp % i == 0) {
                    tmp /= i;
                    num++;
                }
                vec.pb(i);
            }
        }
        if (tmp != 1)vec.pb(tmp);
        int p = n - m + 1;
        ll ans = 1;
        rep2(i, p, n) {
            tmp = i;
            rep(j, vec.size()) {
                int y = vec[j];
                while (tmp % y == 0) {
                    dp[j]++;
                    tmp /= y;
                }
            }
            ans = ans * (ll) tmp % k;
        }
        ll cnt = 1;
        rep2(i, 2, m) {
            tmp = i;
            rep(j, vec.size()) {
                int y = vec[j];
                while (tmp % y == 0) {
                    dp[j]--;
                    tmp /= y;
                }
            }
            cnt = cnt * (ll) tmp % k;
        }
        rep(j, vec.size()) {
            ans = ans * quick_power(vec[j], dp[j], k) % k;
        }
        ans = ans * inv(cnt, k) % k;
        cout << ans << endl;


    }
    return 0;
}

