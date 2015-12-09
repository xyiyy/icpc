#include "../../xyiyy/lib.hpp"

const int MAXN = 100010;
int pre[MAXN << 1], ch[MAXN << 1][2], rev[MAXN << 1];
int key[MAXN << 1];
int lx[MAXN << 1], rx[MAXN << 1];
int mx[MAXN << 1];

void push_down(int r) {
    if (!r)return;
    if (rev[r]) {
        rev[ch[r][0]] ^= 1;
        rev[ch[r][1]] ^= 1;
        swap(ch[r][0], ch[r][1]);
        rev[r] ^= 1;
    }
}

void push_up(int x) {
    int l = ch[x][0], r = ch[x][1];
    mx[x] = x;
    if (key[mx[l]] < key[mx[x]])mx[x] = mx[l];
    if (key[mx[r]] < key[mx[x]])mx[x] = mx[r];
}

void rotate(int x, int d) {
    const int y = pre[x];
    ch[y][!d] = ch[x][d];
    if (ch[x][d])pre[ch[x][d]] = y;
    pre[x] = pre[y];
    if (ch[pre[y]][0] == y)ch[pre[x]][0] = x;
    else if (ch[pre[y]][1] == y)ch[pre[x]][1] = x;
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
        //cout<<x<<" "<<y<<endl;
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

void link(int x, int y) {
    makeroot(x);
    pre[x] = y;
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
    for (int i = 0; i < n; i++) {
        pre[i] = ch[i][0] = ch[i][1] = 0;
        key[i] = INF;
        mx[i] = 0;
    }
}

void debug(int x) {

}

int query(int x, int y) {
    makeroot(x);
    access(y);
    splay(y, 0);
    return mx[y];
}


vector <int> vec[MAXN];
int ans[MAXN];

class hdu5398 {
public:
    void solve(std::istream &in, std::ostream &out) {
        rep2(i, 2, MAXN - 1)
        {
            vec[i].pb(1);
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    vec[i].pb(j);
                    if (i / j != j)vec[i].pb(i / j);
                }
            }
            sort(vec[i].begin(), vec[i].end());
        }
        Init(MAXN << 1);
        ans[1] = 0;
        rep2(i, 2, MAXN - 5)
        {
            int sz = vec[i].size();
            int y = vec[i][sz - 1];
            ans[i] = ans[i - 1];
            link(i, MAXN + i);
            rx[MAXN + i] = i;
            link(y, MAXN + i);
            lx[MAXN + i] = y;
            key[MAXN + i] = y;
            ans[i] += y;
            dep(j, sz - 2, 0)
            {
                y = vec[i][j];
                int x = query(y, i);
                cut(x, lx[x]);
                cut(x, rx[x]);
                link(y, x);
                link(i, x);
                ans[i] -= key[x];
                key[x] = y;
                lx[x] = y;
                rx[x] = i;
                ans[i] += y;
            }
        }
        int n;
        while (in >> n) {
            out << ans[n] << endl;
        }

    }
};
