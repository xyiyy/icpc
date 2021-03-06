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


#define MAXN 1100000

int pa[MAXN]; // parent
int ra[MAXN]; // rank
int ans;

//���鼯 
void init(int n) {
    for (int i = 0; i < n; i++) {
        pa[i] = i;
        ra[i] = 0;
    }
    ans = n;
}

int find(int x) {
    if (pa[x] != x) pa[x] = find(pa[x]);
    return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return 0;
    ans--;
    if (ra[x] < ra[y]) {
        pa[x] = y;
    } else {
        pa[y] = x;
        if (ra[x] == ra[y]) ra[x]++;
    }
    return 1;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int id[100000];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        init(n);
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--;
            v--;
            unite(u, v);
        }
        cout << ans << endl;
    }
    return 0;
}
