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
vector<int> G[5010];
int dfn[5010], low[5010];
int vis[5010];
int point[5010];
int ans, maxx;
int dclock;
int n, m;

void tarjan(int u, int lim) {
    vis[u] = 1;
    int son = 0;
    dfn[u] = low[u] = ++dclock;
    for (int i = 0; i < G[u].size(); i++) {
        if (G[u][i] == lim)continue;
        int v = G[u][i];
        if (!vis[v]) {
            tarjan(v, lim);
            son++;
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])point[u]++;
        }
        else if (vis[v])low[u] = min(low[u], dfn[v]);
    }
}


int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        ans = maxx = 0;
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            if (u == v)continue;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int num;
        for (int i = 0; i < n; i++) {
            dclock = 0;
            memset(dfn, 0, sizeof(dfn));
            memset(low, 0, sizeof(low));
            memset(vis, 0, sizeof(vis));
            fill(point, point + n, 1);
            num = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && !vis[j]) {
                    num++;
                    point[j] = 0;
                    tarjan(j, i);
                }
            }

            //	cout<<"i: "<<endl;
            //	for(int j=0;j<n;j++)
            //	{
            //		cout<<point[j]<<" ";
            //	}
            //	cout<<endl;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    maxx = max(num + point[j] - 1, maxx);
            }
        }
        cout << maxx << endl;
    }
    return 0;
}

