#include "../../xyiyy/lib.hpp"

int dp[40010];
vector <PII> G[40010];

void dfs(int u, int fa) {
    int sz = G[u].size();
    rep(i, sz)
    {
        int v = G[u][i].first;
        if (v == fa)continue;
        int w = G[u][i].second;
        dp[v] = dp[u] ^ w;
        dfs(v, u);
    }
}

//should use scanf and printf
class shuoj1948 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t, cas = 1;
        in >> t;
        while (t--) {
            int n, m;
            in >> n >> m;
            rep2(i, 1, n)
            G[i].clear();
            int u, v, w;
            rep(i, n - 1)
            {
                in >> u >> v >> w;
                G[u].pb(mp(v, w));
                G[v].pb(mp(u, w));
            }
            dp[1] = 0;
            dfs(1, 0);
            out << "Case " << cas++ << ":" << endl;
            rep(i, m)
            {
                in >> u >> v;
                out << (dp[u] ^ dp[v]) << endl;
            }
        }
    }
};