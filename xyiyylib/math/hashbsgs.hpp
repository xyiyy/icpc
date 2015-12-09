//
// Created by xyiyy on 2015/8/16.
//

#ifndef ICPC_HASHBSGS_HPP
#define ICPC_HASHBSGS_HPP

//O(sqrt(n))
//a^x = b (mod n)
#include "inv.hpp"

class MyHash {
    static const int HASHMOD = (1 << 17) - 1;
    int top, hash[HASHMOD + 100], value[HASHMOD + 100], stack[1 << 16];

    int locate(const int x) const {
        int h = x % HASHMOD;
        while (hash[h] != -1 && hash[h] != x)h++;
        return h;
    }

public:
    MyHash() : top(0) { clr(hash, -1); }

    void insert(const int x, const int v) {
        const int h = locate(x);
        if (hash[h] == -1) {
            hash[h] = x, value[h] = v, stack[++top] = h;
        }
    }

    int get(const int x) const {
        const int h = locate(x);
        return hash[h] == x ? value[h] : -1;
    }

    void clear() { while (top)hash[stack[top--]] = -1; }
} Hash;

ll bsgs(ll a, ll b, ll n) {
    int m = static_cast<int>(std::ceil(std::sqrt(n + 0.5)));
    ll base = 1;
    Hash.clear();
    rep(i, m)
    {
        Hash.insert(base, i);
        base = base * a % n;
    }
    int v = inv(base, n);
    rep(i, m)
    {
        int j = Hash.get(b);
        if (j != -1)return i * m + j;
        b = b * v % n;
    }
    return -1;
}


#endif //ICPC_HASHBSGS_HPP
