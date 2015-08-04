//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define MAXN 100010
vector<int>G[MAXN];
int root;
int size[MAXN];
int tot;
int pa[20][MAXN];
int depth[MAXN];
void dfs(int v,int fa,int d){
	pa[0][v]=fa;
	size[v]=1;
	depth[v]=d;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]==fa)continue;
		dfs(G[v][i],v,d+1);
		size[v]+=size[G[v][i]];
	}
}
void init(){
	dfs(0,-1,0);
	for(int k=0;k+1<19;k++){
		for(int v=0;v<tot;v++){
			if(pa[k][v]<0)pa[k+1][v]=-1;
			else pa[k+1][v]=pa[k][pa[k][v]];
		}
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v])swap(u,v);
	int dis=depth[v]-depth[u];
	for(int k=0;k<19;k++){
		if((dis>>k)&1){	
			v=pa[k][v];
		}
	}
	if(u==v)return u;
	for(int k=19;k>=0;k--){
		if(pa[k][u]!=pa[k][v]){
			u=pa[k][u];
			v=pa[k][v];
		}
	}
	return pa[0][u];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	tot=n;
	int u,v;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init();
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		u--;v--;
		int r=lca(u,v);
		int dis=depth[u]+depth[v]-2*depth[r];
		if(depth[u]>depth[v])swap(u,v);
		if(dis&1){
			cout<<0<<endl;
		}else{
			dis/=2;
			int mid=v;
			for(int k=19;k>=0;k--){
				if((dis>>k)&1){
					mid=pa[k][mid];
				}
			}
			int ans=1;
			if(mid==r){
				int preu=u,prev=v;
				int du=depth[u]-depth[r];
				du--;
				for(int k=19;k>=0;k--){
					if((du>>k)&1){
						preu=pa[k][preu];
					}
				}
				int dv=depth[v]-depth[r];
				dv--;
				for(int k=19;k>=0;k--){
					if((dv>>k)&1){
						prev=pa[k][prev];
					}
				}
				ans=tot-size[preu]-size[prev];
			}else{
				int prev=v,preu=u;
				int dv=depth[v]-depth[mid];
				dv--;
				for(int k=19;k>=0;k--){
					if((dv>>k)&1){
						prev=pa[k][prev];
					}
				}
				ans=size[mid]-size[prev];
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}



