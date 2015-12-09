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
const int maxn = 100010;
int num[maxn];
int sum[maxn];
int minn[maxn * 4];

void push_up(int rt) {
    minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]);
}

void build(int l, int r, int cur) {
    if (l == r) {
        minn[cur] = num[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur << 1);
    build(mid + 1, r, cur << 1 | 1);
    push_up(cur);
}

int query(int curl, int curr, int l, int r, int cur) {
    if (curl <= l && curr >= r) {
        return minn[cur];
    }
    int mid = (l + r) >> 1;
    int m = -1;
    if (curl <= mid)m = min(query(curl, curr, l, mid, cur << 1), m);
    if (curr > mid)m = min(query(curl, curr, mid + 1, r, cur << 1 | 1), m);
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (scanf("%d", &n) != EOF) {
        CLR(num, 0);
        fill(minn, minn + maxn * 4, INF);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i - 1]);
            sum[i] = sum[i - 1] + num[i - 1];
        }
        build(0, n - 1, 1);
        int q;
        int x, y;
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &x, &y);
            printf("%d\n", sum[x] - num[0] + query(x - 1, y - 1, 0, n, 1));
        }
    }

    return 0;
}


