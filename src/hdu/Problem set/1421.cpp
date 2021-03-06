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
ll dp[2010][1010];
int a[2010];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    while(cin>>n>>k){
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j] = 0;
            }
        }
        sort(a,a+n);
        dp[1][1] = (a[1]-a[0])*(a[1]-a[0]);
        for(int i=2;i<=n;i++){
            for(int j=1;(j*2-1)<=i;j++){
                if(j*2-1==i)dp[i][j] = dp[i-2][j-1] + (a[i]-a[i-1])*(a[i]-a[i-1]);
                else dp[i][j] = min(dp[i-1][j],dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
            }
        }
        cout<<dp[n-1][k]<<endl;
    }
    return 0;
}
