//
// Created by xyiyy on 2015/8/14.
//

#ifndef ICPC_ADJLIST_ARRAY_HPP
#define ICPC_ADJLIST_ARRAY_HPP

#define Foredge(A,X) for(int A = From[X];A!=-1;A = Next[A])

int From[maxEdge],To[maxEdge];
int Next[maxEdge];
int Edgecnt;
void init(int n){
    rep(i,n+1)From[i] = -1;
    Edgecnt = 0;
}
void addedge(int u,int v){
    To[Edgecnt] = v;
    Next[Edgecnt] = From[u];
    From[u] = Edgecnt++;
}

#endif //ICPC_ADJLIST_ARRAY_HPP
