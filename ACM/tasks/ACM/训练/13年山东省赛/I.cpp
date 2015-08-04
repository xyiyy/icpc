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
double dp[110][110];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n){
        double a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        CLR(dp,0);
        for(int i=n;i;i--){
            for(int j = n+1-i;j<=n;j++){
                if(i==n&&j==(n+1-i))continue;
                else if(i==n)dp[i][j]=dp[i][j-1]+1.0;
                else if(j==(n+1-i))dp[i][j]=a*dp[i+1][j-1]+b*dp[i+1][j]+1.0;
                else dp[i][j]=c*dp[i+1][j-1]+d*dp[i+1][j]+e*dp[i][j-1]+1.0;
            }
        }
        cout<<fixed<<setprecision(2)<<dp[1][n]<<endl;
	}
	return 0;
}


