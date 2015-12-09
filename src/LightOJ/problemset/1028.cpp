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

const int MAXN = 1000010;
ll prime[MAXN];
int n_prime;
bool vis[MAXN];

void eular() {
    n_prime = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i])prime[n_prime++] = i;
        for (int j = 0; j < n_prime && i * prime[j] < MAXN; j++) {
            vis[i * prime[j]] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin >> t;
    eular();
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 1;
        for (int i = 0; prime[i] * prime[i] <= n && i < n_prime; i++) {
            if (n % prime[i] == 0) {
                int num = 0;
                while (n % prime[i] == 0) {
                    num++;
                    n /= prime[i];
                }
                ans *= (num + 1);
            }
        }
        if (n > 1)ans *= 2;
        cout << "Case " << cas++ << ": " << ans - 1 << endl;
    }
    return 0;
}
