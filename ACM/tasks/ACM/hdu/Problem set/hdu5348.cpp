#include "../../xyiyy/lib.hpp"
const int MAXN = 800010;
int head[MAXN];
int Next[MAXN],To[MAXN];
int vis[MAXN];
int used[100010];
int deg[100010];
int gao;
int tot;
void init(int n){
	tot = 0;
	rep(i,n)head[i] = -1;
}
void addedge(int u,int v){
	Next[tot] = head[u];
	To[tot] = v;
	vis[tot] = 0;
	head[u] = tot++;
}
void eular(int u){
	used[u] = 1;
	int i;
	while(head[u]!=-1){
		i = head[u];
		head[u] = Next[head[u]];
		if(vis[i])continue;
		vis[i^1] = 1;
		eular(To[i]);
	}
}
int Scan() {
	int res=0, ch;
	while(ch=getchar(), ch<'0'||ch>'9');
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
void Out(int a) {
	if(a>9)
		Out(a/10);
	putchar(a%10+'0');
}

class hdu5348 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in>>t;
		while(t--){
			int n,m;
			in>>n>>m;
			init(n);
			rep(i,n)deg[i] = 0;
			int u,v;
			rep(i,m){
				in>>u>>v;
				u--,v--;
				deg[u]++;
				deg[v]++;
				addedge(u,v);
				addedge(v,u);
			}
			gao = -1;
			rep(i,n){
				if(deg[i]&1){
					if(gao!=-1){
						addedge(i,gao);
						addedge(gao,i);
						gao = -1;
					}else gao = i;
				}
			}
			rep(i,n) used[i] = 0;
			rep(i,n){
				if(!used[i]){
					eular(i);
				}
			}
			m<<=1;
			for(int i=0;i<m;i+=2){
				if(!vis[i])out<<1<<endl;
				else out<<0<<endl;
			}

		}
	}
};

