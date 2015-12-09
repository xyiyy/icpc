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
const int MAX_V = 410;

struct edge {
    int to, cap, f, rev;

    edge(int _to, int _cap, int _f, int _rev) {
        to = _to;
        cap = _cap;
        f = _f;
        rev = _rev;
    }
};

vector<edge> G[MAX_V];

void add_edge(int u, int v, int cap) {
    G[u].PB(edge(v, cap, 0, G[v].size()));
    G[v].PB(edge(u, 0, 0, G[u].size() - 1));
}

int level[MAX_V];
int s, t;

void bfs() {
    CLR(level, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            edge &e = G[u][i];
            if (e.cap > e.f && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int f) {
    if (v == t)return f;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (level[v] < level[e.to] && e.cap > e.f) {
            int d = dfs(e.to, min(f, e.cap - e.f));
            if (d > 0) {
                e.f += d;
                G[e.to][e.rev].f -= d;
                return d;
            }
        }
    }
    return 0;
}

int Dinic() {
    int flow = 0;
    for (; ;) {
        bfs();
        if (level[t] < 0)return flow;
        int f;
        while ((f = dfs(s, INF)) > 0) {
            flow += f;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, f, d;
    while (cin >> n >> f >> d) {
        int nf, nd;
        int x;
        s = 2 * n + f + d, t = s + 1;
        for (int i = 0; i < f; i++) {
            add_edge(s, 2 * n + i, 1);
        }
        for (int i = 0; i < d; i++) {
            add_edge(2 * n + f + i, t, 1);
        }
        for (int i = 0; i < n; i++) {
            cin >> nf >> nd;
            add_edge(i, n + i, 1);
            int id = 0;
            while (nf--) {
                cin >> x;
                x--;
                add_edge(x + 2 * n, i, 1);
                //	add_edge(s,x+2*n,1);
            }
            while (nd--) {
                cin >> x;
                x--;
                add_edge(n + i, 2 * n + f + x, 1);
                //	add_edge(2*n+f+x,t,1);
            }
        }
        cout << Dinic() << endl;
    }
    return 0;
}



