#include "../../xyiyy/lib.hpp"

char a[110];
string str[110];
double num[110];

class TaskA {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        while (in >> n) {
            rep(i, n)
                in >> a[i] >> str[i] >> num[i];
            int ans = 0;
            for (double i = -1.5; i < 1010; i += 1.0) {
                int m = 0;
                rep(j, n) {
                    if (gao(i, j))m++;
                }
                ans = max(ans, m);
            }
            rep2(i, -10, 1010) {
                int m = 0;
                rep(j, n) {
                    if (gao(i, j))m++;
                }
                ans = max(ans, m);
            }
            out << ans << endl;

        }
    }

    bool gao(double x, int i) {
        if (str[i] == "<") {
            return x < num[i];
        } else if (str[i] == "<=") {
            return x <= num[i];
        } else if (str[i] == "=") {
            return x == num[i];
        } else if (str[i] == ">") {
            return x > num[i];
        } else if (str[i] == ">=") {
            return x >= num[i];
        }
    }
};