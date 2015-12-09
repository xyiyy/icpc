#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 100010
#define w(i) T[i].w
#define ls(i) T[i].ls
#define rs(i) T[i].rs

struct node {
    int ls, rs, w;

    node() { ls = rs = w = 0; }
} T[MAXN * 20];

int tot;
int a[MAXN], p[MAXN], b[MAXN];

void Insert(int &i, int l, int r, int x) {
    T[++tot] = T[i], i = tot;
    w(i)++;
    if (l == r)return;
    int mid = (l + r) >> 1;
    if (l <= mid)Insert(ls(i), l, mid, x);
    else Insert(rs(i), mid + 1, r, x);
}

void query(int lx, int rx, int ls, int rs, in t x) {

}

void update(int i, int x) {

}

void Quer(int l, int r) {
}

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    scanf(¡°%d¡±,&t);
    while (t--) {
        tot = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            p[i] = i;
        }
        sort(p + 1, p + n + 1, cmp);
        for (int i = 1; i <= n; i++)b[p[i]] = i;

    }
    return 0;
}

