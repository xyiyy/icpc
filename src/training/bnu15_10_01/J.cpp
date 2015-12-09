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
#define mp(X, Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X, N) for(int X=0;X<N;X++)
#define rep2(X, L, R) for(int X=L;X<=R;X++)
#define dep(X, R, L) for(int X=R;X>=L;X--)
#define clr(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
#define mmp(X, Y, Z) mp(mp(X,Y),Z)
typedef pair<PII, int> PIII;
typedef vector<PII> VII;
typedef vector<int> VI;
PIII p[1010];
PIII q[1010];
int num[1010][4];

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while (scanf("%d", &n) != EOF) {
        int x, y;
        rep(i, n) {
            scanf("%d%d", &x, &y);
            p[i] = mmp(x, y, i);
            q[i] = mmp(y, x, i);
            rep(j, 4)num[i][j] = 0;
        }
        sort(p, p + n);
        sort(q, q + n);
        int now = 0;
        bool ok = true;
        x = 0, y = 0;
        int ans = 0;
        int f = -1;
        while (1) {
            PIII tmp;
            if (now & 1) {
                f = lower_bound(p, p + n, mmp(x, y, -1)) - p;
            } else {
                f = lower_bound(q, q + n, mmp(y, x, -1)) - q;
            }
            if (now == 1)f--;
            else if (now == 2)f--;
            if (f < 0 || f >= n)break;
            if (now & 1) {
                tmp = p[f];
            } else tmp = q[f];
            int lx, ly;
            if (now & 1) {
                lx = tmp.first.first;
                ly = tmp.first.second;
                if (lx != x)break;
            } else {
                lx = tmp.first.second;
                ly = tmp.first.first;
                if (ly != y)break;
            }
            if (now == 0)lx--;
            else if (now == 1)ly++;
            else if (now == 2)lx++;
            else ly--;
            f = tmp.second;
            if ((lx == x) || (ly == y)) {
                x = lx;
                y = ly;
            } else break;
            if (num[f][now]) {
                ok = false;
                break;
            }
            num[f][now]++;
            now++;
            if (now == 4)now -= 4;
            ans++;
        }
        if (!ok) ans = -1;
        cout << ans << endl;


    }
    return 0;
}

