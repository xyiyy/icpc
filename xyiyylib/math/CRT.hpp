//
// Created by xyiyy on 2015/8/16.
//

#ifndef ICPC_CRT_HPP
#define ICPC_CRT_HPP

void extgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

ll CRT(int n, ll *a, ll *m) {
    ll M = 1, d, y, x = 0;
    rep(i, n)
    M *= m[i];
    rep(i, n)
    {
        ll w = M / m[i];
        extgcd(m[i], w, d, d, y);
        x = (x + y * w * a[i]) % M;
    }
    return (x + M) % M;
}


#endif //ICPC_CRT_HPP
