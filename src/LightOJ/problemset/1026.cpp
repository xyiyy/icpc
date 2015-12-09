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
const int MAXN = 10010;
vector<int> G[MAXN];
int dclock, cut[MAXN], low[MAXN], dfn[MAXN];
priority_queue<PII, vector<PII>, greater<PII> > q;

void dfs(int u, int fa) {
    int son = 0;
    dfn[u] = low[u] = dclock++;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (dfn[v] < 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])q.push(MP(min(u, v), max(u, v)));
        } else if (dfn[u] > dfn[v] && v != fa)low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)G[i].clear();
        for (int i = 0; i < n; i++) {
            int u, v, num;
            char c;
            cin >> u >> c >> num >> c;
            for (int j = 0; j < num; j++) {
                cin >> v;
                G[u].PB(v);
            }
        }
        CLR(dfn, -1);
        CLR(low, 0);
        dclock = 0;
        while (!q.empty())q.pop();
        for (int i = 0; i < n; i++) {
            if (dfn[i] < 0)dfs(i, -1);
        }
        cout << "Case " << cas++ << ":" << endl;
        cout << q.size() << " critical links" << endl;
        while (!q.empty()) {
            PII p = q.top();
            q.pop();
            cout << p.first << " - " << p.second << endl;
        }
    }
    return 0;
}
