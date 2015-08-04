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
int a, b, c, d, e, f;
int dp[100010];
int sum[100010];

int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &dp[0], &dp[1], &dp[2], &dp[3], &dp[4], &dp[5], &n);
        sum[0]=dp[0];
        for(int i=1;i<6;i++)sum[i]=(sum[i-1]+dp[i])%10000007;
        for(int i=6;i<=n;i++){
            dp[i]=sum[i-1];
            sum[i]=((sum[i-1]*2-dp[i-6])%10000007+10000007)%10000007;
        }
        int ans =dp[n]% 10000007;
        printf("Case %d: %d\n", ++caseno, ans);
    }
    return 0;
}



