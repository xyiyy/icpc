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
typedef vector<int> VI;
#define MAXN 1010
#define MAXE 200010
int gao[MAXN];
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

void init() {
    rep(i,MAXN) Map[i].clear();
    n_edge = 0;
}

int d[MAXN];
int gap[MAXN];
int bfs(int s, int t) {
    int n = 0;
    queue<int> q;
    rep(i,MAXN) d[i] = -1;
    rep(i,MAXN) gap[i] = 0;
    d[t] = 0;
    q.push(t);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        gap[d[u]]++;
        n++;
        rep(i,Map[u].size()) {
            int e=Map[u][i];
            int v=edge[e].v;
            if(edge[e^1].f < edge[e^1].c && d[v] == -1) {
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
        rep(i, Map[u].size()) {
            int e = Map[u][i];
            int v = edge[e].v;
            if(edge[e].f < edge[e].c && d[u] == d[v] + 1) {
                // advance
                u = v;
                last[v] = e;
                f = 1;
                break;
            }
        }
        if(!f) {
            // retreat
            int _min = n;
            rep(i,Map[u].size()) {
                int e = Map[u][i];
                int v = edge[e].v;
                if(edge[e].f < edge[e].c) _min = min(_min, d[v]);
            }
            if(--gap[d[u]]==0) break;
            d[u] = _min+1;
            if(d[u] < n) gap[d[u]]++;
            if(u != s) u = edge[last[u]].u;
        }
    }
    return res;
}

void add_edge(int u, int v, ll c) {
    edge[n_edge] = Edge(u,v,c,0);
    Map[u].pb(n_edge++);
    edge[n_edge] = Edge(v,u,0,0);
    Map[v].pb(n_edge++);
}


int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n ,m;
        init();
        //for(int i = 0 ; i<MAXN;i++)G[i].clear();
        clr(gao,-1);
        cin >> n >> m;
        int s = 2 * n;
        int t = s + 1;
        int a,b,mid;
        int u ,v;
        cin >> a >> b >>mid;
        a--,b--,mid--;
        for(int i = 0;i< m; i++){
            cin >> u >> v;
            u--,v--;
            add_edge(u+n,v,1);
            add_edge(v+n,u,1);
        }
        for(int i =0 ; i <n ; i++){
            if(i!=mid)
            add_edge(i,i+n,1);
            else add_edge(i,i+n,2);
        }
        add_edge(s,a,1);
        add_edge(s,b,1);
        add_edge(mid+n,t,2);
        ISAP(s,t);
        int p = a;
        int last = s;
        while(p!=mid){
            if(p<n)cout << p + 1 << " ";
            for(int i =0 ;i <Map[p].size();i++){
                int e = Map[p][i];
                int v = edge[e].v;
                int f = edge[e].f;
                int c = edge[e].c;
          //      cout << v << " " << f << " " << c << endl;
                if(v == last)continue;
                if(f == 1 && c == 1){
                    last = p;
                    p = v;
                    break;
                }
            }
          //  system("pause");
        }
       // system("pause");
        cout << mid+1<<" ";
        stack<int >st;
        p = b;
        last = s;
        while(p!=mid){
            //cout << p + 1 << " ";
            for(int i =0 ;i <Map[p].size();i++){
                int e = Map[p][i];
                int v = edge[e].v;
                int f = edge[e].f;
                int c = edge[e].c;
               // cout << v << " " << f << " " << c << endl;
                if(v == last)continue;
                if(f == 1 && c == 1){
                    last = p;
                    if(p<n)st.push(p+1);
                    p = v;
                    break;
                }
            }
           // system("pause");
        }
        while(!st.empty()){
            p = st.top();
            cout << p;
            st.pop();
            if(!st.empty())cout << " ";
        }
        cout << endl;
        /*for(int i = 0; i < t ; i++){
            cout << i << " "<< gao[i] << endl;
        }*/
        /*int p = a;
        while(p != mid){
             if(p<n)cout << p + 1 << " ";
             p = gao[p];
        }
        cout << mid + 1 << " ";
        p = b;
        stack<int>st;
        while(p != mid){
            if(p<n)st.push(p+1);
            p = gao[p];
        }
        while(!st.empty()){
            p = st.top();
            cout << p;
            st.pop();
            if(st.empty());
            else cout << " ";
        }
        cout << endl;*/
        //cout << dinic(s,t)<<endl;
    }
    return 0;
}
