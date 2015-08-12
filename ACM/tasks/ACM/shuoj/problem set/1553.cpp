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
int n,m;
int dp[110][110];
int a[110][110];
int dfs(int x,int y,int h){
    if(x<1||x>n||y<1||y>m||a[x][y]>=h)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y] = max(max(dfs(x-1,y,a[x][y]),dfs(x,y-1,a[x][y])),max(dfs(x,y+1,a[x][y]),dfs(x+1,y,a[x][y])))+1;
    return dp[x][y];
}
int main()
{
	ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                dp[i][j]=-1;
            }
        }
        int ans = 0 ;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans = max(ans , dfs(i,j,INF));
            }
        }
        cout<<ans<<endl;
    }

	return 0;
}


