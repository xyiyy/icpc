
//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
const int MAXN = 100010;
int pre[MAXN], ch[MAXN][2], rev[MAXN];
int key[MAXN];
int inc[MAXN];
void push_down(int r) {
    if (!r)return;
    if (rev[r]) {
        rev[ch[r][0]] ^= 1;
        rev[ch[r][1]] ^= 1;
        swap(ch[r][0], ch[r][1]);
        rev[r] ^= 1;
    }
   // cout << r << endl;
    if(inc[r]){
        if(ch[r][0])key[ch[r][0]]+=inc[r],inc[ch[r][0]]+=inc[r];
        if(ch[r][1])key[ch[r][1]]+=inc[r],inc[ch[r][1]]+=inc[r];
        inc[r]=0;
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
        key[i] = 0;
        //and other thing
    }
}

void debug(int x) {

}

void Modify(int x,int y){
    makeroot(x);
    access(y),splay(y,0);
    key[y]++;
    inc[y]++;
}

int query(int x, int y) {
    makeroot(x);
    access(y);
    splay(y, 0);
    //return mx[y];
    //then return what you want
}
template<class T>
inline bool Scan(T &n) {
    T x = 0, f = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-' && c != EOF)c = getchar();
    if (c == EOF)return false;
    if (c == '-')c = getchar(), f = -1;
    while (c >= '0' && c <= '9')x *= 10, x += (c - '0'), c = getchar();
    n = x * f;
    return true;
}

template<class T>
inline void Out(T n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0, data[20];
    while (n) {
        data[len++] = n % 10;
        n /= 10;
    }
    if (!len)data[len++] = 0;
    while (len--)putchar(data[len] + 48);
}
int main()///TLE
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL

    int t,cas = 1;
    Scan(t);
    //scanf("%d",&t);
    while(t--){
        int n,m;
        Scan(n);
        Scan(m);
        //scanf("%d%d",&n,&m);
        int u,v;
        Init(2 * n+10);
        rep(i,n-1){
            Scan(u);
            Scan(v);
            //scanf("%d%d",&u,&v);
            link(u,n+i+1);
            link(n+i+1,v);
        }
        rep2(i,n,m){
            Scan(u);
            Scan(v);
            //scanf("%d%d",&u,&v);8989-=-
            Modify(u,v);
        }
        int ans = INF;
        rep(i,n-1){
            query(n+i+1,n+i+1);
            ans = min(ans, key[n+i+1]);
        }
        ans++;
        cout << "Case #" << cas++ << ": " << ans << endl;

    }

    return 0;
}
