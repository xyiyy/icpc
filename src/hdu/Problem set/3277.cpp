//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MAXN 1010

struct edge {
    int to, cap, rev;

    edge(int _to, int _cap, int _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};

const int MAX_V = 5020;
vector<edge> G[MAX_V];
int iter[MAX_V];
int head[MAXN];
int _to[510 * 510];
int _flow[510 * 510];
int _next[510 * 510];
int level[MAX_V];
int tot = 0;

void add_edge(int from, int to, int cap) {
    G[from].PB(edge(to, cap, G[to].size()));
    G[to].PB(edge(from, 0, G[from].size() - 1));
}

void Add(int u, int v, int f) {
    _to[tot] = v;
    _flow[tot] = f;
    _next[tot] = head[u];
    head[u] = tot++;
}

void bfs(int s, int t) {
    CLR(level, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            edge &e = G[u][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int Dinic(int s, int t) {
    int flow = 0;
    for (; ;) {
        bfs(s, t);
        if (level[t] < 0)return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int a[210][210];

int main() {
    ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, f;
        scanf("%d%d%d", &n, &m, &f);
        tot = 0;
        for (int i = 0; i < MAXN; i++)head[i] = -1;
        int u, v;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            a[u][v + n] = 1;
        }
        for (int i = 0; i < f; i++) {
            scanf("%d%d", &u, &v);
            a[u][v] = 1;
            a[v][u] = 1;
        }
        for (int i = 1; i <= n + n; i++)a[i][i] = 1;
        for (int k = 1; k <= n + n; k++) {
            for (int i = 1; i <= n + n; i++) {
                for (int j = 1; j <= n + n; j++) {
                    a[i][j] = max(a[i][j], a[i][k] & a[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1 + n; j <= n + n; j++) {
                if (a[i][j])Add(i, j, 1);
            }
        }
        int l = 0, r = n;
        int s = 0, t = 2 * n + 1;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            for (int i = 0; i <= 2 * n + 1; i++)G[i].clear();
            for (int i = 1; i <= 2 * n; i++) {
                int now = head[i];
                while (now != -1) {
                    add_edge(i, _to[now], _flow[now]);
                    now = _next[now];
                }
            }
            for (int i = 1; i <= n; i++) {
                add_edge(s, i, mid);
                add_edge(n + i, t, mid);
            }
            if (Dinic(s, t) == mid * n) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }


    return 0;
}
