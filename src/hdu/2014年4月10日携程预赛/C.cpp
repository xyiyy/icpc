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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;

#define min(x,y) (x < y ? x : y)  
#define MAX 101  
  
int dp[MAX][MAX];  
  
bool cmp(int n,int m)  
{  
    if((n == '('&&m == ')')||(n == '['&&m == ']'))     return 1;  
    else  
    return 0;  
}  
  
int main(void)  
{  
    int n,m,i,j,k;  
    char str[101];  
    scanf("%d",&n);  
    while(n--)  
    {  
        scanf("%s",str);  
        int length = strlen(str);  
        memset(dp,0,sizeof(dp));  
        for(i = 0; i < length; i++)  
        {  
            dp[i][i] = 1;  
        }  
        for(m = 1; m < length; m++)  
        {  
            for(i = 0; i < length - m; i++)  
            {  
                j = i + m;  
                dp[i][j] = MAX;   
                if(cmp(str[i],str[j]))    
                dp[i][j] = min(dp[i][j],dp[i+1][j-1]);  
                for(k = i; k < j; k++)  
                {  
                   dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);  
                }  
            }  
        }  
        printf("%d\n",dp[0][length-1]);  
    }  
    return 0;  
}  

