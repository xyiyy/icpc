#include <iostream>

using namespace std;
int dp[30][20][5][2];
int ans[30][20];

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    for (int i = 1; i < 4; i++)dp[1][1][i][0] = 1;
    for (int i = 2; i <= 20; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 4; k++) {
                for (int l = 1; l < k; l++)dp[i][j][k][0] += dp[i - 1][j][l][0] + dp[i - 1][j - 1][l][1];
                if (i == 2)dp[i][j][k][1] = 0;
                else for (int l = k + 1; l < 5; l++)dp[i][j][k][1] += dp[i - 1][j][l][1] + dp[i - 1][j][l][0];
            }
        }
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k < 4; k++) {
                ans[i][j] += dp[i][j][k][1];
            }
        }
    }
    cin >> n >> t;
    cout << ans[n][t] << endl;

    return 0;
}
