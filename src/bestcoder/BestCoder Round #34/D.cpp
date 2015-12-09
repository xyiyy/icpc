#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <functional>
#include <ios>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
#define MAXN 100010
int bit[MAXN];

int sum(int x) {
    int s = 0;
    while (x > 0) {
        s += bit[x];
        x -= x & -x;
    }
    return s;
}

void add(int i, int x) {
    while (i <= N) {
        bit[i] += x;
        i += i & -i;
    }
}

int siz[MAXN];
int tot = 0;
int lson[MAXN], rson[MAXN];

void init() {
    key[0] = siz[0] = lson[0] = rson[0] = 0;
    tot = 0;
}

int newnode(int k) {
    int r = ++tot;
    key[r] = k;
    siz[r] = 1;
}

int change(int t, int l, int r) {
    siz[t] = siz[l] + siz[r] + 1;
    lson[t] = l;
    rson[t] = r;
}

void splitsize(int t, int s, int *ret) {
    if (s <= 0) {
        ret[0] = 0;
        ret[1] = t;
    } else if (s <= siz[lson[t]]) {
        splitsize(lson[t], s, ret);
        ret[1] = change(t, ret[1], rson[t]);
    } else {
        splitsize(rson[t], s - siz[lson[t]] - 1, , ret);
        ret[0] = change(t, lson[t], ret[0]);
    }
}

void merge(int l, int r) {

}


}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", x + i, y + i, z + i);
            idx[i] = i;
        }
    }
    return 0;
}

