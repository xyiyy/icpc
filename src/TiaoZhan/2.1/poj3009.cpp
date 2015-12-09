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
int m, n;
int sx, sy, gx, gy;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
int a[110][110];

bool in(int x, int y, int i) {
    x += dir[i][0];
    y += dir[i][1];
    if (x < 0 || x >= m || y < 0 || y >= n)return 0;
    return 1;
}

int minn;

void dfs(int x, int y, int i, int step) {
    if (step > 10)return;
    int dx = x + dir[i][0];
    int dy = y + dir[i][1];
    while (!a[dx][dy] && in(x, y, i)) {
        if (dx == gx && dy == gy) {
            minn = min(step, minn);
            return;
        }
        x = dx, y = dy;
        dx = x + dir[i][0];
        dy = y + dir[i][1];
    }
    if (in(x, y, i) && a[dx][dy])
        a[dx][dy] = 0;
    else return;
    for (int i = 0; i < 4; i++) {
        if (in(x, y, i) && !a[x + dir[i][0]][y + dir[i][1]])
            dfs(x, y, i, step + 1);
    }
    a[dx][dy] = 1;
}


int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m && (m || n)) {
        minn = 11;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (a[i][j] == 2)sx = i, sy = j, a[i][j] = 0;
                if (a[i][j] == 3)gx = i, gy = j, a[i][j] = 0;
            }
        }
        int step;
        for (int i = 0; i < 4; i++) {
            if (in(sx, sy, i) && !a[sx + dir[i][0]][sy + dir[i][1]]) {
                step = 1;
                dfs(sx, sy, i, step);
            }
        }
        if (minn <= 10)
            cout << minn << endl;
        else cout << -1 << endl;
    }

    return 0;
}


