//
// Created by xyiyy on 2015/8/5.
//

#ifndef ICPC_GEULAR_HPP
#define ICPC_GEULAR_HPP
const int MAXN = 200010;
int head[MAXN];
int Next[MAXN], To[MAXN];
int tot;

void init(int n) {
    tot = 0;
    rep(i, n)
    head[i] = -1;
}

void addedge(int u, int v) {
    Next[tot] = head[u];
    To[tot] = v;
    head[u] = tot++;
}

void euler(int u) {
    for (int i = head[u]; i != -1; i = Next[i]) {
        int v = To[i];
        head[u] = Next[i];
        euler(v);
    }
}

#endif //ICPC_GEULAR_HPP
