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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
char s[110];
int dp[110][2];
int main()
{
    ios::sync_with_stdio(false);
    freopen("Blarge.in","r",stdin);
    freopen("Blarge.out","w",stdout);
    int t,cas = 1;
    cin >> t;
    while(t--){
        cin >> s + 1;
        int n = strlen(s+1);
        for(int i = 1; i <= n ; i ++){
            if(s[i] == '+'){
                dp[i][1] = min(dp[i-1][1],dp[i-1][0] + 1);
                dp[i][0] = min(dp[i-1][1]+1,dp[i-1][0] + 2);
            }else{
                dp[i][0] = min(dp[i-1][0],dp[i-1][1]+1);
                dp[i][1] = min(dp[i-1][0]+1,dp[i-1][1]+2);
            }
        }
        cout << "Case #" << cas ++ << ": " << dp[n][1] << endl;
    }
    return 0;
}
