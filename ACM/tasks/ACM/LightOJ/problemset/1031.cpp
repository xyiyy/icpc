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
int a[110];
int sum[110];
int dp[110][110];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sum[0] = 0;
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i-1];
        sum[n+1]=sum[n];
        //for(int i=0;i<n;i++)dp[1][i]=a[i];
        for(int len=1;len<=n;len++){
            for(int i=0;i<n;i++){
                dp[len][i]=sum[i+len]-sum[i];
                for(int j=i;j<i+len;j++){
                    if(j>i)dp[len][i]=max(dp[len][i],sum[j]-sum[i]-dp[i+len-j][j]);
                    if(j<i+len-1)dp[len][i]=max(dp[len][i],sum[i+len]-sum[j+1]-dp[j-i+1][i]);
                    //dp[len][i]=max(dp[len][i],max(sum[i+len]-sum[j+1]-dp[j-i+1][i],-dp[i+len-j][j]+sum[j]-sum[i]));
                }
            }
        }
        cout<<"Case "<<cas++<<": "<<dp[n][0]<<endl;

    }
    return 0;
}
