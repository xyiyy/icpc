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

ll f(ll n) {
    ll ret = 0;
    while (n) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

char a[20];

bool check(ll n) {
    CLR(a, 0);
    int i = 0;
    while (n) {
        a[i++] = n % 10 + '0';
        n /= 10;
    }
    int len = strlen(a);
    bool flag = 0;
    for (i = 0; i < len; i++) {
        if (a[i] != a[len - 1 - i])flag = 1;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int num = 1;
        ll m = f(n);
        n = m + n;
        while (check(n) && num <= 8) {
            m = f(n);
            n = m + n;
            num++;
        }
        if (num > 8)
            num = 0;
        cout << num << endl;
    }
    return 0;
}


