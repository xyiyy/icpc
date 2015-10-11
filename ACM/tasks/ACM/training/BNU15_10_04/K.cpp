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
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

#define MAXN 100000
VII Map[MAXN];
VII Q[MAXN];
int dep[MAXN];
int tot = 0;
int a[MAXN];
int _u[MAXN], _v[MAXN];
int lca[MAXN];
int pa[MAXN];

int find(int u) {
    return pa[u] == -1? u : pa[u] = find(pa[u]);
}

void dfs(int u, int fa = -1) {
    REP(i,Map[u].size()) {
        int v = Map[u][i].X;
        int dir = Map[u][i].Y;
        if(v != fa) {
            a[v] = a[u] + dir;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
    REP(i,Q[u].size()) {
        int v = Q[u][i].X;
        int id = Q[u][i].Y;
        lca[id] = find(v);
    }
    pa[u] = fa;

}

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);

#endif // LOCAL
    int n,q;
    while(~scanf("%d",&n)) {
        REP(i,n){
            Map[i].clear();
            Q[i].clear();
        }
        REP(i,n-1) {
            int u,v;
            scanf("%d%d",&u,&v);
            u--; v--;
            Map[u].PB(MP(v,1));
            Map[v].PB(MP(u,-1));
        }
        int root = (n)/2;
        scanf("%d",&q);
        REP(i,q){
            int u,v;
            scanf("%d%d",&u,&v);
            u--; v--;
            _u[i] = u;
            _v[i] = v;
            Q[u].PB(MP(v,i));
            Q[v].PB(MP(u,i));
        }
        REP(i,n) pa[i] = -1;
        dfs(root);
        a[root] = 0;
        dep[root] = 0;
        REP(i,n)cout << dep[i ] << " ";
        cout << endl;
        REP(i,q){
            int u = _u[i];
            int v = _v[i];
            int l1 = dep[u] - dep[lca[i]];
            int l2 = dep[v] - dep[lca[i]];
            cout <<l1 <<" "<<l2<<endl;
            if(a[u] - a[lca[i]] == -l1
            && a[v] - a[lca[i]] == l2) {
                puts("Yes");
            }else{
                puts("No");
            }
        }

    }
    return 0;
}

