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
//#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
int n, m;
int num, minn;
int map[110][110];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int sx, sy;

void dfs(int x, int y) {
    if (num > 10)return;
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (map[tx][ty] == 3) {
            if (minn > num)minn = num;
        }
        if (map[tx][ty] == 1)continue;
        while (map[tx][ty] == 0 && tx > 0 && tx <= m && ty > 0 && ty <= n) {
            tx = tx + dx[i];
            ty = ty + dy[i];
            if (map[tx][ty] == 3) {
                if (num < minn)minn = num;
                break;
            }
            if (map[tx][ty] == 1) {
                num++;
                map[tx][ty] = 0;
                dfs(tx - dx[i], ty - dy[i]);
                num--;
                map[tx][ty] = 1;
                break;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m && (m || n)) {
        memset(map, 0, sizeof(map));
        num = 1;
        minn = 13;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
                if (map[i][j] == 2) {
                    sx = i;
                    sy = j;
                    map[i][j] = 0;
                }
            }
        }
        dfs(sx, sy);
        if (minn <= 10)cout << minn << endl;
        else cout << "-1" << endl;
    }


    return 0;
}

