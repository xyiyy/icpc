#include <iostream>
#include <cstdio>

using namespace std;
int t[111][111], dp[2][111];

int main() {
    int f, v;
    while (cin >> f >> v) {
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < v; j++) {
                scanf("%d", &t[i][j]);
            }
        }
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < v; j++) {
                if (i == 0) dp[0][j] = t[0][j];
                else if (j - i >= 0) {
                    dp[i % 2][j] = dp[(i + 1) % 2][i - 1] + t[i][j];
                    for (int k = j - 1; k > i - 1; k--)
                        dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][k] + t[i][j]);
                }
            }
        }
        int ans = -1000000;
        for (int i = f - 1; i < v; i++) {
            ans = max(ans, dp[(f - 1) % 2][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
