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
const int MAX_V = 410;
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
        CLR(vis, 0);
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
    return res;
}