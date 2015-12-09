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
#define MP(X, Y, Z) make_pair(X,make_pair(Y,Z))
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, pair<int, int> > PII;
typedef vector<PII> VII;
typedef vector<int> VI;
char a[110][110];
int dis[30][30][11];
int vis[31][31][11];
int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, -1, 1, 0};
int n, m;

bool in(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)return 0;
    return 1;

}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int k;
        int sx, sy, gx, gy;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int l = 0; l <= k; l++) {
                    dis[i][j][l] = INF;
                    vis[i][j][l] = 0;
                }
            }
        }
        queue<PII> q;
        q.push(MP(sx, sy, 0));
        int ans = INF;
        dis[sx][sy][0] = 0;
        vis[sx][sy][0] = 1;
        while (!q.empty()) {
            PII p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second.first;
            int z = p.second.second;
            if (a[x][y] == 'T') {
                ans = min(ans, dis[x][y][z]);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int tx = x + dirx[i];
                int ty = y + diry[i];
                if (!in(tx, ty))continue;
                if (a[tx][ty] != 'x' && dis[tx][ty][z] > dis[x][y][z] + 1) {
                    dis[tx][ty][z] = dis[x][y][z] + 1;
                    q.push(MP(tx, ty, z));
                } else if (a[tx][ty] == 'x' && a[x][y] != 'x' && dis[tx][ty][z + 1] > dis[x][y][z] + 1) {
                    if (z == k)continue;
                    dis[tx][ty][z + 1] = dis[x][y][z] + 1;
                    q.push(MP(tx, ty, z + 1));
                }

            }
        }
        if (ans == INF)ans = -1;
        cout << ans << endl;;


    }
    return 0;
}
