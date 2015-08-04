#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int INF = 1 << 30;
const int N = 205;

int dp[N][N];
int sum[N];
int a[N];

int getMinval(int a[],int n)
{
    for(int i=0;i<n;i++)
        dp[i][i] = 0;
    for(int v=1;v<n;v++)
    {
        for(int i=0;i<n-v;i++)
        {
            int j = i + v;
            dp[i][j] = INF;
            int tmp = sum[j] - (i > 0 ? sum[i-1]:0);
            for(int k=i;k<j;k++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j] + tmp);
        }
    }
    return dp[0][n-1];
}

int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    //while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum[0] = a[0];
        for(int i=1;i<n;i++)
            sum[i] = sum[i-1] + a[i];
        printf("%d\n",getMinval(a,n));
    }
    return 0;
}
