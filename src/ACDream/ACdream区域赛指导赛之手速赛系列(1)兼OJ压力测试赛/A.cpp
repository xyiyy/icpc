#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int solve(int n)
{
    if(n<3) return 0;
    if(n==3) return 1;
    if(n==4) return 8;
    if(n==5) return 35;
    if(n==6) return 32;
    int ans=0;
    ans = 5*n;
    return ans%20121111;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int cas,T=1;
    scanf("%d",&cas);
    while(cas--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",T++,solve(n));
    }
    return 0;
}

