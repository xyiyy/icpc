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

struct edge {
    int to, cap, rev;

    edge(int _to, int _cap, int _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};

const int MAXN = 3010;
vector<edge> G[MAXN];
int level[MAXN];
//层次标号
int iter[MAXN];

//当前弧
void init(int n) {
    for (int i = 0; i < MAXN; i++)G[i].clear();
}

void add_edge(int u, int v, int cap) {
    G[u].PB(edge(v, cap, G[v].size()));
    G[v].PB(edge(u, 0, G[u].size() - 1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (int i = 0; i < G[x].size(); i++) {
            edge &e = G[x][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[x] + 1;
                que.push(e.to);
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
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int dinic(int s, int t) {
    int flow = 0;
    while (1) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

vector<PII> Map[MAXN];
int vis[MAXN];
int dis[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        init(n);
        int u, v, d;
        for (int i = 0; i < n; i++)Map[i].clear();
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &d);
            //cin>>u>>v>>d;
            u--;
            v--;
            Map[u].PB(MP(v, d));
            Map[v].PB(MP(u, d));
        }
        for (int i = 0; i < n; i++)vis[i] = 0;
        for (int i = 0; i < n; i++)dis[i] = (i == 0 ? 0 : INF);
        priority_queue<PII, VII, greater<PII> > q;
        q.push(MP(0, 0));
        while (!q.empty()) {
            PII p = q.top();
            q.pop();
            int x = p.second;
            if (vis[x])continue;
            vis[x] = 1;
            for (int i = 0; i < Map[x].size(); i++) {
                p = Map[x][i];
                int y = p.first;
                int d = p.second;
                if (!vis[y] && dis[x] + d < dis[y]) {
                    dis[y] = dis[x] + d;
                    q.push(MP(dis[y], y));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < Map[i].size(); j++) {
                PII p = Map[i][j];
                int y = p.first;
                int d = p.second;
                w
                if (dis[i] + d == dis[y]) {
                    add_edge(i, y, 1);
                }
            }
        }
        bfs(0);
        int ans = level[n - 1];
        cout << dinic(0, n - 1) << " " << m - ans << endl;
    }
    return 0;
}



