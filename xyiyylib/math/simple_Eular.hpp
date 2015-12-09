//
// Created by xyiyy on 2015/8/10.
//

#ifndef ICPC_SIMPLE_EULAR_HPP
#define ICPC_SIMPLE_EULAR_HPP

const int MAXN = 3000010;
ll phi[MAXN];

void Eular() {
    rep(i, MAXN)
    phi[i] = i;
    rep2(i, 2, MAXN - 1)
    {
        if (phi[i] == i) {
            for (int j = i; j < MAXN; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

#endif //ICPC_SIMPLE_EULAR_HPP
