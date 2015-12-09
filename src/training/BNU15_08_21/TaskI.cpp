#include "../../xyiyy/lib.hpp"
const int maxn = 50010 *51;
int To[maxn],Next[maxn],head[50010];
double cost[maxn];
int e;

void add_edge(int u, int v, double d) {
	To[e] = v;
	Next[e] = head[u];
	cost[e] = d;
	head[u] = e++;
}

double dis[50010];
int vis[50010];
int tot;
void spfa(int s, int t, int n) {
	queue<int> q;
	clr(vis,0);
	clr(dis,0);
	dis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(int i = head[x];i!=-1;i=Next[i]){
			int y = To[i];
			double d = cost[i];
			if (dis[x] * d > dis[y]) {
				dis[y] = dis[x] * d;
				if (!vis[y]) {
					q.push(y);
					vis[y] = 1;
				}
			}
		}
	}
}

class TaskI {
public:
	void solve() {
		int n;
		while(scanf("%d",&n)!=EOF)
		{
			e=0;
			clr(head,-1);
			for(int i=1;i<=n;i++)
			{
				int m;
				scanf("%d",&m);
				for(int j=0;j<m;j++)
				{
					int a,b;
					scanf("%d%d",&a,&b);
					add_edge(i,a,1.0-b*1.0/100);
				}
			}
			int s,t,tot;
			scanf("%d%d%d",&s,&t,&tot);
			spfa(s,t,n);
			if(dis[t]==0)
				printf("IMPOSSIBLE!\n");
			else
				printf("%.2f\n",(1-dis[t])*tot);

		}
	}
};