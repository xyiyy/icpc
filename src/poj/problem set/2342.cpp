#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define  MAXN 6010
#define REP(A, X) for(int A=0;A<X;A++)
int a[MAXN];
int dp[MAXN][2];
int head[MAXN];
int Next[MAXN * 2];
int p[MAXN * 2];
bool vis[MAXN];
int tot = 0;

void init() {
    tot = 0;
    REP(i, MAXN)head[i] = -1;
    memset(vis, 0, sizeof(vis));
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
    dp[u][1] = a[u];
    dp[u][0] = 0;
    for (int i = head[u]; i != -1; i = Next[i]) {
        int v = p[i];
        if (vis[v])continue;
        dfs(v);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (scanf("%d", &n) != EOF) {
        init();
        REP(i, n)scanf("%d", &a[i]);
        int u, v;
        while (scanf("%d%d", &u, &v) != EOF && (u || v))add_edge(u - 1, v - 1);
        dfs(0);
        printf("%d\n", max(dp[0][1], dp[0][0]));
    }
    return 0;
}
