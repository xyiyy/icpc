#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

const int maxn = 1000000000;
int arr[105], brr[105];
int dp[10002][16];

int min(int a, int b)
{
    if(a > b)
        return b;
    return a;
}

int main()
{
    int L, N;
    while(scanf("%d %d", &L, &N) != EOF)
    {
        int len = L*N;
        for(int i = 0; i < L; ++i)
            scanf("%d", &arr[i]);
        for(int i = 0; i < L; ++i)
            scanf("%d", &brr[i]);

        for(int i = 1; i <= len; ++i)
            for(int j = 0; j < 15; ++j)
                dp[i][j] = maxn;

        dp[1][1] = arr[0];

        for(int i = 1; i < len; ++i)
        {
            for(int j = 0; j < 15; ++j)
            {
                int t = j+1;
                if(t == 15) t = 10;
                dp[i+1][t] = min(dp[i+1][t], dp[i][j]+arr[i%L]);

                if(j >= 5)
                {
                    dp[i+1][j-5] = min(dp[i+1][j-5], dp[i][j]+brr[i%L]);
                }
            }
        }

        int ans = maxn;
        for(int i = 0; i < 15; ++i)
        {
            ans = min(ans, dp[len][i]);
        }
        cout << ans << endl;
    }
    return 0;
}

