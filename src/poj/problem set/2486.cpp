#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXN 10010
#define REP(A, X) for(int A=0;A<X;A++)
int head[MAXN];
int p[MAXN];
int Next[MAXN];
int a[MAXN];
int dp[110][210][2];
int tot;
bool vis[MAXN];
int k;

void init() {
    REP(i, MAXN)head[i] = -1;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    tot = 0;
}

void add_edge(int u, int v) {
    p[tot] = v;
    Next[tot] = head[u];
    head[u] = tot++;
    p[tot] = u;
    Next[tot] = head[v];
    head[v] = tot++;
}

void dfs(int u) {
    vis[u] = 1;
    //cout<<u<<endl;
    for (int i = head[u]; i != -1; i = Next[i]) {
        int v = p[i];
        //cout<<v<<endl;
        if (vis[v])continue;
        dfs(v);
        for (int j = k; j >= 0; j--) {
            for (int l = 0; l + j <= k; l++) {
                if (l >= 2)dp[u][j + l][0] = max(dp[u][j + l][0], dp[u][j][0] + dp[v][l - 2][0] + a[v]);
                if (l)dp[u][j + l][1] = max(dp[u][j + l][1], dp[u][j][0] + dp[v][l - 1][1] + a[v]);
                if (l >= 2)dp[u][j + l][1] = max(dp[u][j + l][1], dp[u][j][1] + dp[v][l - 2][0] + a[v]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (scanf("%d%d", &n, &k) != EOF) {
        REP(i, n)scanf("%d", &a[i]);
        int u, v;
        init();
        REP(i, n - 1) {
            scanf("%d%d", &u, &v);
            add_edge(u - 1, v - 1);
        }
        dfs(0);
        printf("%d\n", a[0] + max(dp[0][k][0], dp[0][k][1]));
    }
    return 0;
}
