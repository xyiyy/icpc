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
int n, m;
int num = 0;

bool in(int x, int y) {

}

void dfs(int x, int y) {
    vis[x][y] = num;
    for (int i = 0; i < 4; i++) {
        int tx = x + dirx[i];
        int ty = y + diry[i];
        if (in(tx, ty) && !vis[tx][ty] && a[tx][ty] == '#')dfs(tx, ty);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int cas = 1;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)cin >> a[i][j];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '#' && !vis[i][j]) {
                    num++;
                    dfs(i, j);
                }
            }
        }
        cout << "Case " << cas++ << ": ";
        if (num > 2) {
            cout << -1 << endl;
            continue;
        } else if (num == 2) {

        } else {

        }
    }
    return 0;
}
