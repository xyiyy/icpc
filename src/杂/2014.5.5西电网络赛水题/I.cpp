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

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;

const int N = 110;
vector<int> M[N], Q[N], G[N];
bool vis[N];
int father[N], ance[N], in[N], p[N];
int ex, ey;
int n, m;
int root;

void convert(int u, int fa) {
    int d = M[u].size();
    for (int i = 0; i < d; i++) {
        int v = M[u][i];
        if (v != fa)convert(v, p[v] = u);
    }
}

int find(int x) {
    return x == father[x] ? x : father[x] = find(father[x]);
}

void Union(int x, int y) {
    father[find(x)] = y;
}

void dfs(int u) {
    ance[u] = u;
    int dd = G[u].size();
    for (int i = 0; i < dd; ++i) {
        dfs(G[u][i]);
        Union(u, G[u][i]);
        ance[find(u)] = u;
    }
    vis[u] = 1;
    dd = Q[u].size();
    for (int i = 0; i < dd; i++) {
        if (vis[Q[u][i]] == 1) {
            printf("%d\n", ance[find(Q[u][i])]);
            return;
        }
    }
}

int main() {
//	ios::sync_with_stdio(false);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i <= n; i++) {
            vis[i] = false;
            //	in[i]=0;
            father[i] = i;
            ance[i] = 0;
            M[i].clear();
            Q[i].clear();
        }
        int u, v;
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            M[u].PB(v);
            M[v].PB(u);
            //	in[v]++;
        }
        scanf("%d", &m);
        while (m--) {
            for (int i = 0; i <= n; i++) {
                G[i].clear();
            }
            scanf("%d", &root);
            memset(p, 0, sizeof(p));
            p[root] = -1;
            convert(root, -1);
            scanf("%d%d", &u, &v);
            for (int i = 0; i <= n; i++) {
                if (p[i] != -1)
                    G[p[i]].PB(i);
            }
            Q[u].PB(v);
            Q[v].PB(u);
            dfs(root);
            for (int i = 0; i <= n; i++) {
                Q[i].clear();
                father[i] = i;
                ance[i] = 0;
            }
            memset(vis, 0, sizeof(vis));

        }
    }

    return 0;
}

