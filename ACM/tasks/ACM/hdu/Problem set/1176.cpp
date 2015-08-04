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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int dp[100010][11];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        int a,b;
        int maxn = 0;
        CLR(dp,0);
        for(int i=0;i<n;i++){
            //cin>>a>>b;
            scanf("%d%d",&a,&b);
            dp[b][a]++;
            //cout<<dp[a][b]<<endl;
            maxn = max(maxn,b);
        }
        for(int i=maxn-1;i>=0;i--){
            for(int j=0;j<=10;j++){
                if(j==0)dp[i][j] += max(dp[i+1][j],dp[i+1][j+1]);
                else if(j==10)dp[i][j]+=max(dp[i+1][j],dp[i+1][j-1]);
                else dp[i][j] += max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
            }
        }
        printf("%d\n",dp[0][5]);
        //cout<<dp[0][5]<<endl;

    }
    return 0;
}
