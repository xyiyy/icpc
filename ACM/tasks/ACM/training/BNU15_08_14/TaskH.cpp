#include "../../xyiyy/lib.hpp"
const int maxNode = 10010;
const int maxEdge = (maxNode <<1);
#include "../../xyiyy/Graph/Hashtree.hpp"
#include "../../xyiyy/Graph/TreeDiameter.hpp"
int deg[maxNode];
int vis[maxNode];
class TaskH {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n){
				vector<ull>ans[2];
				rep(times,2) {
					int u, v;
					init(n);
					rep(i, n + 1)deg[i] = 0;
					rep(i, n + 1)vis[i] = 0;
					queue<int> q;
					rep(i, n - 1) {
						in >> u >> v;
						u--,v--;
						deg[u]++;
						deg[v]++;
						addedge(u, v);
						addedge(v, u);
					}
					int dia = getDiameter(n);
					int num = n;
					rep(i, n) {
						if (deg[i] == 1) {
							q.push(i);
						}
					}
					int gao = 1;
					if(dia&1)gao++;
					while (num > gao && !q.empty()) {
						u = q.front();
						q.pop();
						vis[u] = 1;
						num--;
						deg[u]--;
						for (int i = From[u]; i != -1; i = Next[i]) {
							int v = To[i];
							if (!vis[v]) {
								deg[v]--;
								if (deg[v] == 1) {
									q.push(v);
								}
							}
						}
					}
					rep(i, n) {
						if (!vis[i]) {
							ans[times].pb(getHash(i));
						}
					}
				}
				bool ok = 0;
				rep(i,ans[0].size()){
					rep(j,ans[1].size()){
						if(ans[0][i] == ans[1][j])ok = 1;
					}
				}
				if(ok)out<<"S"<<endl;
				else out<<"N"<<endl;
			}
		}
};