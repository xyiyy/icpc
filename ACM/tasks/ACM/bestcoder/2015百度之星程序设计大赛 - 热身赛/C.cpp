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
typedef pair<int,ll> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
ll dp[2010][60];
vector<PII>G[2010];
ll dp2[60];
int k;
void dfs(int u,int fa){
    for(int i=0;i<G[u].size();i++){
        PII p = G[u][i];
        int v = p.first;
        ll d = p.second;
        if(v==fa)continue;
        dfs(v,u);
        for(int j=0;j<=k;j++)dp2[j]=dp[u][j];
        for(int j=0;j<=k;j++){
            for(int l=0;l<=j;l++){
                dp2[j]=min(dp2[j],dp[u][j-l]+dp[v][l]+d*l*(k-l)*2);
            }
        }
        for(int j=0;j<=k;j++){
            dp[u][j]=dp2[j];
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>k;
        int u,v,d;
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n-1;i++){
            cin>>u>>v>>d;
            u--;
            v--;
            G[u].PB(MP(v,d));
            G[v].PB(MP(u,d));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                if(j<=1)dp[i][j]=0;
                else dp[i][j]=1LL<<60;
            }
        }
        dfs(0,-1);
        cout<<dp[0][k]<<endl;

    }

	return 0;
}


