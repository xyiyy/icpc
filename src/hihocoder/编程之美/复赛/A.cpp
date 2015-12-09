
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
ll ans=0;
vector<int>G[100010];
ll a[100010];
ll dfs(int x,int fa){
    //cout<<"  "<<x<<endl;
    ll ret=a[x];
    for(int i=0;i<G[x].size();i++){
        int v= G[x][i];
        if(v==fa)continue;
        ret+=dfs(v,x);
    }
    return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	int cas=1;
	cin>>t;
	while(t--){
	    int n,s;
	    int u,v;
	    cin>>n>>s;
	    for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            u--;
            v--;
            G[u].PB(v);
            G[v].PB(u);
        }
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ans =0;
        s--;
        for(int i=0;i<G[s].size();i++){
            ans=max(ans,dfs(G[s][i],s));
        }
        cout<<"Case #"<<cas++<<": ";
        cout<<ans<<endl;

	}
	return 0;
}


