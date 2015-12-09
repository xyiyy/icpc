struct edge
{
	int to,cap,rev;
	edge(int _to,int _cap,int _rev)
	{
		to=_to;cap=_cap;rev=_rev;
	}
};
vector<edge> >G[MAXN];
int level[MAXN];//层次标号 
int iter[MAXN];//当前弧 
void add_edge(int u,int v,int cap){
	G[u].PB(edge(v,cap,G[v].size()));
	G[v].PB(edge(u,0,G[u].size()-1));
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>que;
	level[s] = 0;
	que.push(s);
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(int i=0;i<G[x].size();i++){
			edge &e = G[x][i];
			if(e.cap > 0 &&level[e.to] < 0){
				level[e.to] = level[x] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v,int t,int f){
	if(v == t)return f;
	for(int &i = iter[v];i<G[v].size();i++){
		edge &e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d > 0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int dinic(int s,int t){
	int flow = 0;
	while(1){
		bfs(s);
		if(level[t] < 0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f = dfs(s,t,INF)) > 0){
			flow += f;
		}
	}
}
		

			


