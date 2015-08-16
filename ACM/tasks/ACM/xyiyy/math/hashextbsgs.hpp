//
// Created by xyiyy on 2015/8/16.
//

#ifndef ICPC_HASHEXTBSGS_HPP
#define ICPC_HASHEXTBSGS_HPP

#include "inv.hpp"
class  MyHash{
    static const int HASHMOD = (1<<17) - 1;
    int top, hash[HASHMOD + 100],value[HASHMOD + 100],stack[1<<16];
    int locate(const int x)const{
        int h = x % HASHMOD;
        while(hash[h]!=-1&&hash[h]!=x)h++;
        return h;
    }

public:
    MyHash():top(0) {clr(hash,-1);}
    void insert(const int x,const int v){
        const int h = locate(x);
        if(hash[h]==-1){
            hash[h] = x,value[h] = v,stack[++top] = h;
        }
    }
    int get(const int x)const {
        const int h = locate(x);
        return hash[h] == x ? value[h]:-1;
    }
    void clear(){while(top)hash[stack[top--]] = -1;}
}Hash;

int extbsgs(int a,int b,int n){
    ll tmp = 1,cnt = 0, D = 1;
    rep(i,32){
        if (tmp == b)return i;
        tmp = tmp * a % n;
    }
    for(int d = __gcd(a,n);d != 1;++cnt){
        if(b % d)return -1;
        b /= d; n /= d;
        D = D * (a / d) % n;
        d == __gcd(a,n);
    }
    int m = static_cast<int>(std::ceil(std::sqrt(n + 0.5)));
    Hash.clear();
    ll base = 1;
    rep(i,m){
        Hash.insert(base,i);
        base = base * a % n;
    }
    int v = inv(base,n);
    rep(i,m){
        int j = Hash.get(b);
        if(j!=-1)return i*m + j;
        b = (ll)b * v % n;
    }
    return -1;
}



#endif //ICPC_HASHEXTBSGS_HPP
