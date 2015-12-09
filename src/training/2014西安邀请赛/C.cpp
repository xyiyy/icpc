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
typedef pair<ll, ll> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define MAXN 1010
vector<PII> Map[MAXN];

void init() { REP(i, MAXN) Map[i].clear(); }

ll dis[MAXN];

void dijkstra(int s) {
    REP(i, MAXN) { dis[i] = i == s ? 0 : INF; }
    int vis[MAXN] = {0};
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push(MP(0, s));
    while (!q.empty()) {
        PII p = q.top();
        q.pop();
        int x = p.second;
        if (vis[x])continue;
        vis[x] = 1;
        for (vector<PII>::iterator it = Map[x].begin(); it != Map[x].end(); it++) {
            int y = it->first;
            ll d = it->second;
            if (!vis[y] && dis[y] > dis[x] + d) {
                dis[y] = dis[x] + d;
                q.push(MP(dis[y], y));
            }
        }
    }
}

ll x[1000010], y[1000010];
ll z[1000010];
int us[1000010];

int main() {
    ios::sync_with_stdio(false);
    int n, m, x0, x1, y0, y1;
    while (cin >> n >> m >> x[0] >> x[1] >> y[0] >> y[1]) {
        init();
        for (int i = 0; i < 2; i++) {
            z[i] = (x[i] * 90123 + y[i]) % 8475871 + 1;
        }
        for (int i = 2; i < n * n; i++) {
            x[i] = (12345 + x[i - 1] * 23456 + x[i - 2] * 34567 + x[i - 1] * x[i - 2] * 45678) % 5837501;
            y[i] = (56789 + y[i - 1] * 67890 + y[i - 2] * 78901 + y[i - 2] * y[i - 1] * 89012) % 9860381;
            z[i] = (x[i] * 90123 + y[i]) % 8475871 + 1;
        }
        for (int i = 0; i < n * n; i++) {
            int u = i / n;
            int v = i % n;
            if (u == v)continue;
            Map[u].PB(MP(v, z[i]));
        }
        dijkstra(0);
        for (int i = 1; i < n; i++) {
            us[dis[i] % m]++;
        }
        int ans = INF;
        int ax = 0;
        for (int i = 0; i < m; i++) {
            if (us[i]) {
                ans = i;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            us[i] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}


