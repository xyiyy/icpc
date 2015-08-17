#include "../../xyiyy/lib.hpp"
int a[410],b[110];
const int MAX_V = 1010;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u,int v)
{
	G[u].pb(v);
	G[v].pb(u);
}

bool dfs(int v)//Ôö¹ãÂ·
{
	used[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[u]=v;
			match[v]=u;
			return 1;
		}
	}
	return false ;
}

int hungary()
{
	int res=0;
	clr(match,-1);
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			clr(used,0);
			if(dfs(v))
			{
				res++;
			}
		}
	}
	return res;
}



class TaskE {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			while(t--){
				int n,m;
				in>>n>>m;
				rep(i,n){
					in>>a[i];
				}
				rep(i,m)in>>b[i];
				set<int>s;
				rep(i,m)s.insert(b[i]);
				rep(i,2*n)G[i].clear();
				V = n;
				rep(i,n){
					rep(j,n){
						if(i==j)continue;
						if(s.count(a[i]+a[j]))add_edge(i,j+n);
					}
				}
				out<<hungary()/2<<endl;
			}
		}
};