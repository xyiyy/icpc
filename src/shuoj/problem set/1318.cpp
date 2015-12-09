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
int dp[21][21][21];
int dfs(int a,int b,int c){
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20) return dfs(20,20,20);
    if(dp[a][b][c])return dp[a][b][c];
    if(a<b&&b<c)return (dp[a][b][c] = dfs(a,b,c-1) + dfs(a,b-1,c-1) - dfs(a,b-1,c));
    else return (dp[a][b][c] = dfs(a-1,b,c) + dfs(a-1,b-1,c) + dfs(a-1,b,c-1) - dfs(a-1,b-1,c-1));
}
int main()
{
	ios::sync_with_stdio(false);
    int a,b,c;
    CLR(dp,0);
    dp[0][0][0]=1;
    while(cin>>a>>b>>c&&(a!=-1||b!=-1||c!=-1)){
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
        cout<<dfs(a,b,c)<<endl;
    }
	return 0;
}


