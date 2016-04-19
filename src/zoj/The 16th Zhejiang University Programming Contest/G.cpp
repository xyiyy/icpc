
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
struct edge {
    int to, cap, cost, rev;

    edge(int _to, int _cap, int _cost, int _rev) {
        to = _to;
        cap = _cap;
        cost = _cost;
        rev = _rev;
    }
};

int V;
const int MAX_V = 510;
vector <edge> G[MAX_V];
int dis[MAX_V];
int prevv[MAX_V], preve[MAX_V];

//最短路中的前驱结点和对应的边
void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
}

int vis[MAX_V];

int min_cost_flow(int s, int t, int f)//如果不能在增广则返回-1
{
    int res = 0;
    while (f > 0) {
        fill(dis, dis + V, INF);
        dis[s] = 0;
        queue <int> q;
        clr(vis, 0);
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            vis[v] = 0;
            for (int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && dis[e.to] > dis[v] + e.cost) {
                    dis[e.to] = dis[v] + e.cost;
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    if (!vis[e.to]) {
                        q.push(e.to);
                        vis[e.to] = 1;
                    }
                }
            }
        }
        /*	bool update=1;
            while(update)
            {
                update=false;
                for(int v=0;v<V;v++)
                {
                    if(dis[v]==INF) continue;
                    for(int i=0;i<G[v].size();i++)
                    {
                        edge &e=G[v][i];
                        if(e.cap>0&&dis[e.to]>dis[v]+e.cost)
                        {
                            dis[e.to]=dis[v]+e.cost;
                            prevv[e.to]=v;
                            preve[e.to]=i;
                            update=1;
                        }
                    }
                }
            }*/
        if (dis[t] == INF) {
            f = INF - f;
            printf("%d %d\n",f,2*f - res);
            return -1;
        }
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dis[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
        //cout<<f<<endl;
        //	cout<<"ok"<<endl;
    }
    printf("%d %d\n",f,2*f - res);
    return res;
}
char str[1010];
int group[1010];
int girls[1010];
int notok[510][510];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int s = n;
        int t= s + 1;
        scanf("%s",str);
        //int len = strlen(str);
        rep(i,n){
            if(str[i] == '0')group[i] = 0;
            else group[i] = 1;
        }
        scanf("%s",str);
        rep(i,n){
            if(str[i] == '0')girls[i] = 1;
            else girls[i] = 0;
        }
        rep(i,n)
        rep(j,n)notok[i][j] = 0;
        int num =0 ,tmp;

        rep(i,n){
            scanf("%d",&num);
            rep(j,num){
                scanf("%d",&tmp);
                tmp--;
                notok[i][tmp] = 1;
            }
        }
        V = t +1;
        rep(i,V){
            G[i].clear();
        }
        rep(i,n){
            if(group[i])add_edge(s,i,1,0);
            else add_edge(i,t,1,0);
        }
        rep(i,n){
            if(group[i]){
                rep(j,n){
                    if(group[j])continue;
                    if(notok[i][j])continue;
                    if(i == j)continue;
                    add_edge(i,j,1,2 - (girls[i]+girls[j]));
                }
            }
        }
        int ans = min_cost_flow(s,t,INF);
        rep(i,n){
            int sz = G[i].size();
            if(!group[i])continue;
            rep(j,sz){
                int u = G[i][j].to;

                if(group[u])continue;
                if(u >= n)continue;
                int c = G[i][j].cap;
                //cout<< i << " "   << u << "  " << c << endl;
                if(c == 0){
                      //  cout << "ok" << endl;
                    printf("%d %d\n",i+1,u+1);
                }

            }
        }

    }
    return 0;
}
