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
int n, q;
const int maxn = 100010;
ll bit0[maxn], bit1[maxn];

void add(ll *b, int i, int x) {
    while (i <= n) {
        b[i] += x;
        i += i & -i;
    }
}

ll sum(ll *b, int i) {
    ll s = 0;
    while (i > 0) {
        s += b[i];
        i -= i & -i;
    }
    return s;
}

void query(int l, int r) {
    ll ans = 0;
    ans += sum(bit0, r) + sum(bit1, r) * r;
    ans -= sum(bit0, l - 1) + sum(bit1, l - 1) * (l - 1);
    printf("%lld\n", ans);
}

void Add(int l, int r, int inc) {
    add(bit0, l, -inc * (l - 1));
    add(bit1, l, inc);
    add(bit0, r + 1, inc * r);
    add(bit1, r + 1, -inc);
}

void init() {
    CLR(bit0, 0);
    CLR(bit1, 0);
}

int main() {
    ios::sync_with_stdio(false);

    while (scanf("%d%d", &n, &q) != EOF) {
        init();
        int num;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            add(bit0, i + 1, num);
        }
        char qu[10];
        int l, r, inc;
        for (int i = 0; i < q; i++) {
            scanf("%s", qu);
            if (qu[0] == 'Q') {
                scanf("%d%d", &l, &r);
                query(l, r);
            }
            else {
                scanf("%d%d%d", &l, &r, &inc);
                Add(l, r, inc);
            }
        }
    }
    return 0;
}


