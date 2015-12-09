//#############################
//Ford-Fulkerson
//by fraud
//////////////////////////////// 
struct edge {
    int to, cap, rev;

    //终点，容量，反向边
    edge(int _to, int _cap, int _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};

vector <edge> G[MAX_V];
//图的邻接表表示
bool used[MAX_V];

//dfs访问标记
void add_edge(int from, int to, int cap) {
    G[from].PB(edge(to, cap, G[to].size()));
    G[to].PB(edge(from, 0, G[from].size() - 1));
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    used[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (; ;) {
        CLR(used, 0);
        int f = dfs(s, t, INF);
        if (f == 0)return flow;
        flow += f;
    }
}
		


