//
// Created by xyfra_000 on 2015/8/19.
//

#ifndef ICPC_LCT_HPP
#define ICPC_LCT_HPP

const int MAXN = 100010;
int pre[MAXN], ch[MAXN][2], rev[MAXN];
int key[MAXN];

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
    //update the information
    /*int l = ch[x][0],r = ch[x][1];
    mx[x] = x;
    if(key[mx[l]]<key[mx[x]])mx[x] = mx[l];
    if(key[mx[r]]<key[mx[x]])mx[x] = mx[r];*/
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
        //and other thing
    }
}

void debug(int x) {

}

int query(int x, int y) {
    makeroot(x);
    access(y);
    splay(y, 0);
    //return mx[y];
    //then return what you want
}


#endif //ICPC_LCT_HPP
