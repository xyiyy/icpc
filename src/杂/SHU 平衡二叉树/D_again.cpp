#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define Key_value ch[ch[root][1]][0]
const int maxn = 500010;
int root, n, tot1, tot2;
int lx[maxn], rx[maxn], ch[maxn][2], sum[maxn], mx[maxn];
int pre[maxn], size[maxn], ss[maxn], key[maxn];
int same[maxn], rev[maxn], a[maxn];

void newnode(int &r, int father, int k) {
    if (tot2)r = ss[tot2--];
    else r = ++tot1;
    pre[r] = father;
    mx[r] = lx[r] = rx[r] = sum[r] = key[r] = k;
    size[r] = 1;
    ch[r][0] = ch[r][1] = rev[r] = same[r] = 0;
}

void update_same(int r, int k) {
    if (!r)return;
    key[r] = k;
    sum[r] = k * size[r];
    same[r] = 1;
    if (k > 0)lx[r] = rx[r] = mx[r] = size[r] * k;
    else lx[r] = rx[r] = mx[r] = k;
}

void update_rev(int r) {
    if (!r)return;
    swap(lx[r], rx[r]);
    swap(ch[r][0], ch[r][1]);
    rev[r] ^= 1;
}

void push_up(int r) {
    if (!r)return;
    sum[r] = sum[ch[r][0]] + sum[ch[r][1]] + key[r];
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
    int lson = ch[r][0], rson = ch[r][1];
    lx[r] = max(lx[lson], sum[lson] + key[r] + max(lx[rson], 0));
    rx[r] = max(rx[rson], sum[rson] + key[r] + max(rx[lson], 0));
    mx[r] = max(max(mx[lson], mx[rson]), max(lx[rson], 0) + key[r] + max(rx[lson], 0));
}

void push_down(int r) {
    if (same[r]) {
        update_same(ch[r][0], key[r]);
        update_same(ch[r][1], key[r]);
        same[r] = 0;
    }
    if (rev[r]) {
        update_rev(ch[r][0]);
        update_rev(ch[r][1]);
        rev[r] = 0;
    }
}

void build(int &x, int l, int r, int father) {
    if (l > r)return;
    int mid = (l + r) / 2;
    newnode(x, father, a[mid]);
    build(ch[x][0], l, mid - 1, x);
    build(ch[x][1], mid + 1, r, x);
    push_up(x);
}

void init() {
    root = tot1 = tot2 = 0;
    ch[root][0] = ch[root][1] = key[root] = size[root] = sum[root] = pre[root] = same[root] = rev[root] = 0;
    lx[root] = rx[root] = mx[root] = -INF;
    newnode(root, 0, -1);
    newnode(ch[root][1], root, -1);
    push_up(root);
    //cout<<root<<endl;
    build(Key_value, 1, n, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
}

void rotate(int x, int d) {
    int y = pre[x];
    push_down(y);
    push_down(x);
    ch[y][!d] = ch[x][d];
    pre[ch[x][d]] = y;
    if (pre[x])ch[pre[y]][ch[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    ch[x][d] = y;
    pre[y] = x;
    push_up(y);
}

void splay(int x, int goal) {
    push_down(x);
    while (pre[x] != goal) {
        if (pre[pre[x]] == goal) {
            //	push_down(pre[x]);
            rotate(x, ch[pre[x]][0] == x);
        }
        else {
            int y = pre[x];
            //	push_down(pre[y]);
            //	push_down(y);
            int d = (ch[pre[y]][0] == y);
            if (ch[y][d] == x) {
                rotate(x, !d);
                rotate(x, d);
            }
            else //一
            {
                rotate(y, d);
                rotate(x, d);
            }
        }
    }
    push_up(x);
    if (goal == 0)root = x;
}

void rotateto(int k, int goal)//把第k位转到goal下面
{
    int x = root;
    push_down(x);
    while (size[ch[x][0]] != k) {
        if (k < size[ch[x][0]]) {
            x = ch[x][0];
        }
        else {
            k -= (size[ch[x][0]] + 1);
            x = ch[x][1];
        }
        push_down(x);
    }
    splay(x, goal);
}

int get_kth(int x, int k) {
    push_down(x);
    int d = size[ch[x][0]] + 1;
    if (d == k)return x;
    else if (k < d)
        return get_kth(ch[x][0], k);
    else
        return get_kth(ch[x][1], k - d);
}

int get_min(int x) {
    push_down(x);
    while (ch[x][0]) {
        x = ch[x][0];
        push_down(x);//一定要下传标记 TAT查了好久
    }
    return x;
}

void erase(int x) {
    if (!x)return;
    ss[++tot2] = x;
    erase(ch[x][0]);
    erase(ch[x][1]);
}

void insert(int pos, int tot) {
    splay(get_kth(root, pos + 1), 0);
    splay(get_min(ch[root][1]), root);
    build(Key_value, 1, tot, ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
}

void Delete(int pos, int tot) {
    splay(get_kth(root, pos), 0);
    splay(get_kth(root, pos + tot + 1), root);
    erase(Key_value);
    pre[Key_value] = 0;
    Key_value = 0;
    push_up(ch[root][1]);
    push_up(root);
}

void make_same(int pos, int tot, int k) {
    splay(get_kth(root, pos), 0);
    splay(get_kth(root, pos + tot + 1), root);
    update_same(Key_value, k);
    push_up(ch[root][1]);
    push_up(root);
}

void Reverse(int pos, int tot) {
    splay(get_kth(root, pos), 0);
    splay(get_kth(root, pos + tot + 1), root);
    update_rev(Key_value);
//	push_up(ch[root][1]);
//	push_up(root);
}

int get_sum(int pos, int tot) {
    splay(get_kth(root, pos), 0);
    splay(get_kth(root, pos + tot + 1), root);
    return sum[Key_value];
}

int get_maxsum() {
    int pos = 1, tot = size[root] - 2;
    splay(get_kth(root, pos), 0);
    splay(get_kth(root, pos + tot + 1), root);
    return mx[Key_value];
}

void Treavel(int x) {
    if (x) {
        Treavel(ch[x][0]);
        printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d sum = %2d maxsum=%2d \n", x, ch[x][0], ch[x][1],
               pre[x], size[x], key[x], sum[x], mx[x]);
        Treavel(ch[x][1]);
    }
}

void debug() {
    printf("root%d\n", root);
    Treavel(root);
}

int main() {
    //ios::sync_with_stdio(false);
    int m, pos, tot, num;
    char str[110];
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        init();
        for (int i = 0; i < m; i++) {
            scanf("%s", str);
            if (str[0] == 'I') {
                scanf("%d%d", &pos, &tot);
                for (int i = 1; i <= tot; i++) {
                    scanf("%d", &a[i]);
                }
                insert(pos, tot);
            }
            else if (str[0] == 'D') {
                scanf("%d%d", &pos, &tot);
                Delete(pos, tot);
            }
            else if (str[2] == 'K') {
                scanf("%d%d%d", &pos, &tot, &num);
                make_same(pos, tot, num);
            }
            else if (str[0] == 'R') {
                scanf("%d%d", &pos, &tot);
                Reverse(pos, tot);
            }
            else if (str[0] == 'G') {
                scanf("%d%d", &pos, &tot);
                printf("%d\n", get_sum(pos, tot));
            }
            else if (str[2] == 'X') {
                printf("%d\n", get_maxsum());
            }
        }
    }
    return 0;
}
