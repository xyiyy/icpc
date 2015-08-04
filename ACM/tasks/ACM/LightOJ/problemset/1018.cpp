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
int line[21][21];
int x[21],y[21];
int dp[(1<<16)+10];
bool ok(int a,int b,int c,int d){
    if(a*d==b*c)return 1;
    return 0;
}
int n;
int dfs(int now){
    if(dp[now]!=INF)return dp[now];
    int cnt = __builtin_popcount(now);
    if(!cnt)return dp[now] = 0;
    if(cnt<=2)return dp[now] = 1;
    for(int i=0;i<n;i++){
        if((now&(1<<i))==0)continue;
        for(int j=i+1;j<n;j++){
            if((now&(1<<j))==0)continue;
            dp[now] = min(dp[now],dfs(now^(now&line[i][j]))+1);
        }
        return dp[now];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                line[i][j]=((1<<i)|(1<<j));
                for(int k=0;k<n;k++)
                    if(ok(x[k]-x[i],y[k]-y[i],x[k]-x[j],y[k]-y[j]))
                        line[i][j]|=(1<<k);
            }
        }
        int tot = 1<<n;
        for(int i=0;i<tot;i++)dp[i]=INF;
        cout<<"Case "<<cas++<<": "<<dfs(tot-1)<<endl;

    }

    return 0;
}
