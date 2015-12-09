//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;


const int MAXN = 200010;
int pre[MAXN], ch[MAXN][2], rev[MAXN];
int key[MAXN];
bool sam[MAXN];
int size[MAXN];
int lx[MAXN],rx[MAXN],mx[MAXN],sum[MAXN];

void update_same(int r,int k){
    if(!r)return;
    key[r] = k;
    sum[r] = k * size[r];
    sam[r] = 1;
    if(k>0)lx[r] = rx[r] = mx[r] = size[r] * k;
    else lx[r] = rx[r] = mx[r] = k;
}

void update_rev(int r){
    if(!r)return;
    swap(lx[r],rx[r]);
    //swap(ch[r][0],ch[r][1]);
    rev[r]^=1;
}

void push_down(int r) {
    if(!r)return;
    if(sam[r]){
        sam[r] = 0;
        update_same(ch[r][0],key[r]);
        update_same(ch[r][1],key[r]);
    }
    if (rev[r]) {
        //rev[ch[r][0]] ^= 1;
        //rev[ch[r][1]] ^= 1;
        //swap(ch[r][0], ch[r][1]);
        update_rev(ch[r][0]);
        update_rev(ch[r][1]);
        swap(ch[r][0],ch[r][1]);
        rev[r] ^= 1;
    }
}

void push_up(int r) {
    if(!r)return;
    sum[r] = sum[ch[r][0]] + sum[ch[r][1]] + key[r];
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
    int lson = ch[r][0],rson = ch[r][1];
    lx[r] = max(lx[lson],sum[lson]+key[r]+max(lx[rson],0));
    rx[r] = max(rx[rson],sum[rson]+key[r]+max(rx[lson],0));
    mx[r] = max(max(mx[lson],mx[rson]),max(lx[rson],0)+key[r]+max(rx[lson],0));
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

bool _splay_parent(int x,int &y){
    return (y = pre[x])!=0 && (ch[y][0] == x || ch[y][1] == x);
}

void splay(int x,int goal) {
    push_down(x);
    for (int y,z;_splay_parent(x,y);) {
        if(_splay_parent(y,z)){
            push_down(z);push_down(y);push_down(x);
            int d = y == ch[z][0];
            if(x == ch[y][d])rotate(x,d^1),rotate(x,d);
            else rotate(y,d),rotate(x,d);
        }else {
            push_down(y),push_down(x);
            rotate(x, x == ch[y][0]);break;
        }
    }
    push_up(x);
}

int access(int u) {
    int v = 0;
    for (; u; u = pre[u]) {
        splay(u,0);
        ch[u][1] = v;
        push_up(v = u);
    }
    return v;
}

void makeroot(int x) {
    rev[access(x)] ^= 1;
    splay(x,0);
}

void link(int x, int y) {
    makeroot(x);
    pre[x] = y;
}

void cut(int x, int y) {
    makeroot(x);
    access(y);
    splay(y,0);
    pre[ch[y][0]] = 0;
    ch[y][0] = 0;
    push_up(y);
}

void Init(int n) {
    for (int i = 0; i < n; i++) {
        pre[i] = ch[i][0] = ch[i][1] = 0;
        mx[i] = sum[i] = key[i];
        lx[i] = rx[i] = -INF;
        size[i] = 0;
        sam[i] = 0;
        //and other thing
    }
    lx[0] = rx[0] = mx[0] = -INF;
}
void debug(int x){

}
int query(int x, int y) {
    makeroot(x);
    access(y);
    splay(y,0);
    return mx[y];
    //then return what you want
}
void update(int x,int y,int k){
    makeroot(x);
    access(y);
    splay(y,0);
    update_same(y,k);
}
vector<int>G[MAXN];
bool vis[MAXN];
queue<int> que;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF){
        rep(i,n)scanf("%d",&key[i+1]);
        Init(n+1);
        int u,v;
        rep(i,n+1)G[i].clear();
        rep(i,n+1)vis[i] = 0;
        rep(i,n-1){
            scanf("%d%d",&u,&v);
            G[u].pb(v);
            G[v].pb(u);
            //link(u,v);
        }
        while(!que.empty())que.pop();
        que.push(1);
        vis[1] = 1;
        while(!que.empty()){
            int x = que.front();
            que.pop();
            rep(i,G[x].size()){
                int y = G[x][i];
                if(vis[y])continue;
                que.push(y);
                vis[y] = 1;
                pre[y] = x;
                //link(x,y);
            }
        }
        int t,a,b,c;
        rep(i,q){
            scanf("%d%d%d%d",&t,&a,&b,&c);
            if(t==1){
                update(a,b,c);
            }else{
                printf("%d\n",query(a,b));
                /*if(b==17){
                    printf(" %d\n",ch[3][0]);
                }*/
            }
        }
    }


    return 0;
}
