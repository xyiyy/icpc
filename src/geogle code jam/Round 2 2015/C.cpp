#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)


#define MAXN 100010
#define MAXE 200010

struct Edge{
    int u, v;
    ll c, f;
    Edge(){};
    Edge(int _u, int _v, ll _c, ll _f) {
        u=_u; v=_v; c=_c; f=_f;
    }
}edge[MAXE*2];
int n_edge;

VI Map[MAXN];
int last[MAXN];

void init() {
    REP(i,MAXN) Map[i].clear();
    n_edge = 0;
}

int d[MAXN];
int gap[MAXN];
int bfs(int s, int t) {
    int n = 0;
    queue<int> q;
    REP(i,MAXN) d[i] = INF;
    REP(i,MAXN) gap[i] = 0;
    d[t] = 0;
    q.push(t);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        gap[d[u]]++;
        n++;
        REP(i,Map[u].size()) {
            int e=Map[u][i];
            int v=edge[e].v;
            if(edge[e^1].f < edge[e^1].c && d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return n;
}

ll augument(int t) {
    int e = last[t];
    ll fl = INF;
    while(e != -1) {
        int v = edge[e].u;
        fl = min(fl, edge[e].c - edge[e].f);
        e = last[v];
    }
    e = last[t];
    while(e != -1) {
        int v = edge[e].u;
        edge[e].f += fl;
        edge[e^1].f -= fl;
        e = last[v];
    }
    return fl;
}

ll ISAP(int s, int t) {
    ll res = 0;
    int n = bfs(s, t);
    last[s] = -1;
    int u = s;
    while(d[s] < n) {
        if(u == t) {
            res += augument(t);
            u = s;
        }
        int f = 0;
        REP(i, Map[u].size()) {
            int e = Map[u][i];
            int v = edge[e].v;
            if(edge[e].f < edge[e].c && d[u] == d[v] + 1) {
                // advance
                u = v;
                last[v] = e;
                f = 1;
                break;
            }
        }
        if(!f) {
            // retreat
            int _min = n;
            REP(i,Map[u].size()) {
                int e = Map[u][i];
                int v = edge[e].v;
                if(edge[e].f < edge[e].c) _min = min(_min, d[v]);
            }
            if(--gap[d[u]]==0) break;
            d[u] = _min+1;
            gap[d[u]]++;
            if(u != s) u = edge[last[u]].u;
        }
    }
    return res;
}

void addEdge(int u, int v, ll c) {
    edge[n_edge] = Edge(u,v,c,0);
    Map[u].PB(n_edge++);
    edge[n_edge] = Edge(v,u,0,0);
    Map[v].PB(n_edge++);
}

int main()
{
	ios::sync_with_stdio(false);
	//#ifdef LOCAL
		freopen("C-large.in", "r", stdin);
		freopen("c.out", "w", stdout);
	//#endif
	int t,n,cs=1;
	cin>>t;
	while(t--) {
		cin>>n;
		map<string, PII> mp;
		cin.ignore();
		int S = 0, T = 1;
		int cnt = 2;
		init();
		string s;
		REP(i,n) {
			getline(cin,s,'\n');
			stringstream ss(s);

			VI v1, v2;
			while(ss>>s) {
				int id1, id2;
				if(mp.count(s)) {
					id1 = mp[s].X;
					id2 = mp[s].Y;
				}else{
					id1 = cnt++;
					id2 = cnt++;
					addEdge(id1, id2, 1);
					mp[s] = MP(id1,id2);
				}
				if(i==0) {
					addEdge(S,id1,INF);
				}else if(i==1) {
					addEdge(id2,T,INF);
				}
				v1.PB(id1);
				v2.PB(id2);
			}
			if(i>=2) {
				REP(i,v1.size()) {
					REP(j,i) {
						addEdge(v2[i], v1[j], INF);
						addEdge(v2[j], v1[i], INF);
					}
				}
			}
		}
		cout<<"Case #"<<cs++<<": ";
		cout<<ISAP(S,T)<<endl;
	}
	return 0;
}
