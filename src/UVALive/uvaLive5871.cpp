#include "../xyiyy/lib.hpp"

int num[2 * 500010];
int L[500010], R[500010];
char c[500010];
const int MAXN = 10000010;
int sz = 0;

struct SBT {
    int left, right, size, key;

    void init() {
        left = right = key = 0;
        size = 1;
    }
} sbt[MAXN];

int root[2 * 500010], tot;

void left_rot(int &x) {
    int k = sbt[x].right;
    sbt[x].right = sbt[k].left;
    sbt[k].left = x;
    sbt[k].size = sbt[x].size;
    sbt[x].size = sbt[sbt[x].left].size + sbt[sbt[x].right].size + 1;
    x = k;
}

void right_rot(int &x) {
    int k = sbt[x].left;
    sbt[x].left = sbt[k].right;
    sbt[k].right = x;
    sbt[k].size = sbt[x].size;
    sbt[x].size = sbt[sbt[x].left].size + sbt[sbt[x].right].size + 1;
    x = k;
}

void maintain(int &r, bool flag) {
    if (flag) {
        if (sbt[sbt[sbt[r].right].right].size > sbt[sbt[r].left].size)
            left_rot(r);
        else if (sbt[sbt[sbt[r].right].left].size > sbt[sbt[r].left].size) {
            right_rot(sbt[r].right);
            left_rot(r);
        }
        else
            return;
    }
    else {
        if (sbt[sbt[sbt[r].left].left].size > sbt[sbt[r].right].size)
            right_rot(r);
        else if (sbt[sbt[sbt[r].left].right].size > sbt[sbt[r].right].size) {
            left_rot(sbt[r].left);
            right_rot(r);
        }
        else
            return;
    }
    maintain(sbt[r].left, false);
    maintain(sbt[r].right, true);
    maintain(r, false);
    maintain(r, true);
}

void insert(int &r, int k) {
    if (r == 0) {
        r = ++tot;
        sbt[r].init();
        sbt[r].key = k;
    }
    else {
        sbt[r].size++;
        if (k < sbt[r].key)
            insert(sbt[r].left, k);
        else
            insert(sbt[r].right, k);
        maintain(r, k >= sbt[r].key);
    }
}

int query(int &r, int key) {
    if (!r)return 0;
    int ret = sbt[sbt[r].right].size + 1;
    if (sbt[r].key >= key) return ret + query(sbt[r].left, key);
    else return query(sbt[r].right, key);
}

void update(int i, int v) {
    while (i <= v) {
        insert(root[i], v);
        i += i & -i;
    }
}

int gao(int x, int r) {
    int ret = 0;
    while (x > 0) {
        ret += query(root[x], r);
        x -= x & -x;
    }
    return ret;
}

class uvaLive5871 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        while (in >> n) {
            rep(i, n)
            in >> c[i] >> L[i] >> R[i];
            rep(i, n)
            {
                num[i << 1] = L[i];
                num[i << 1 | 1] = R[i];
            }
            sort(num, num + n * 2);
            int m = unique(num, num + n * 2) - num;
            sz = m;
            rep2(i, 0, m)
            root[m] = 0;
            tot = 0;
            rep(i, n)
            {
                L[i] = lower_bound(num, num + m, L[i]) - num + 1;
                R[i] = lower_bound(num, num + m, R[i]) - num + 1;
            }
            rep(i, n)
            {
                if (c[i] == '+') {
                    update(L[i], R[i]);
                } else out << gao(L[i], R[i]) << endl;
            }
        }
    }
};