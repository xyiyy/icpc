//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
const int maxn=10010;
vector<int>G[maxn];
vector<int>rG[maxn];
vector<int>vs;
int vis[maxn];
int cmp[maxn];
int last[maxn];
int deg[maxn];
int Next[maxn];
int V;
vector<int>vc[maxn];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    rG[v].push_back(u);
}
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        G[i].clear();
        rG[i].clear();
        vc[i].clear();
        vis[i]=0;
        last[i]=-1;
        deg[i]=0;
        Next[i]=-1;
    }
}
void dfs(int v)
{
    vis[v]=1;
    for(int i=0;i<G[v].size();i++)
    {
        if(!vis[G[v][i]])dfs(G[v][i]);
    }
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    vis[v]=1;
    cmp[v]=k;
    vc[k].push_back(v);
    for(int i=0;i<rG[v].size();i++)
    {
        if(!vis[rG[v][i]])rdfs(rG[v][i],k);
    }
}
int scc()
{
    memset(vis,0,sizeof(vis));
    vs.clear();
    for(int i=0;i<V;i++)
    {
        if(!vis[i])dfs(i);
    }
    memset(vis,0,sizeof(vis));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!vis[vs[i]])rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
    ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
        V=n;
        init(n);
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            add_edge(--u,--v);
        }
        int k=scc();
        memset(vis,0,sizeof(vis));
        int flag=1;
        int num=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<vc[i].size();j++){
                u=vc[i][j];
                for(int l=0;l<G[u].size();l++){
                    v=G[u][l];
                    if(cmp[u]!=cmp[v]){
                        if(last[cmp[v]]==-1){
                            last[cmp[v]]=cmp[u];
                        }
                        else if(last[cmp[v]]==cmp[u])continue;
                        else flag=0;
                        if(Next[cmp[u]]==-1){
                            Next[cmp[u]]=cmp[v];
                        }
                        else if(Next[cmp[u]]==cmp[v]){
                            continue;
                        }
                        else flag=0;
                    }
                }
            }
        }
        for(int i=0;i<k;i++){
            if(last[i]==-1)num++;
        }
        if(flag&&num==1)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}




