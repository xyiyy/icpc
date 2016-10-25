#include <bits/stdc++.h>
using namespace std;

const int INF = -1000000000;
const int MAXN = 100010;
int pre[MAXN], ch[MAXN][2], rev[MAXN];
int key[MAXN];
bool Same[MAXN];
int same_value[MAXN],mx[MAXN][2],mxc[MAXN][2],Inc[MAXN],sz[MAXN];

void update_same(int r,int d){
    key[r] = d;
    mx[r][0] = d, mxc[r][0] = sz[r];
    mx[r][1] = INF, mxc[r][1] = 0;
    Same[r] = 1;
    same_value[r] = d;
    Inc[r] = 0;
}
void update_add(int r,int d){
    key[r] += d;
    mx[r][0] += d;
    if(mx[r][1] != INF)mx[r][1] += d;
    Inc[r] += d;
}
void push_down(int r) {
    if (!r)return;
    if (rev[r]) {
        rev[ch[r][0]] ^= 1;
        rev[ch[r][1]] ^= 1;
        swap(ch[r][0], ch[r][1]);
        rev[r] ^= 1;
    }
    int lson = ch[r][0], rson = ch[r][1];
    if(Same[r]){
        if(lson)update_same(lson, same_value[r]);
        if(rson)update_same(rson, same_value[r]);
        Same[r] = 0;
    }
    if(Inc[r]){
        if(lson)update_add(lson, Inc[r]);
        if(rson)update_add(rson, Inc[r]);
        Inc[r] = 0;
    }
}
void update_mx(int son,int fa){
    if(!son)return;
    int val = mx[son][0], cnt = mxc[son][0];
    if(!cnt)return;
    if(val > mx[fa][0]){
        mx[fa][1] = mx[fa][0], mx[fa][0] = val;
        mxc[fa][1] = mxc[fa][0], mxc[fa][0] = cnt;
    }else if(val == mx[fa][0]){
        mxc[fa][0] += cnt;
    }else if(val > mx[fa][1]){
        mx[fa][1] = val, mxc[fa][1] = cnt;
    }else if(val == mx[fa][1]){
        mxc[fa][1] += cnt;
    }
    val = mx[son][1], cnt = mxc[son][1];
    if(!cnt)return;
    if(val > mx[fa][1]){
        mx[fa][1] = val, mxc[fa][1] = cnt;
    }else if(val == mx[fa][1]){
        mxc[fa][1] += cnt;
    }
}
void push_up(int x) {
    int lson = ch[x][0], rson = ch[x][1];
    mx[x][0] = key[x], mx[x][1] = INF;
    mxc[x][0] = 1, mxc[x][1] = 0;
    update_mx(lson,x);
    update_mx(rson,x);
    sz[x] = sz[lson] + sz[rson] + 1;
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
    //push_up(x);
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
    pre[x] = 0;
    ch[y][0] = 0;
    push_up(y);
}
void Init(int n) {
    for (int i = 0; i < n; i++) {
        pre[i] = ch[i][0] = ch[i][1] = 0;
        Inc[i] = Same[i] = rev[i] = 0;
        mx[i][0] = mx[i][1] = INF;
        mxc[i][0] = mxc[i][1] = 0;
        //and other thing
    }
    key[0] = 0;
    sz[0] = 0;

}

void debug(int x) {

}

void query(int x, int y) {
    makeroot(x);
    access(y);
    splay(y, 0);
    //return mx[y];
    //then return what you want
}
void make_same(int x,int y,int d){
    query(x,y);
    update_same(y,d);

}
void modify_add(int x,int y,int d){
    query(x, y);
    update_add(y, d);
}


vector<int>G[MAXN];
bool vis[MAXN];
void build(int u,int fa){
    pre[u] = fa;
    vis[u] = 1;
    for(int i = 0 ;i < G[u].size() ; i ++){
        int v = G[u][i];
        if(vis[v])continue;
        build(v,u);
    }
}



int main(){
    int t;
    int cas = 1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1 ; i <= n; i ++){
            scanf("%d",&key[i]);
        }
        int u, v;
        Init(n+10);
        for(int i = 0 ; i < n + 2; i ++){
            G[i].clear();
            vis[i] = 0;
        }
        for(int i = 1 ; i < n; i++){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= n ; i++){
            if(vis[i])continue;
            build(i,0);
        }
        int c;
        int x,y,a,b,d;
        printf("Case #%d:\n",cas++);
        for(int i = 0 ; i < m ; i ++){
            scanf("%d",&c);
            if(c == 1){
                scanf("%d%d%d%d",&x,&y,&a,&b);
                cut(x,y);
                link(a,b);
            }else if(c == 2){
                scanf("%d%d%d", &a, &b, &x);
                make_same(a,b,x);
            }else if(c == 3){
                scanf("%d%d%d", &a, &b, &d);
                modify_add(a,b,d);
            }else if(c == 4){
                scanf("%d%d", &a, &b);
                query(a,b);
                int ans = mx[b][1];
                if(ans == INF){
                    printf("ALL SAME\n");
                }else{
                    printf("%d %d\n",ans,mxc[b][1]);
                }
            }
        }
    }
    return 0;
}
