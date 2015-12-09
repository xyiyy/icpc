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
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define PRIME_MAXN 100010
int vis[PRIME_MAXN];
int prime[PRIME_MAXN], n_prime;
int phi[PRIME_MAXN];

void Eular() {
    n_prime = 0;
    phi[1] = 1;
    for (int i = 2; i < PRIME_MAXN; i++) {
        if (!vis[i]) {
            prime[n_prime++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < n_prime && i * prime[j] < PRIME_MAXN; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}

vector<int> vec[100010];
ll dp[100010];
ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    Eular();
    for (int i = 2; i < 100010; i++) {
        int tmp = i;
        for (int j = 2; j * j <= tmp; j++) {
            if (tmp % j == 0) {
                vec[i].PB(j);
            }
            while (tmp % j == 0)tmp /= j;
        }
        if (tmp != 1)vec[i].PB(tmp);
    }
    //cout<<vec[4][0]<<" "<<vec[4][1]<<endl;
    //for(int i=0;i<15;i++)cout<<i<<" "<<phi[i]<<endl;
    for (int i = 1; i <= 100000; i++) {
        dp[i] = phi[i];
        for (int j = 0; j < vec[i].size(); j++) {
            dp[i] += phi[i / vec[i][j]];
            if (dp[i] >= MOD)dp[i] -= MOD;
        }
    }
    for (int i = 0; i < 15; i++)cout << dp[i] << endl;
    int n;
    while (cin >> n) {
        int m;
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            cin >> m;
            ans = ans * dp[m] % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}


