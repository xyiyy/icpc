//
// Created by xyiyy on 2015/8/14.
//

#ifndef ICPC_HASHTREE_HPP
#define ICPC_HASHTREE_HPP

//树的同构，返回哈希值
//输入有根树的根，或者无根树的重心
typedef unsigned long long ull;
const ull MAGIC = 321;

#include "adjList_array.hpp"

ull powMod(ull a,int n){
    ull ret = 1ULL;
    while(n){
        if(n&1)ret *= a;
        a *= a;
        n>>=1;
    }
    return ret;
}

struct Hash{
    int length;
    ull value;
    Hash(): length(0),value(0){}
    Hash(char c):length(1),value(c){}
    Hash(int l,int v):length(l),value(v){}
};
bool operator <(const Hash &a,const Hash &b){
    return a.value < b.value;
}
Hash operator +(const Hash &a,const Hash &b){
    return Hash(a.length + b.length, a.value * powMod(MAGIC,b.length) + b.value);
}
void operator +=(Hash &a,Hash &b){
    a = a + b;
}

vector<Hash> childs[maxNode];

Hash dfs(int pre,int cur){
    Hash ret;
    childs[cur].clear();
    for(int iter = From[cur];iter != -1;iter = Next[iter]){
        if(To[iter] != pre){
            childs[cur].pb(dfs(cur,To[iter]));
        }
    }
    sort(ALL(childs[cur]));
    for(vector<Hash>::iterator iter = childs[cur].begin();iter != childs[cur].end();iter++){
        ret += *iter;
    }
    Hash retL = Hash('(');
    ret = '(' + ret + ')';
    return ret;
}
ull getHash(int root){
    return dfs(-1,root).value;
}

#endif //ICPC_HASHTREE_HPP
