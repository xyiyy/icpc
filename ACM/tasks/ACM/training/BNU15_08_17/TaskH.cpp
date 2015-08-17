#include "../../xyiyy/lib.hpp"
ll x[1010],y[1010];
vector<int>G[1010];
void addedge(int u,int v){
	G[u].pb(v);
	G[v].pb(u);
}
int vis[1010];
int dis[1010];
void dijkstra(int s,int n){
	rep(i,n)vis[i] = 0;
	rep(i,n)dis[i] = INF;
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(vis[x])continue;
		vis[x] = 1;
		for(int i = 0;i<G[x].size();i++){
			int y = G[x][i];
			if(dis[x] + 1 < dis[y] && !vis[y]){
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
}
class TaskH {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			while(t--){
				int n,s,f;
				double l1,l2;
				in>>n>>s>>f>>l1>>l2;
				s--;f--;
				double l = (l1 + l2) * (l2 + l1);
				rep(i,n)G[i].clear();
				rep(i,n)in>>x[i]>>y[i];
				rep(i,n){
					rep2(j,i+1,n-1){
						double tmp = 1.0*(x[i] - x[j])*(x[i] - x[j]) + 1.0*(y[i] - y[j])*(y[i] - y[j]);
						if(l-tmp>=0){addedge(i,j);}
					}
				}
				dijkstra(s,n);
				if(dis[f]==INF)out<<"Impossible"<<endl;
				else out<<dis[f]<<endl;
			}
		}
};