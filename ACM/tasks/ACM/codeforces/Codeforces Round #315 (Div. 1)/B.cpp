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
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int dp[4010][4010];
const int MOD = 1e9+7;
int C(int n,int m){
    if(m==1||m==n)return 1;
    if(dp[n][m]!=-1)return dp[n][m];
    return dp[n][m] = ((ll)C(n-1,m)*m+C(n-1,m-1))%MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll ans = 0;
    cin>>n;
    clr(dp,-1);
    dp[1][0] =1;
    rep2(i,1,n){
        ans =(ans + (ll)i*C(n,i))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
