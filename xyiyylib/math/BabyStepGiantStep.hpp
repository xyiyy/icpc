//
// Created by xyiyy on 2015/8/16.
//

#ifndef ICPC_BABYSTEPGIANTSTEP_HPP
#define ICPC_BABYSTEPGIANTSTEP_HPP

//O((m+n/m)logm)
//当m和n/m接近时为O(sqrt(n)logn)
//a^x = b (mod n)
//n为素数，无解返回-1
#include "inv.hpp"
ll mul_mod(ll a,ll b,ll mod){
    return a * b % mod;
}
int bsgs(int a,int b,int n){
    int m, v, e = 1, i;
    m = (int)sqrt(n + 0.5);
    map<int,int> x;
    rep(i,m){
        if(!x.count(e))x[e] = i;
        e = mul_mod(e, a, n);
    }
    v = inv(e,n);
    rep(i,m){
        if(x.count(b))return i*m + x[b];
        b = mul_mod(b,v,n);
    }
    return -1;
}

#endif //ICPC_BABYSTEPGIANTSTEP_HPP
