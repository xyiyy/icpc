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
set<int> s[1010];
int x[1010], y[1010];
int n, d;
int vis[1010];
#define MAXN 1010

int pa[MAXN]; // parent
int ra[MAXN]; // rank

void init(int n) {
    for (int i = 0; i < n; i++) {
        pa[i] = i;
        ra[i] = 0;
    }
}

int find(int x) {
    if (pa[x] != x) pa[x] = find(pa[x]);
    return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return 0;
    if (ra[x] < ra[y]) {
        pa[x] = y;
    } else {
        pa[y] = x;
        if (ra[x] == ra[y]) ra[x]++;
    }
    return 1;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    //ios::sync_with_stdio(false);
    scanf("%d%d", &n, &d);
    d = d * d;
    CLR(vis, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    char a[10];
    init(n);
    int p, q;
    while (scanf("%s", a) != EOF) {
        if (a[0] == 'O') {
            scanf("%d", &p);
            vis[p - 1] = 1;
            for (int i = 0; i < n; i++) {
                if (i == p - 1)continue;
                else if (same(i, p - 1))continue;
                else if ((x[i] - x[p - 1]) * (x[i] - x[p - 1]) + (y[i] - y[p - 1]) * (y[i] - y[p - 1]) <= d && vis[i]) {
                    unite(i, p - 1);
                }
            }
        }
        else {
            scanf("%d%d", &p, &q);
            if (same(p - 1, q - 1))printf("SUCCESS");
            else printf("FAIL");
            printf("\n");
        }
    }
    return 0;
}


