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
int a[110][110];
int n, m;

bool in(int x, int y) {
    if (x + 1 < n && y + 1 < m && x >= 0 && y >= 0)return 1;
    return 0;
}

bool check(int x, int y) {
    if (a[x][y] || a[x + 1][y] || a[x][y + 1] || a[x + 1][y + 1])return 0;
    return 1;
}

int getdir(string str) {
    if (str == "east")return 2;
    if (str == "south")return 3;
    if (str == "west")return 1;
    else return 0;
}

int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, -1, 1, 0};
bool vis[51][51][4];
int dis[51][51][4];

int main() {
    ios::sync_with_stdio(false);
    string str;
    while (cin >> n >> m && (n || m)) {
        CLR(dis, INF);
        CLR(vis, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int sx, sy, sz, ex, ey;
        cin >> sx >> sy >> ex >> ey >> str;
        sx--;
        sy--;
        ex--;
        ey--;
        int dir = getdir(str);
        vis[sx][sy][dir] = 1;
        dis[sx][sy][dir] = 0;
        queue<PII> q;
        q.push(MP(sx, sy, dir));
        while (!q.empty()) {
            PII p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second.first;
            int z = p.second.second;
            //cout<<x<<" "<<y<<" "<<z<<endl;
            for (int i = 0; i < 4; i++) {
                if (i == z || i + z == 3)continue;
                else {
                    if (vis[x][y][i])continue;
                    dis[x][y][i] = dis[x][y][z] + 1;
                    vis[x][y][i] = 1;
                    q.push(MP(x, y, i));
                }
            }
            for (int i = 1; i < 4; i++) {
                int tx = x + dirx[z] * i;
                int ty = y + diry[z] * i;
                if (in(tx, ty) && check(tx, ty)) {
                    //cout<<tx<<" "<<ty<<" "<<endl;
                    if (vis[tx][ty][z])continue;
                    dis[tx][ty][z] = dis[x][y][z] + 1;
                    //dis[tx][ty][z] = min(dis[tx][ty][z],dis[x][y][z]+1);
                    vis[tx][ty][z] = 1;
                    q.push(MP(tx, ty, z));
                } else break;
            }
        }
        int ans = INF;
        for (int i = 0; i < 4; i++) { ans = min(dis[ex][ey][i], ans); }
        /* for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 int tmp = INF;
                 for(int k =0;k<4;k++)tmp = min(tmp,dis[i][j][k]);
                 cout<<tmp<<" ";
             }
             cout<<endl;
         }*/
        if (ans == INF)ans = -1;
        cout << ans << endl;
    }
    return 0;
}


