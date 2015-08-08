#include "../../../../library/libhduc++.hpp"
#include "../../../../library/Scanner.hpp"
#define  LLINF (1LL<<62)
int pa[200010];
ll dis[200010];
void init(int n){
	rep(i,n+1){pa[i] =i,dis[i] = LLINF;}
}
int find(int x){
	if(pa[x]!=x)pa[x] = find(pa[x]);
	return pa[x];
}

void unite(int x,int y){
	x = find(x);y = find(y);
	if(x == y)return;
	pa[x] = y;
}

const int MAXN = 200010;
int l[MAXN],r[MAXN],c[MAXN];
typedef pair<ll,int> PLL;
PQ<PLL,vector<PLL>,greater<PLL> >q;
void dijkstra(int s,int n){
	dis[s] = 0;
	q.push(mp(dis[s]+c[s],s));
	while(!q.empty()){
		int x = q.top().second;
		q.pop();
		for(int i=-1;i<=1;i+=2){
			int lx = l[x]*i+x;
			int rx = r[x]*i+x;
			if(lx>rx)swap(lx,rx);
			if(rx<=0||lx>=n)continue;
			lx = max(1,lx);
			rx = min(n-1,rx);
			for(int y=lx;;y++){
				y = find(y);
				if(y>rx)break;
				if(dis[x]+c[x]<dis[y]){
					dis[y] = dis[x] + c[x];
					q.push(mp(dis[y]+c[y],y));
				}
				unite(y,y+1);
			}
		}
	}
}
class hdu5361 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		Scan(n);
		rep(i,n)Scan(l[i]);
		rep(i,n)Scan(r[i]);
		rep(i,n)Scan(c[i]);
		init(n);
		dijkstra(0,n);
		rep(i,n){
			if(i)putchar(' ');
			if(dis[i]!=LLINF)Out(dis[i]);
			else Out(-1);
		}
		putchar('\n');
	}
};