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
vector<int>G[1010];
void add_edge(int u,int v){
    G[u].PB(v);
}
int deg[1010];
int vis[10010];
void dfs(int x){
    if(vis[x])return;
    vis[x] = 1;
    for(int i=0;i<G[x].size();i++){
        dfs(G[x][i]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n&&n){
        cin>>m;
        for(int i=0;i<n;i++)G[i].clear();
        CLR(vis,0);
        CLR(deg,0);
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            u--;v--;
            add_edge(u,v);
            add_edge(v,u);
            deg[u]++;deg[v]++;
        }
        int num = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                num++;
            }
        }
        if(num!=1)cout<<0<<endl;
        else{
            int f = 1;
            for(int i=0;i<n;i++){
                if(deg[i]&1) f = 0;
            }
            cout<<f<<endl;
        }

    }
    return 0;
}
