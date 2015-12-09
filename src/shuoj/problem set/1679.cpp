//gaoshenbaoyou  ------ pass system test
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
int C[410][510];
const int MOD = 1000007;

void init() {
    C[1][1] = C[1][0] = 1;
    for (int i = 2; i < 410; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    init();
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int sum = 0;
        for (int i = 0; i < 16; i++) {
            int r = n, c = m, b = 0;
            if (i & 1) { b++, r--; }
            if (i & 2) { b++, r--; }
            if (i & 4) { b++, c--; }
            if (i & 8) { b++, c--; }
            if (b & 1)sum = ((sum - C[r * c][k]) % MOD + MOD) % MOD;
            else sum = (sum + C[r * c][k]) % MOD;
        }
        cout << sum << endl;
    }


    return 0;
}



