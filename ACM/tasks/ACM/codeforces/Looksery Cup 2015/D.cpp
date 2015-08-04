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
char a[110][110];
int dp[110][110];
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    /*dp[n-1][n-1]=0;
    for(int j=m-2;j>=0;j--){

    }*/
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int x =a[i][j]=='W'?1:-1;
            if(i!=n-1)dp[i][j]+=dp[i+1][j];
            if(j!=m-1)dp[i][j]+=dp[i][j+1];
            if(i!=n-1&&j!=m-1)dp[i][j]-=dp[i+1][j+1];
            if(dp[i][j]!=x)ans++;
            dp[i][j]=x;
        }
    }
    cout<<ans<<endl;
	return 0;
}

