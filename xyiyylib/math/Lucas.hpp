//
// Created by xyiyy on 2015/8/15.
//

#ifndef ICPC_LUCAS_HPP
#define ICPC_LUCAS_HPP

#include "inv.hpp"

ll C(int n, int m, ll mod) {
    if (n < m)return 0;
    if (m == 0)return 1;
    ll ret = 1;
    rep(i, m)
    {
        ret = ret * (n - i) % mod * inv(i + 1, mod) % mod;
    }
    return ret;
}

ll Lucas(ll n, ll m, ll mod) {
    if (m == 0)return 1;
    else return (C(n % mod, m % mod, mod) * Lucas(n / mod, m / mod, mod)) % mod;
}


#endif //ICPC_LUCAS_HPP
