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
const ll MOD=1000000007;
ll dp[200010];
ll dp1[200010];
vector<int>G[200010];
ll dp2[200010];
ll pre[200010];
ll last[200010];
void dfs(int x){
    dp[x]=1;
    for(int i=0;i<G[x].size();i++){
        int v=G[x][i];
        dfs(v);
        dp[x]=dp[x]*(dp[v]+1)%MOD;
    }
}
void dfs1(int x){
    dp1[x]=dp[x]*dp2[x]%MOD;
    pre[0]=1;
    for(int i=0;i<G[x].size();i++){
        int v = G[x][i];
        pre[i+1]=pre[i]*(dp[v]+1)%MOD;
    }
    last[(int)G[x].size()]=1;
    for(int i=(int)G[x].size()-1;i>=0;i--){
        int v = G[x][i];
        last[i]=last[i+1]*(dp[v]+1)%MOD;
    }
    for(int i=0;i<G[x].size();i++){
        int v = G[x][i];
        dp2[v]=dp2[x]*pre[i]%MOD*last[i+1]%MOD;
        dp2[v]++;
    }
    for(int i=0;i<G[x].size();i++){
        int v = G[x][i];
        dfs1(v);
    }
}
int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    for(int i=2;i<=n;i++){
        cin>>a;
        G[a].PB(i);
    }
    fill(dp2,dp2+n+2,1);
    dfs(1);
    dfs1(1);
    for(int i=1;i<=n;i++)cout<<dp1[i]<<" ";
    cout<<endl;
	return 0;
}


