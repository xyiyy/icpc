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

ll quick_pow(ll m, int n) {
    ll ret = 1;
    while (n) {
        if (n & 1)ret = ret * m;
        m *= m;
        n >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int c;
    while (cin >> c) {
        ll ans = 4 / 2 * (quick_pow(c, 2) + quick_pow(c, 4 / 2 + 1));
        REP(i, 4)ans += quick_pow(c, __gcd(4, i + 1));
        cout << ans / 8 << endl;
    }
    return 0;
}



