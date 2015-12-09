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

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int flag, sort[101], point[101], line[101], color[101];

    memset(point, 0, sizeof(point));
    memset(line, 0, sizeof(line));
    memset(sort, -1, sizeof(sort));
    memset(color, -1, sizeof(color));

    flag = 1;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        point[tmp] = 1;
        sort[i] = tmp;
    }

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            line[j] = 1;
        }
    }

    for (int i = 0; i <= 100; i++) {
        if (point[i] && !line[i]) {
            cout << "-1" << endl;
            return 0;
        }
        if (point[i]) {
            flag = !flag;
            color[i] = flag;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (sort[i] != -1) if (color[sort[i]] != -1)
            cout << color[sort[i]] << " ";
    }
    cout << endl;
    return 0;
}

