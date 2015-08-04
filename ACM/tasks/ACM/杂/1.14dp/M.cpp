#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
using namespace std;

double dp[1005][105];  
int main()  
{  
    int c,n,m;  
    while(scanf("%d",&c)&&c)  
    {  
        scanf("%d%d",&n,&m);  
        if(m>n||m>c||(m%2==0&&n%2!=0)||(m%2!=0&&n%2==0))  
        {  
            printf("0.000\n");  
            continue;  
        }  
        if(n>1000)  
        {  
        	if(n%2==0)  n=1000;  
            else        n=1001;  
        }  
        memset(dp,0,sizeof(dp));  
        dp[0][0]=1;  
        for(int i=1;i<=n;++i)  
        {  
            dp[i][0]=dp[i-1][1]/c;  
            dp[i][c]=dp[i-1][c-1]/c;  
            for(int j=1;j<c;++j)  
                dp[i][j]=dp[i-1][j-1]*(c-j+1)/c+dp[i-1][j+1]*(j+1)/c;  
        }  
        printf("%.3lf\n",dp[n][m]);  
    }  
    return 0;  
}  





