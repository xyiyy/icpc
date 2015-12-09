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
typedef unsigned long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
struct node {
    int u, v, len;
} edge[100010];
ll dp[100010];
ll n;
ll sum[100010];
vector<PII> G[100010];

void dfs(int root, int fa) {
    sum[root] = 1;
    for (int i = 0; i < G[root].size(); i++) {
        int son = G[root][i].first;
        if (son == fa)continue;
        dfs(son, root);
        sum[root] += sum[son];
        dp[G[root][i].second] =
                sum[son] * (n - sum[son]) * (n - sum[son] - 1LL) + sum[son] * (sum[son] - 1LL) * (n - sum[son]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    int u, v, len;
    for (int i = 1; i < n; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].len;
        u = edge[i].u;
        v = edge[i].v;
        G[u].push_back(MP(v, i));
        G[v].push_back(MP(u, i));
    }
    dfs(1, -1);
    ll t = 1.0 * (n) * (n - 1) * (n - 2) / 6;
    double tmp = 0;
    for (int i = 1; i < n; i++) {
        tmp += (double) dp[i] * edge[i].len / t;
    }
    //tmp/=t;
    int q;
    cin >> q;
    while (q--) {
        cin >> u >> len;
        tmp -= (double) dp[u] * edge[u].len / t;
        edge[u].len = len;
        tmp += (double) dp[u] * edge[u].len / t;
        cout << fixed << setprecision(12) << (double) tmp << endl;
    }


    return 0;
}



