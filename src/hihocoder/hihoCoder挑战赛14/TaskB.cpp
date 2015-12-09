#include "../../xyiyy/lib.hpp"

vector <int> G[100010];
int dp[100010][2];
int pre[100010][2];
int dep[100010];
int ans;

class TaskB {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        while (in >> n) {
            rep(i, n)
            G[i].clear();
            int u, v;
            rep(i, n - 1)
            {
                in >> u >> v;
                u--;
                v--;
                G[u].pb(v);
            }
            dep[0] = 0;
            dfs(0, -1);
            ans = 0;
            dfs2(0, -1);
            out << ans << endl;
        }
    }

    void dfs(int u, int fa) {
        dp[u][0] = dp[u][1] = 0;
        pre[u][0] = pre[u][1] = -1;
        int sz = G[u].size();
        rep(i, sz)
        {
            int v = G[u][i];
            dep[v] = dep[u] + 1;
            dfs(v, u);
            if (dp[v][0] + 1 > dp[u][1]) {
                dp[u][1] = dp[v][0] + 1;
                pre[u][1] = v;
                if (dp[u][1] > dp[u][0]) {
                    swap(dp[u][1], dp[u][0]);
                    swap(pre[u][1], pre[u][0]);
                }
            }
        }
    }

    void dfs2(int u, int fa) {
        int sz = G[u].size();
        rep(i, sz)
        {
            int v = G[u][i];
            ans = max(ans, dp[u][1] + dep[u] + dp[u][0]);
            dfs2(v, u);
        }
    }
};
