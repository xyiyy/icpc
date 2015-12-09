#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
#define INF 0x3FFFFFFF
#define CLR(A, X) memset(A,X,sizeof(A))
const int maxn = 410;
struct node {
    int w, f;
} net[maxn][maxn];
int level[maxn];

void bfs(int s, int t) {
    CLR(level, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i <= t; i++) {
            if (level[i] < 0 && net[v][i].w > net[v][i].f) {
                level[i] = level[v] + 1;
                que.push(i);
            }
        }
    }
}

void add_edge(int u, int v, int cap) {
    net[u][v].w = cap;
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    int flow;
    for (int i = 0; i <= t; i++) {
        if (net[v][i].w > net[v][i].f && level[i] == level[v] + 1) {
            int d = dfs(i, t, min(f, net[v][i].w - net[v][i].f));
            if (d > 0) {
                net[v][i].f += d;
                net[i][v].f -= d;
                return d;
            }
        }
    }
    return 0;
}

int Dinic(int s, int t) {
    int flow = 0;
    for (; ;) {
        bfs(s, t);
        if (level[t] < 0)return flow;
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int main() {
    int n, s, t, S, T;
    int num;
    while (scanf("%d%d%d", &n, &S, &T) != EOF) {
        S--;
        T--;
        CLR(net, 0);
        s = 2 * n, t = 2 * n + 1;
        add_edge(s, S, INF);
        add_edge(T + n, t, INF);
        for (int i = 0; i < n; i++) {
            add_edge(i, i + n, 1);
            for (int j = 0; j < n; j++) {
                scanf("%d", &num);
                if (num)add_edge(i + n, j, INF);
            }
        }
        add_edge(S, S + n, INF);
        add_edge(T, T + n, INF);
        if (!net[S + n][T].w) {
            int f = Dinic(s, t);
            printf("%d\n", f);
            int temp = f;
            set<int> person;
            set<int>::iterator it;
            for (int i = 0; i < n && temp; i++) {
                if (i == S || i == T)continue;
                if (!net[i][i + n].f)continue;
                net[i][i + n].w = 0;
                for (int a = 0; a <= t; a++) {
                    for (int b = 0; b <= t; b++) {
                        net[a][b].f = 0;
                    }
                }
                int k = 0;
                for (; ;) {
                    bfs(s, t);
                    if (level[t] < 0)break;
                    int ff;
                    while ((ff = dfs(s, t, INF)) > 0) {
                        k += ff;
                    }
                }
                if (k != temp) {
                    person.insert(i + 1);
                    temp = k;
                }
                else net[i][i + n].w = 1;
            }
            int c = 0;
            for (it = person.begin(); it != person.end(); it++) {
                if (c++)printf(" ");
                printf("%d", *it);
            }
            printf("\n");

        }
        else {
            printf("NO ANSWER!\n");
        }
    }
    return 0;
}

/*
3 1 3
1 1 0
1 1 1
0 1 1
9 1 9
1 1 1 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0
1 1 1 0 1 1 0 0 0
0 1 0 1 0 0 1 0 0
0 1 1 0 1 0 1 1 0
0 0 1 0 0 1 0 1 0
0 0 0 1 1 0 1 1 1 
0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 1 1 1
*/ 
