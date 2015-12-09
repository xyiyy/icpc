/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author xyiyy @ http://www.cnblogs.com/fraud/
 */
const int maxn;
int ch[maxn][2], key[maxn], pre[maxn], size[maxn], ss[maxn];
int root, tot, tot2;

void newnode(int &r, int fa, int k) {
    if (tot2)r = ss[--tot2];
    else r = ++tot;
    key[r] = k;
    ch[r][0] = ch[r][1] = 0;
    pre[r] = fa;
    size[r] = 1;
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
    push_up(x);
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

//区间型操作的Init
void init() {
    root = tot = tot2 = 0;
    key[root] = ch[root][0] = ch[root][1] = pre[root] = 0;
    newnode(root, 0, impossible);//此处impossible的取值须保证对后面无影响
    newnode(ch[root][1], root, impossible);
    push_up(ch[root][1]);
    push_up(root);
}

int get_kth(int r, int k) {
    push_down(r);
    int d = size[ch[r][0]] + 1;
    if (d == k)return r;
    else if (d < k)return get_kth(ch[r][1], k - d);
    else return get_kth(ch[r][0], k);
}

void get_interval(int l, int r) {
    splay(get_kth(root, l), 0);
    splay(get_kth(ch[root][1], r - l + 1), root);
}

void erase(int r) {
    if (!r)return;
    ss[tot2++] = r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}

void Treavel(int x) {
    if (x) {
        Treavel(ch[x][0]);
        printf("结点%2d:左儿子 %2d 右儿子 %2d 父节点 %2d size = %2d val = %2d\n", x, ch[x][0], ch[x][1], pre[x], size[x], key[x]);
        Treavel(ch[x][1]);
    }
}

void debug() {
    printf("root%d\n", root);
    Treavel(root);
}



