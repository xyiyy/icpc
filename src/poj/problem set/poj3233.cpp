#include "../../xyiyy/lib.hpp"

int a[110][110];
ll MOD;
const int maxn = 61;

#include "../../xyiyy/math/Matrix.hpp"

class poj3233 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, k;
        while (in >> n >> k >> MOD) {
            rep(i, n)
            {
                rep(j, n)
                {
                    in >> a[i][j];
                }
            }
            Matrix ans(n * 2, n * 2);
            rep(i, n)
            {
                rep(j, n)
                {
                    ans.m[i + n][j + n] = a[i][j];
                    ans.m[i][j] = 0;
                    ans.m[i][j] = (i == j) ? 1 : 0;
                    ans.m[i][j + n] = (i == j) ? 1 : 0;
                }
            }
            Matrix tmp(n * 2, n);
            rep(i, n)
            {
                rep(j, n)
                {
                    tmp.m[i][j] = 0;
                    tmp.m[i + n][j] = (i == j) ? 1 : 0;
                }
            }
            ans = ans.power(k + 1);
            ans = ans * tmp;
            rep(i, n)
            {
                rep(j, n)
                {
                    if (j)out << " ";
                    if (i == j)ans.m[i][j]--;
                    out << (ans.m[i][j] + MOD) % MOD;
                }
                out << endl;
            }
        }
    }
};