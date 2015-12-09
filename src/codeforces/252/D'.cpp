#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 1000 + 10
#define INF 2100000000
#define ll long long
int n, a[3010];
bool vis[3010];
void dfs(int i)
{
    if(vis[i]) return;
    vis[i] = true;
    dfs(a[i]);
    return;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int sum = 0;
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) dfs(i), ++sum;
    int m;
    scanf("%d", &m);
    int len = abs(m-(n-sum));
    printf("%d\n", len);
    if((n-sum) < m)
    {
        for(int i = 1; i <= len; ++i)
        {
            if(i!=1) printf(" ");
            memset(vis, false, sizeof(vis));
            dfs(1);
            int j;
            for(j = 1; j <= n; ++j)
                if(!vis[j]) break;
            printf("%d %d", 1, j);
            swap(a[1], a[j]);
        }
        printf("\n");
    }
    else
    {
        for(int i = 1; i <= len; ++i)
        {
            if(i!=1) printf(" ");
            int j;
            for(j = 1; j <= n; ++j)
                if(a[j] != j) break;
            int small = n;
            for(int k = a[j]; k != j; k = a[k])
                small = min(k, small);
            printf("%d %d", j, small);
            swap(a[j], a[small]);
        }
        printf("\n");
    }
    return 0;
}
