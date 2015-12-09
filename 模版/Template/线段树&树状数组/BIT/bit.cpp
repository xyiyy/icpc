// Binary Indexed Tree
// 单点更新 / 区间查询 
// 复杂度 O(nlogn)
// 2014.5.4
// By Curs0r

struct BIT {
    int sz;
    ll *bit;

    void init() {
        REP(i, sz + 1)
        bit[i] = 0;
    }

    BIT(int size) {
        sz = size > 0 ? size : 0;
        bit = new ll[sz + 1];
        this->init(); // initialize
    }

    ~BIT() {
        delete[] bit;
    }

    void add(int i, ll x) {
        while (i <= sz) {
            bit[i] += x;
            i += i & -i;
        }
    }

    ll query(int i) {
        ll sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    int kth(int k) {
        int r = 0, h = H;
        while (h >>= 1) {
            r += h;
            if (r > sz || bit[r] >= k)
                r -= h;
            else
                k -= bit[r];
        }
        /*
        int i = r+1;
        while(i<=sz)
        {
            bit[i]--;
            i += i&-i;
        }
        */
        return r;
    }
};
