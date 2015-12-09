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
int n, m, w;
struct edge {
    int u, v, l;
} e[6030];
int dis[610];
int tot = 0;

bool bellmen() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < tot; j++) {
            int x = e[j].u, y = e[j].v;
            dis[e[j].v] = min(dis[e[j].v], dis[e[j].u] + e[j].l);
        }
    }
    for (int i = 0; i < tot; i++) {
        if (dis[e[i].v] > dis[e[i].u] + e[i].l)return 1;
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        tot = 0;
        cin >> n >> m >> w;
        int u, v, l;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> l;
            e[tot].u = u;
            e[tot].v = v;
            e[tot++].l = l;
            e[tot].u = v;
            e[tot].v = u;
            e[tot++].l = l;
        }
        for (int i = 0; i < w; i++) {
            cin >> u >> v >> l;
            e[tot].u = u;
            e[tot].v = v;
            e[tot++].l = -l;
        }
        if (bellmen()) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}


