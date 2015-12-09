#pragma comment(linker, "/STACK:102400000,102400000")

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
int v[500][500];
int dir[5][2] = {0, 1, 1, 0, 0, -1, -1, 0, 0, 1};

int main() {
    int n, m, g, t, cs = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &g);
        CLR(v, 0);
        queue<PII> q;
        int cnt = 0;
        for (int i = 0; i < g; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--;
            y--;
            if (!v[x][y]) cnt++;
            v[x][y] = 1;
        }
        int dd = 0;
        while (!dd) {
            dd = 1;
            for (int tx = 0; tx < n; tx++) {
                for (int ty = 0; ty < m; ty++) {
                    if (tx >= 0 && ty >= 0 && tx < n && ty < m && !v[tx][ty]) {
                        int l = 0, c = 0;
                        for (int j = 0; j < 5; j++) {
                            int xx = tx + dir[j][0];
                            int yy = ty + dir[j][1];
                            if (xx >= 0 && yy >= 0 && xx < n && yy < m && v[xx][yy]) {
                                if (l) c = 2;
                                l = 1;
                            } else {
                                l = 0;
                            }
                        }
                        if (c >= 2) {
                            v[tx][ty] = 1;
                            dd = 0;
                            cnt++;
                        }
                    }
                }
            }
        }
        printf("Case #%d:\n%d\n", cs++, cnt);
    }
    return 0;
}


