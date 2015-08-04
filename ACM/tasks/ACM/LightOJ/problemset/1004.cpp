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
ll a[510][210];
ll dp[210][110];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int n;
        cin>>n;
        CLR(dp,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin>>a[i][j];
            }
            if(i){
                dp[i][0]=dp[i-1][0]+a[i][0];
                for(int j=1;j<=i;j++){
                    if(j<i)
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
                    else dp[i][j]=dp[i-1][j-1]+a[i][j];
                }
            }
            else{
                dp[0][0]=a[0][0];
            }
        }
        for(int i=n;i<2*n-1;i++){
            for(int j=0;j<(2*n-1)-i;j++){
                cin>>a[i][j];
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+a[i][j];
            }
        }
        cout<<"Case "<<cas++<<": "<<dp[2*n-2][0]<<endl;
    }

	return 0;
}



