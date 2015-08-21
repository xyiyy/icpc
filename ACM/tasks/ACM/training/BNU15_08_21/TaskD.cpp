#include "../../xyiyy/lib.hpp"
struct node{
	int u,v,d;
	bool operator <(const node &a)const{
		return d>a.d;
	}
}edge[100010];
int pa[100010];
int f[100010];
int find(int x){
	if(pa[x]!=x)pa[x] = find(pa[x]);
	return pa[x];
}
int unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(f[x]&&f[y])return 1;
	if(f[x])pa[y] = x;
	else pa[x] = y;
	return 0;
}
class TaskD {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			while(t--){
				int n,k;
				in>>n>>k;
				rep(i,n-1){
					in>>edge[i].u>>edge[i].v>>edge[i].d;
				}
				rep(i,n)pa[i] = i;
				int x;
				clr(f,0);
				rep(i,k){
					in>>x;
					f[x] = 1;
				}
				ll ans = 0;
				sort(edge,edge+n-1);
				rep(i,n-1){
					if(unite(edge[i].u,edge[i].v))ans=ans+edge[i].d;
				}
				out<<ans<<endl;
			}
		}
};