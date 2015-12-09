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
int a[5][5];
int dir[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};
set<int> s;

bool in(int x, int y) {
    if (x < 0 || x >= 5 || y < 0 || y >= 5)return 0;
    return 1;
}

void dfs(int x, int y, int t, int num) {
    if (t == 100000) {
        //num+=a[x][y]*t;
        s.insert(num);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (in(dx, dy)) {
            dfs(dx, dy, t * 10, num + t * 10 * a[dx][dy]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, 1, a[i][j]);
        }
    }
    cout << s.size() << endl;
    return 0;
}


