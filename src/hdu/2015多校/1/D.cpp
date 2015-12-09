//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[210];
ll dp[210][40010];
const ll MOD = 1000000007;
ll sum[40010];
ll gao[410];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)cin >> a[i];
        dp[0][0] = 1;
        int tot = n * 100;
        for (int i = 1; i <= n; i++) {
            tsum[0] = dp[i - 1][0];
            for (int j = 2; j <= tot * 2; j += 2) {
                tsum[j] = (tsum[j - 2] + dp[i - 1][j]) % MOD;
            }
            tsum[1] = dp[i - 1][1];
            for (int j = 1; j <= tot * 2; j += 2) {
                tsum[j] = (tsum[j - 2] + dp[i - 1][j]) % MOD;
            }
            for (int j = 0; j <= a[i]; j++) {
                gao[j] = (a[i] - j + 1) / 2;
            }
            ll sum = gao[0] * dp[i - 1][a[i]];
            for (int j = a[i]; j > 0; j--) {
                sum = (gao[j] * dp[i - 1][a[i] - j] + sum) % MOD;
            }
            for (int j = a[i] + 1; j < 2 * a[i]; j++) {
                sum = (sum + gao[j - a[i]] * dp[i - 1][j]) % MOD;
            }
            int num = a[i];
            int f;
            if (num & 1)f = 1;
            else f = 0;
            for (int j = a[i]; j <= tot - a[i]; j++) {
                dp[i][j] = sum;
                if (f) {
                    sum = ((sum - (tsum[j - 1] - tsum[(j - a[i] - 2 > 0) ? (j - a[i] - 2) : 0])) % MOD + MOD) % MOD;
                    sum = (sum + (tsum[j + a[i] + 1] - tsum[j - 1])) % MOD;
                } else {
                    sum = ((sum - (tsum[j] - tsum[(j - a[i] - 2 > 0) ? (j - a[i] - 2) : 0])) % MOD + MOD) % MOD;
                    sum = (sum + (tsum[j + a[i] + ]))
                }


                return 0;
            }



