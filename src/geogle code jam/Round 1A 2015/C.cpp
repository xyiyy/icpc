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

struct Point {
    ll x, y;

    Point(ll x = 0, ll y = 0) : x(x), y(y) { }
} a[3010];

int vis[3010];
int Id[3010];
int used[3010];
bool check[3010];
Point con[3010], tmp[3010], fuc[3010];

Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }

Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

ll Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }

ll Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int ConvexHull(Point *p, int n, Point *ch) {
    sort(Id, Id + n, cmp);
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[Id[i]] - ch[m - 2]) <= 0)m--;
        used[m] = Id[i];
        ch[m++] = p[Id[i]];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[Id[i]] - ch[m - 2]) <= 0)m--;
        used[m] = Id[i];
        ch[m++] = p[Id[i]];
    }
    if (n > 1)m--;
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("C-large.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int t;
    cin >> t;
    int cas = 1;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            Id[i] = i;
        }
        int caocao = ConvexHull(a, n, con);
        CLR(check, 0);
        for (int i = 0; i < caocao; i++) {
            check[used[i]] = 1;
        }
        cout << "Case #" << cas++ << ":" << endl;
        for (int i = 0; i < n; i++) {
            ans = n - 3;
            if (check[i])ans = 0;
            for (int j = 0; j < n; j++) {
                if (j == i)continue;
                if (ans == 0)break;
                Point ff, mp;
                if (j < i)ff = a[i] - a[j], mp = a[j];
                else ff = a[j] - a[i], mp = a[i];
                CLR(vis, 0);
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)continue;
                    if (Cross(a[k] - mp, ff) < 0)vis[k] = 1;
                }
                int tot = 0;
                for (int k = 0; k < n; k++) {
                    if (!vis[k])tot++;
                }
                ans = min(ans, n - tot);
                CLR(vis, 0);
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)continue;
                    if (Cross(a[k] - mp, ff) > 0)vis[k] = 1;
                }
                tot = 0;
                for (int k = 0; k < n; k++) {
                    if (!vis[k])tot++;
                }
                ans = min(ans, n - tot);
                //for(int i=0;i<n;i++){
                //    if(!vis[k])tmp[tot++]=a[i];
                //}
                //ans=min(n-ConvexHull(tmp,tot,fuc)

            }
            if (ans < 0)ans = 0;
            cout << ans << endl;
        }


    }
    return 0;
}



