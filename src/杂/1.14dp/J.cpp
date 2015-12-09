#include<iostream>
#include<cstring>

using namespace std;
char map[55][55];
long long dp[55][55];

void Init() {
    memset(dp, 0, sizeof(dp));
    memset(map, '*', sizeof(map));
}

long long GCD(long long a, long long b) {
    if (b == 0)return a;
    return GCD(b, a % b);
}

int main() {
    int n, m, i, j, k, h;
    long long MAXNUM, gcd;
    while (scanf("%d%d", &n, &m) != EOF) {
        Init();
        MAXNUM = (__int64) 1 << n;
        for (i = 0; i < n; i++)
            for (j = 0; j <= i; j++)
                cin >> map[i][j];
        k = 0;
        h = 0;
        while (k <= n && map[k][h] == '.') {
            k += 2;
            h++;
        }
        dp[k][h] = MAXNUM;
        for (i = 1; i <= n; i++)
            for (j = 0; j <= i; j++) {
                if (j > 0 && map[i - 1][j - 1] == '*')
                    dp[i][j] += dp[i - 1][j - 1] / 2;
                if (map[i - 1][j] == '*')
                    dp[i][j] += dp[i - 1][j] / 2;
                if (map[i][j] == '.') {
                    k = i + 2;
                    h = j + 1;
                    while (k <= n && map[k][h] == '.') {
                        k += 2;
                        h++;
                    }
                    dp[k][h] += dp[i][j];
                }
            }
        gcd = GCD(MAXNUM, dp[n][m]);
        cout << dp[n][m] / gcd << "/" << MAXNUM / gcd << endl;
    }
    return 0;
}
