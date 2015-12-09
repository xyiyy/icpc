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
const int MAXN = 100010;
vector<PII> G[MAXN];

void add_edge(int u, int v, int d) {
    G[u].PB(MP(v, d));
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        G[i].clear();
    }
}

int vis[MAXN];
int dis[MAXN];
int ans[MAXN];

void dijkstra(int s, int n) {
    for (int i = 0; i < n; i++)vis[i] = 0;
    for (int i = 0; i < n; i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII, VII, greater<PII> > q;
    q.push(MP(dis[s], s));
    while (!q.empty()) {
        PII p = q.top();
        int x = p.second;
        q.pop();
        if (vis[x])continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++) {
            int y = G[x][i].first;
            int d = G[x][i].second;
            if (!vis[y] && dis[x] + d < dis[y]) {
                dis[y] = dis[x] + d;
                q.push(MP(dis[y], y));
                ans[y] = x;
            }
        }
    }
}

void dfs(int x) {
    if (ans[x] == -1) {
        cout << x + 1;
        return;
    }
    dfs(ans[x]);
    cout << " " << x + 1;
}


int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int u, v;
        init(n);
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            u--;
            v--;
            add_edge(u, v, 1);
            add_edge(v, u, 1);
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--;
            v--;
            for (int i = 0; i < n; i++)ans[i] = -1;
            dijkstra(u, n);
            dfs(v);
            cout << endl;
        }
    }


    return 0;
}



