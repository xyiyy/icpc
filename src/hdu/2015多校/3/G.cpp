#include <bits/stdc++.h>

using namespace std;
#define MOD 998244353
long long dp[100010];

int main() {
    int n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    for (long long i = 0; i <= 100000; i++)dp[i + 3] =
                                                   (((3 * i + 7) * dp[i + 2] - (i + 2) * (3 * i + 2) % MOD * dp[i + 1] +
                                                     (i + 2) * (i + 1) % MOD * i % MOD * dp[i]) % MOD + MOD) % MOD;
    while (scanf("%d", &n) != EOF) {
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
