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
int vis[110];
int dis[110];
vector<PII> G[110], G1[110], G2[110];
int p[110];

void dijkstra(int s) {
    CLR(vis, 0);
    priority_queue<PII, VII, greater<PII> > q;
    q.push(MP(0, s));
    dis[s] = 0;
    while (!q.empty()) {
        PII p = q.top();
        q.pop();
        int x = p.second;
        if (vis[x])continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++) {
            PII tmp = G[x][i];
            int y = tmp.first;
            int d = tmp.second;
            if (dis[x] + d < dis[y]) {
                dis[y] = dis[x] + d;
                q.push(MP(dis[y], y));
            }
        }
    }
}

bool cmp(int x, int y) {
    return dis[x] < dis[y];
}

void dijkstra1(int s) {
    CLR(vis, 0);
    for (int i = 0; i < 110; i++)dis[i] = INF;
    priority_queue<PII, VII, greater<PII> > q;
    q.push(MP(0, s));
    dis[s] = 0;
    while (!q.empty()) {
        PII p = q.top();
        q.pop();
        int x = p.second;
        if (vis[x])continue;
        vis[x] = 1;
        for (int i = 0; i < G2[x].size(); i++) {
            PII tmp = G2[x][i];
            int y = tmp.first;
            int d = tmp.second;
            if (dis[x] - d < dis[y]) {
                dis[y] = dis[x] - d;
                q.push(MP(dis[y], y));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, s, e;
        cin >> n >> m >> s >> e;
        for (int i = 0; i <= n; i++)G[i].clear(), G1[i].clear(), G2[i].clear();
        for (int i = 0; i <= n; i++)dis[i] = INF;
        int u, v, d1, d2;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> d1 >> d2;
            G[u].PB(MP(v, d1));
            G[v].PB(MP(u, d1));
            G1[u].PB(MP(v, d2));
            G1[v].PB(MP(u, d2));
        }
        dijkstra(s);
        cout << dis[e] << " ";
        for (int i = 1; i <= n; i++)p[i] = i;
        sort(p, p + n, cmp);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                if (dis[G[i][j].first] == dis[i] + G[i][j].second) {
                    G2[i].PB(MP(G1[i][j].first, G1[i][j].second));
                }
            }
        }
        dijkstra1(s);
        cout << -dis[e] << endl;
    }
    return 0;
}


