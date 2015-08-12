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
ll dp[1010][1010];
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    dp[0][0]=1;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<m;j++)dp[i][0]+=dp[i-1][j];
        for(int j=1;j<m;j++){
            dp[i][j]+=dp[i-1][j-1];
        }
    }
    cout<<dp[n+1][0]<<endl;

	return 0;
}


