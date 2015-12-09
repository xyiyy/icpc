#include "../../xyiyy/lib.hpp"

int a[110];
int b[110];
int f[110];

class TaskG {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        while (in >> n) {
            rep(i, n)
            {
                in >> a[i];
                f[a[i]] = i;
            }
            rep(i, n)
            {
                in >> b[i];
                b[i] = f[b[i]];
            }
            int ans = 0;
            rep(i, n)
            {
                rep2(j, i + 1, n - 1)
                {
                    if (b[j] < b[i])ans++;
                }
            }
            out << ans << endl;
        }
    }
};