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
int V;
const int MAX_V = 10010;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!used[G[v][i]])dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        if (!used[rG[v][i]])rdfs(rG[v][i], k);
    }
}

int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 0; v < V; v++) {
        if (!used[v])dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!used[vs[i]])rdfs(vs[i], k++);
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        V = n;
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            add_edge(u - 1, v - 1);
        }
        int n = scc();
        u = 0;
        int num = 0;
        for (int v = 0; v < V; v++) {
            if (cmp[v] == n - 1) {
                u = v;
                num++;
            }
        }
        CLR(used, 0);
        rdfs(u, 0);
        for (int v = 0; v < V; v++) {
            if (!used[v]) {
                num = 0;
                break;
            }
        }
        cout << num << endl;
    }
    return 0;
}


