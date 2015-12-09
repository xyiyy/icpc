//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X, Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X, N) for(int X=0;X<N;X++)
#define rep2(X, L, R) for(int X=L;X<=R;X++)
#define dep(X, R, L) for(int X=R;X>=L;X--)
#define clr(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[1010];
const int MAXN = 1010010;
struct node {
    int ch[2], sz;
} T[MAXN];
int root = 1;
int tot = 1;

void insert(int x) {
    int now = root;
    T[now].sz++;
    dep(i, 30, 0) {
        bool c = (x & (1 << i));
        if (!T[now].ch[c])T[now].ch[c] = ++tot;
        now = T[now].ch[c];
        T[now].sz++;
    }
}

void Del(int x) {
    int now = root;
    T[now].sz--;
    dep(i, 30, 0) {
        bool c = (x & (1 << i));
        now = T[now].ch[c];
        T[now].sz--;
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        rep(i, n) {
            scanf("%d", &a[i]);
            insert(a[i]);
        }
        int ans = 0;
        rep(i, n) {
            Del(a[i]);
            rep(j, i) {
                Del(a[j]);
                int x = a[i] + a[j];
                int now = root;
                dep(k, 30, 0) {
                    bool c = (x & (1 << k));
                    if (T[now].ch[!c] && T[T[now].ch[!c]].sz)now = T[now].ch[!c], x |= (1 << k);
                    else now = T[now].ch[c], x ^= (c << k);
                }
                ans = max(ans, x);
                insert(a[j]);
            }
            insert(a[i]);
        }
        cout << ans << endl;
        tot++;
        rep(i, tot)T[i].ch[0] = T[i].ch[1] = T[i].sz = 0;
        tot = 1;
    }
    return 0;
}

