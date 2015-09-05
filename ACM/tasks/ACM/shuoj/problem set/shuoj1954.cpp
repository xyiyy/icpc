#include "../../xyiyy/lib.hpp"

char str[1010][1010];
int dp[1010][1010];
int dp2[1010][1010];

class shuoj1954 {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;
        while (t--) {
            int n, m;
            in >> n >> m;
            rep(i, n + 10)
                rep(j, m + 10)str[i][j] = 'x';
            rep2(i, 1, n)
                rep2(j, 1, m)in >> str[i][j];
            rep2(i, 1, n)
                rep2(j, 1, m) {
                    if (str[i][j] == 'x') {
                        dp[i][j] = dp2[i][j] = 0;
                    } else {
                        if (str[i - 1][j] == 'x') {
                            int k = i + 1;
                            int num = 0;
                            while (str[k][j] != 'x')num++, k++;
                            dp[i][j] = num;
                        }
                        else dp[i][j] = dp[i - 1][j];
                        if (str[i][j - 1] == 'x') {
                            int k = j + 1;
                            int num = 0;
                            while (str[i][k] != 'x')num++, k++;
                            dp2[i][j] = num;
                        } else dp2[i][j] = dp2[i][j - 1];
                    }
                }
            int ans = 0;
            rep2(i, 1, n)
                rep2(j, 1, m)ans = max(dp[i][j] + dp2[i][j], ans);
            out << ans << endl;
        }
    }
};