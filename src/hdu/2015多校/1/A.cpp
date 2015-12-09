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
#define MAXN 10000
#define MAXE 200000
struct Edge{
    int u, v;
    ll c, f;
    Edge(){};
    Edge(int _u, int _v, ll _c, ll _f) {
        u=_u; v=_v; c=_c; f=_f;
    }
}edge[MAXE*2];
int n_edge;
VI Map[MAXN];
int last[MAXN];
void init() { //记得初始化！
    REP(i,MAXN) Map[i].clear();
    n_edge = 0;
}
int d[MAXN];
int gap[MAXN];
int bfs(int s, int t) {
    int n = 0;
    queue<int> q;
    REP(i,MAXN) d[i] = INF;
    REP(i,MAXN) gap[i] = 0;
    d[t] = 0;
    q.push(t);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        gap[d[u]]++;
        n++;
        REP(i,Map[u].size()) {
            int e=Map[u][i];
            int v=edge[e].v;
            if(edge[e^1].f < edge[e^1].c && d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return n;
}
ll augument(int t) {
    int e = last[t];
    ll fl = INF;
    while(e != -1) {
        int v = edge[e].u;
        fl = min(fl, edge[e].c - edge[e].f);
        e = last[v];
    }
    e = last[t];
    while(e != -1) {
        int v = edge[e].u;
        edge[e].f += fl;
        edge[e^1].f -= fl;
        e = last[v];
    }
    return fl;
}
ll ISAP(int s, int t) {
    ll res = 0;
    int n = bfs(s, t);
    last[s] = -1;
    int u = s;
    while(d[s] < n) {
        if(u == t) {
            res += augument(t);
            u = s;
        }
        int f = 0;
        REP(i, Map[u].size()) {
            int e = Map[u][i];
            int v = edge[e].v;
            if(edge[e].f < edge[e].c && d[u] == d[v] + 1) { // advance
                u = v;
                last[v] = e;
                f = 1;
                break;
            }
        }
        if(!f) { // retreat
            int _min = n;
            REP(i,Map[u].size()) {
                int e = Map[u][i];
                int v = edge[e].v;
                if(edge[e].f < edge[e].c) _min = min(_min, d[v]);
            }
            if(--gap[d[u]]==0) break;
            d[u] = _min+1;
            gap[d[u]]++;
            if(u != s) u = edge[last[u]].u;
        }
    }
    return res;
}
void addEdge(int u, int v, ll c) {
    edge[n_edge] = Edge(u,v,c,0);
    Map[u].PB(n_edge++);
    edge[n_edge] = Edge(v,u,0,0);
    Map[v].PB(n_edge++);
}
int vis[MAXN];
int dis[MAXN];
VI bef[MAXN];
priority_queue<PII,VII,greater<PII> >dij;
queue<int> bf;
vector<PII> G[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		int u,v,td;
		for(int i=0;i<n;i++)G[i].clear();
		for(int i=0;i<n;i++)bef[i].clear();
		for(int i=0;i<m;i++){
			cin>>u>>v>>td;
			u--;v--;
			G[u].PB(MP(v,td));
			G[v].PB(MP(u,td));
		}
		init();
		int s = 0;
		int t = n-1;
		for(int i=0;i<n;i++)vis[i] = 0;
		for(int i=0;i<n;i++)dis[i] = INF;
		dis[s] = 0;
		while(!dij.empty())dij.pop();
		dij.push(MP(0,s));
		while(!dij.empty()){
			PII p = dij.top();
			dij.pop();
			int x = p.second;
			if(vis[x])continue;
			vis[x] = 1;
			for(int i=0;i<G[x].size();i++){
				int y = G[x][i].first;
				int d = G[x][i].second;
				if(!vis[y]&&dis[x] + d < dis[y]){
					dij.push(MP(dis[y],y));
					dis[y] = dis[x] + d;
					bef[y].clear();
				}
				if(dis[x] + d == dis[y]){
					bef[y].PB(x);
				}
			}
		}
		for(int i=0;i<n;i++)dis[i] = INF;
		for(int i=0;i<n;i++)vis[i] = 0;
		dis[t] = 0;
		vis[t] = 1;
		while(!bf.empty())bf.pop();
		bf.push(t);
		//cout<<bef[t].size()<<endl;
		while(!bf.empty()){
			int x = bf.front();
			bf.pop();
			for(int i=0;i<bef[x].size();i++){
				int y = bef[x][i];
				addEdge(x,y,1);
				if(dis[y] == INF){
					dis[y] = dis[x] + 1;
					bf.push(y);
				}
			}
		}
		cout<<ISAP(t,s)<<" "<<m-dis[s]<<endl;
		
		
	}
	return 0;
}



