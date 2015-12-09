#include <cstdio>

using namespace std;
typedef long long ll;
#define Key_value ch[ch[root][1]][0]
const int maxn = 100010;
ll num[maxn];
ll key[maxn], add[maxn], sum[maxn];
int ch[maxn][2], pre[maxn], size[maxn];
int root, tot;

void newnode(int &r, int father, ll k) {
    r = ++tot;
    pre[r] = father;
    ch[r][0] = ch[r][1] = 0;
    size[r] = 1;
    add[r] = 0;
    sum[r] = key[r] = k;
}

void update(int r, ll inc) {
    if (!r)return;
    sum[r] += size[r] * inc;
    add[r] += inc;
    key[r] += inc;
}

void push_down(int r) {
    if (add[r]) {
        update(ch[r][0], add[r]);
        update(ch[r][1], add[r]);
        add[r] = 0;
    }
}

void push_up(int r) {
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
    sum[r] = sum[ch[r][0]] + sum[ch[r][1]] + key[r];
}

void rotate(int x, int d) {
    int y = pre[x];
    push_down(y);
    push_down(x);
    ch[y][!d] = ch[x][d];
    pre[ch[x][d]] = y;
    if (pre[y])ch[pre[y]][ch[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    ch[x][d] = y;
    pre[y] = x;
    push_up(y);
}

void splay(int x, int goal) {
    push_down(x);
    while (pre[x] != goal) {
        if (pre[pre[x]] == goal) {
            rotate(x, ch[pre[x]][0] == x);
        }
        else {
            int y = pre[x];
            int d = ch[pre[y]][0] == y;
            if (ch[y][d] == x) {
                rotate(x, !d);
                rotate(x, d);
            }
            else {
                rotate(y, d);
                rotate(x, d);
            }
        }
    }
    push_up(x);
    if (goal == 0)root = x;
}

void build(int &x, int l, int r, int fa) {
    if (l > r)return;
    int mid = (l + r) / 2;
    newnode(x, fa, num[mid]);
    build(ch[x][0], l, mid - 1, x);
    build(ch[x][1], mid + 1, r, x);
    push_up(x);
}

void init(int n) {
    root = tot = 0;
    ch[root][0] = ch[root][1] = pre[root] = 0;
    sum[root] = key[root] = add[root] = 0;
    size[root] = 0;
    newnode(root, 0, 0);
    newnode(ch[root][1], root, 0);
    build(Key_value, 1, n, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
}


int get_kth(int r, int k) {
    int d = size[ch[r][0]] + 1;
    if (k == d)return r;
    else if (k > d)return get_kth(ch[r][1], k - d);
    else return get_kth(ch[r][0], k);
}

void get_interval(int l, int r) {
    splay(get_kth(root, l), 0);
    splay(get_kth(root, r + 2), root);
}

void Add(int l, int r, int inc) {
    get_interval(l, r);
    update(Key_value, inc);
    push_up(ch[root][1]);
    push_up(root);
}

void query(int l, int r) {
    get_interval(l, r);
    printf("%lld\n", sum[Key_value]);
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &num[i]);
        }
        init(n);
        char a[10];
        int x, y, z;
        while (m--) {
            scanf("%s", a);
            if (a[0] == 'Q') {
                scanf("%d%d", &x, &y);
                query(x, y);
            }
            else {
                scanf("%d%d%d", &x, &y, &z);
                Add(x, y, z);
            }
        }
    }
    return 0;
}




