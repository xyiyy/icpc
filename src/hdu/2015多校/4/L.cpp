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

int Scan() {
    int res = 0, ch;
    while (ch = getchar(), ch < '0' || ch > '9');
    res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    return res;
}

void Out(int a) {
    if (a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

int a[100010];
int vis[100010];
int pos[100010];
int fa[100010];
int dp[600010];
int ans[100010];
set<int> ms;
int n;
set<int>::IT it;

int find(int x) {
    if (fa[x] != x)fa[x] = find(fa[x]);
    return fa[x];
}

void push_up(int cur) {
    dp[cur] = max(dp[cur << 1], dp[cur << 1 | 1]);
}

void build(int l, int r, int cur) {
    if (l == r) {
        dp[cur] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur << 1);
    build(mid + 1, r, cur << 1 | 1);
    push_up(cur);
}

void update(int l, int r, int cur, int x, int inc) {
    if (l == r && l == x) {
        dp[cur] = inc;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)update(l, mid, cur << 1, x, inc);
    else update(mid + 1, r, cur << 1 | 1, x, inc);
    push_up(cur);
}

void update(int x, int num) {
    update(1, n, 1, x, num);
}

int query(int l, int r, int lx, int rx, int cur) {
    if (l >= lx && r <= rx)return dp[cur];
    if (lx > r || rx < l)return 0;
    int mid = (l + r) >> 1;
    return max(query(l, mid, lx, rx, cur << 1), query(mid + 1, r, lx, rx, cur << 1 | 1));
}

int query(int l, int r) {
    return query(1, n, l, r, 1);
}

int main() {
    int t;
    t = Scan();
    while (t--) {
        n = Scan();
        for (int i = 1; i <= n; i++) {
            a[i] = Scan();
            vis[i] = 0;
            pos[a[i]] = i;
            fa[i] = i;
        }
        for (int i = 0; i <= 3 * n; i++)dp[i] = 0;
        build(1, n, 1);
        ms.clear();
        ms.insert(0);
        ms.insert(-INF);
        for (int i = 1; i <= n; i++) {
            if (vis[i])continue;
            int l;
            int posi = pos[i];
            int maxx = find(i);
            int p = pos[maxx];
            if (posi + 1 <= n && !vis[a[posi + 1]]) {
                if (a[posi + 1] > maxx) {
                    p = posi + 1;
                    maxx = a[p];
                }
            }
            if (posi > 1) {
                it = ms.upper_bound(-posi);
                l = *it;
                l = -l;
                l++;
                int tmp = query(l, posi);
                //tmp = find(tmp);
                //cout<<l<<" "<<tmp<<endl;
                if (tmp > maxx) {
                    maxx = tmp;
                    p = pos[tmp];
                }
            }
            if (p == posi) {
                ans[i] = i;
                vis[i] = 1;
                ms.insert(-posi);
            } else if (p == posi + 1) {
                fa[maxx] = fa[i];
                //ans[posi] = maxx;
                update(p, 0);
            } else {
                ans[i] = a[p];
                vis[a[p]] = 1;
                for (int j = p + 1; j <= posi; j++) {
                    ans[a[j - 1]] = a[j];
                    vis[a[j]] = 1;
                }
                ms.insert(-posi);
            }
            /*	cout<<i<<" "<<p<<" "<<maxx<<endl;
                for(int i=1;i<=n;i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;*/
        }
        for (int i = 1; i <= n; i++) {
            if (i != 1)putchar(' ');
            Out(ans[i]);
        }
        puts("");
    }
    return 0;
}
				
				



