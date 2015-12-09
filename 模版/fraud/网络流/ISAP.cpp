#define MAXN 100010
#define MAXE 200010

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
    REP(i,MAXN) Map[i].clear();
    n_edge = 0;
}

int d[MAXN];
int gap[MAXN];
int bfs(int s, int t) {
    int n = 0;
    queue<int> q;
    REP(i,MAXN) d[i] = -1;
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
        REP(i, Map[u].size()) {
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
            REP(i,Map[u].size()) {
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

void addEdge(int u, int v, ll c) {
    edge[n_edge] = Edge(u,v,c,0);
    Map[u].PB(n_edge++);
    edge[n_edge] = Edge(v,u,0,0);
    Map[v].PB(n_edge++);
}

