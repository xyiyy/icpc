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

struct edge {
    int to, cap, f, rev;

    edge(int _to, int _cap, int _f, int _rev) {
        to = _to;
        cap = _cap;
        f = _f;
        rev = _rev;
    }
};

const int MAX_V = 5020;
vector<edge> G[MAX_V];
int level[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].PB(edge(to, cap, 0, G[to].size()));
    G[to].PB(edge(from, 0, 0, G[from].size() - 1));
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
            if (e.cap > e.f && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > e.f && level[v] == level[e.to] - 1) {
            int d = dfs(e.to, t, min(e.cap - e.f, f));
            if (d > 0) {
                e.f += d;;
                G[e.to][e.rev].f -= d;
                return d;
            }
        }
    }
    return 0;
}

ll Dinic(int s, int t) {
    ll flow = 0;
    for (; ;) {
        bfs(s, t);
        if (level[t] < 0)return flow;
        ll f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int ans = 0;
bool vis[MAX_V];

void dfs(int v, int t) {
    if (v == t)return;
    vis[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap != e.f && !vis[e.to] && e.to != t) {
            dfs(e.to, t);
            ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int key = 0;
        int s = n, t = s + 1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &key);
            if (key > 0) {
                add_edge(s, i, key);
                sum += key;
            }
            else {
                add_edge(i, t, -key);
            }
        }
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            add_edge(u - 1, v - 1, INF);
        }
        ll temp = Dinic(s, t);
        ans = 0;
        CLR(vis, 0);
        dfs(s, t);
        //cout<<"ok"<<endl;
        printf("%d %lld\n", ans, sum - temp);


    }

    return 0;
}



