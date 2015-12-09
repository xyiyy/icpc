#include "../../xyiyy/lib.hpp"

int dp[110][110];
ll C[210][110];
const ll MOD = 1000000007;
int a[110];
char b[110];
ll fac[110];

class hdu5396 {
public:
    void solve(std::istream &in, std::ostream &out) {
        rep(i, 110)
        {
            C[i][0] = 1;
            rep2(j, 1, i)
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= MOD;
            }
        }
        fac[0] = 1;
        rep2(i, 1, 110)
        fac[i] = fac[i - 1] * i % MOD;
        int n;
        while (in >> n) {
            int num = 0;
            rep(i, n)
            in >> a[i];
            in >> b;
            rep(i, n)
            dp[i][i] = a[i];
            rep2(len, 1, n - 1)
            {
                rep(i, n)
                {
                    if (i + len >= n)break;
                    int r = i + len;
                    dp[i][r] = 0;
                    rep2(j, i, r - 1)
                    {
                        ll x = dp[i][j];
                        ll y = dp[j + 1][r];
                        ll res;
                        if (b[j] == '*')res = x * y % MOD;
                        else if (b[j] == '+')res = (x * fac[r - j - 1] + y * fac[j - i]) % MOD;
                        else res = ((x * fac[r - j - 1] - y * fac[j - i]) % MOD + MOD) % MOD;
                        res = res * C[len - 1][j - i] % MOD;
                        dp[i][r] = (dp[i][r] + res) % MOD;
                    }
                }
            }
            out << dp[0][n - 1] << endl;
        }
    }
};