//
// Created by xyfra_000 on 2015/8/14.
//

#ifndef ICPC_TREEDIAMETER_HPP
#define ICPC_TREEDIAMETER_HPP

//求树的直径
//可以通过修改dfs部分变成求带权的树的直径
#include "adjList_array.hpp"
vector<int>dist;
void dfs(int p,int u,int d){
    dist[u] = d;
    Foredge(i,u){
        if(To[i] != p){
            dfs(u, To[i], d + 1);
        }
    }
}
int getDiameter(int n){
    dist.resize(n);
    dfs(-1,0,0);
    int u = max_element(ALL(dist)) - dist.begin();
    dfs(-1,u,0);
    return *max_element(ALL(dist));
}


#endif //ICPC_TREEDIAMETER_HPP
