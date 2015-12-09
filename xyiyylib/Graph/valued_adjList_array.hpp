//
// Created by xyfra_000 on 2015/8/14.
//

#ifndef ICPC_VALUED_ADJLIST_ARRAY_HPP
#define ICPC_VALUED_ADJLIST_ARRAY_HPP

int From[maxEdge], To[maxEdge];
int Next[maxEdge], w[maxEdge];
int Edgecnt;

void init(int n) {
    rep(i, n + 1)
    From[i] = -1;
    Edgecnt = 0;
}

void addedge(int u, int v, int d) {
    To[Edgecnt] = v;
    w[Edgecnt] = d;
    Next[Edgecnt] = From[u];
    From[u] = Edgecnt++;
}

#endif //ICPC_VALUED_ADJLIST_ARRAY_HPP
