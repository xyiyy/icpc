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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int MAX_V = 10010;
int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
bool vis[MAX_V];

void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<rG[v].size();i++)
	{
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}

int scc()
{
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0;v<V;v++)
	{
		if(!used[v])dfs(v);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]])rdfs(vs[i],k++);
	}
	return k;
}
int deg[MAX_V];
//vector<int>tmp[MAX_V];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    int cas =1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        V = n;
        rep(i,V)G[i].clear();
        rep(i,V)rG[i].clear();
        int u,v;
        clr(deg,0);
        rep(i,m){
            scanf("%d%d",&u,&v);
            u--;v--;
            add_edge(u,v);
        }
        int ans = 0;
        int k = scc();
        clr(deg,0);
        rep(i,n){
            u = cmp[i];
            rep(j,G[i].size()){
                v = G[i][j];
                v = cmp[v];
                deg[v]++;
            }
        }
        rep(i,k){
            if(!deg[i])ans++;
        }
        cout << "Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
