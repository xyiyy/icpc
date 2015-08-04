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
const int MAXN = 110;
int dis[MAXN];
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
    G[v].PB(MP(u,d));
}
bool vis[MAXN];
void dijkstra(int s,int n){
    CLR(vis,0);
    for(int i=0;i<n;i++)dis[i]=INF;
    dis[s]=0;
    priority_queue<PII,vector<PII>,greater<PII> >q;
    q.push(MP(dis[s],s));
    while(!q.empty()){
        PII p = q.top();
        q.pop();
        int x = p.second;
        if(vis[x])continue;
        vis[x] = 1;
        if(vis[n-1])break;
        for(int i=0;i<G[x].size();i++){
            p = G[x][i];
            int y = p.first;
            int d = p.second;
            if(!vis[y]&&dis[y]>dis[x]+d){
                dis[y] = dis[x]+d;
                q.push(MP(dis[y],y));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int u,v,d;
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<m;i++){
            cin>>u>>v>>d;
            u--;
            v--;
            add_edge(u,v,d);
        }
        cout<<"Case "<<cas++<<": ";
        dijkstra(0,n);
        if(dis[n-1]==INF)cout<<"Impossible"<<endl;
        else cout<<dis[n-1]<<endl;
    }
    return 0;
}
