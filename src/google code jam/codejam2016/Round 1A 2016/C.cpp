
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
typedef vector<PII> vii;
typedef vector<int> vi;
int V;
const int MAX_V = 1050;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
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
int a[MAX_V];
int num[MAX_V];
int gao[MAX_V];
int vis[MAX_V];
int dp[MAX_V];
int dfs1(int u,int fa){
    if(dp[u])return dp[u];
    int ret = 1;
    int sz = rG[u].size();
    rep(i,sz){
        int v = rG[u][i];
        if(v == fa)continue;
        ret = max(ret,dfs1(v,u)+1);
    }
    dp[u] = ret;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;

    freopen("Cl.in","r",stdin);
    freopen("Cl.out","w",stdout);
    cin >> t;
    int cas = 1;
    while(t--){
        int n;
        cin >> n;
        V = n;
        rep(i,n)G[i].clear(),rG[i].clear();
        clr(num,0);
        clr(vis,0);
        rep(i,n){
            cin >> a[i];
            a[i]--;
            G[i].pb(a[i]);
            rG[a[i]].pb(i);
        }
        int ans = 0;
        int c = 0;
        clr(dp,0);
        rep(i,n){
            int u = a[i];
            //cout << i << " " << a[u] << endl;
            if(u < i)continue;
            int tmp = 0;
            if(a[u] == i){
                tmp += dfs1(i,u);
                tmp += dfs1(u,i);
                ans += tmp;
            }
        }
        scc();
        rep(i,n){
            num[cmp[i]]++;
        }
        rep(i,n){
            ans = max(ans,num[i]);
        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}
