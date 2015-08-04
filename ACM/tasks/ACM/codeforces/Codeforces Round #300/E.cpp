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
vector<int>G[200010];
bool isleaf[200010];
int dp[200010];
void dfs1(int u){
    int sz=G[u].size();
    if(!sz)isleaf[u]=1;
    for(int i=0;i<sz;i++){
        int v=G[u][i];
        //isleaf[u]=0;
        dfs1(v);
    }
}
int d=0;
void dfs(int u){
    if(isleaf[u]){
        dp[u]=1;
        return ;
    }
    d++;
    dp[u] = (d&1)?INF:0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        dfs(v);
        if(d&1)dp[u]=min(dp[v],dp[u]);
        else dp[u]+=dp[v];
    }
    d--;
}
int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        G[u].PB(v);
    }
    dfs1(1);
    int num=0;
    for(int i=1;i<=n;i++){
        if(isleaf[i])num++;
    }
    dfs(1);
    cout<<num-dp[1]+1<<" ";
    d=1;
    dfs(1);
    cout<<dp[1]<<endl;;
	return 0;
}



