#include "../xyiyy/lib.hpp"

const int MAXN = 400010;
int key[MAXN], ch[MAXN][2], rev[MAXN], pre[MAXN], minn[MAXN];
int ntr[MAXN];
int pa[MAXN];

void push_down(int r) {
    if (!r)return;
    if (rev[r]) {
        rev[ch[r][0]] ^= 1;
        rev[ch[r][1]] ^= 1;
        swap(ch[r][0], ch[r][1]);
        rev[r] ^= 1;
    }
}

void push_up(int r) {
    minn[r] = key[r];
    minn[r] = min(minn[r], minn[ch[r][0]]);
    minn[r] = min(minn[r], minn[ch[r][1]]);
}

void rotate(int x, int d) {
    const int y = pre[x];
    ch[y][!d] = ch[x][d];
    if (ch[x][d])pre[ch[x][d]] = y;
    pre[x] = pre[y];
    if (ch[pre[y]][0] == y)ch[pre[x]][0] = x;
    else if (ch[pre[y]][1] == y) ch[pre[x]][1] = x;
    pre[y] = x;
    ch[x][d] = y;
    push_up(y);
}

bool _splay_parent(int x, int &y) {
    return (y = pre[x]) != 0 && (ch[y][0] == x || ch[y][1] == x);
}

void splay(int x, int goal) {
    push_down(x);
    for (int y, z; _splay_parent(x, y);) {
        if (_splay_parent(y, z)) {
            push_down(z);
            push_down(y);
            push_down(x);
            int d = y == ch[z][0];
            if (x == ch[y][d])rotate(x, d ^ 1), rotate(x, d);
            else rotate(y, d), rotate(x, d);
        } else {
            push_down(y), push_down(x);
            rotate(x, x == ch[y][0]);
            break;
        }
    }
    push_up(x);
}

int access(int u) {
    int v = 0;
    for (; u; u = pre[u]) {
        splay(u, 0);
        ch[u][1] = v;
        push_up(v = u);
    }
    return v;
}

void makeroot(int x) {
    rev[access(x)] ^= 1;
    splay(x, 0);
}

int find(int x) {
    if (pa[x] != x)pa[x] = find(pa[x]);
    return pa[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    pa[x] = y;
}

void link(int x, int y) {
    makeroot(x);
    pre[x] = y;
    unite(x, y);
}

void cut(int x, int y) {
    makeroot(x);
    access(y);
    splay(y, 0);
    pre[ch[y][0]] = 0;
    ch[y][0] = 0;
    push_up(y);
}

void Init(int n) {
    rep(i, n) {
        pre[i] = ch[i][0] = ch[i][1] = 0;
        pa[i] = i;
    }
    minn[0] = INF;
}

int query(int x, int y) {
    makeroot(x);
    access(y);
    splay(y, 0);
    return minn[y];
}

#define w(i) T[i].w
#define ls(i) T[i].ls
#define rs(i) T[i].rs
int root[MAXN];

struct node {
    int ls, rs, w;

    node() { ls = rs = w = 0; }
} T[MAXN * 20];

int tot = 0;

void Insert(int &i, int l, int r, int x) {
    T[++tot] = T[i];
    i = tot;
    w(i)++;
    if (l == r)return;
    int mid = (l + r) >> 1;
    if (x <= mid)Insert(ls(i), l, mid, x);
    else Insert(rs(i), mid + 1, r, x);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

PII p[MAXN];

class Chef_and_Graph_Queries {
public:
    void solve() {
        int t;
        scanf("%d", &t);//in >> t;
        while (t--) {
            int n, m, q;
            scanf("%d%d%d", &n, &m, &q);//in >> n >> m >> q;
            tot = 0;
            int u, v;
            Init(n + m + 10);
            //rep(i,n+1)pa[i] = i;
            rep(i, m + 1)ntr[i] = 0;
            rep(i, n + 1)key[i] = INF;
            rep(i, m) {
                scanf("%d%d", &u, &v);//in >> u >> v;
                if (u == v) {
                    ntr[i + 1] = i + 1;
                    continue;
                }
                p[i + 1] = mp(u, v);
                if (same(u, v)) {
                    int x = query(u, v);
                    int y = p[x].first;
                    int z = p[x].second;
                    cut(x + n, y);
                    cut(x + n, z);
                    ntr[i + 1] = x;
                }
                key[n + 1 + i] = i + 1;
                link(n + 1 + i, u);
                link(n + 1 + i, v);
            }
            for (int i = 1; i <= m; i++) {
                root[i] = root[i - 1];
                Insert(root[i], 0, m, ntr[i]);
            }
            while (q--) {
                scanf("%d%d", &u, &v);//in >> u >> v;
                int i = root[u - 1], j = root[v];
                int ans = 0;
                int l = 0, r = m;
                while (j) {
                    int mid = (l + r) >> 1;
                    if (u > mid) {
                        ans += w(ls(j)) - w(ls(i));
                        i = rs(i);
                        j = rs(j);
                        l = mid + 1;
                    } else {
                        i = ls(i);
                        j = ls(j);
                        r = mid;
                    }
                }
                ans = n - ans;
                printf("%d\n", ans);//out << ans << endl;
            }
        }
    }
};
