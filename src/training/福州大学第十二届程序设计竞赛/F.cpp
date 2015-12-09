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
vector<PII> G[100010];
int maxx = 0;
int sum = 0;
int d;

void dfs(int x) {
    maxx = max(maxx, d);
    for (int i = 0; i < G[x].size(); i++) {
        int v = G[x][i].first;
        int z = G[x][i].second;
        d += z;
        sum += z;
        dfs(v);
        d -= z;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        maxx = 0;
        sum = 0;
        for (int i = 0; i < n; i++)G[i].clear();
        int u, v, z;
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v >> z;
            u--;
            v--;
            G[u].PB(MP(v, z));
        }
        d = 0;
        dfs(0);
        cout << sum - maxx << endl;
    }
    return 0;
}


