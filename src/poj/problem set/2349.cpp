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
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn = 510;
int pa[maxn];
int ra[maxn];
double x[maxn];
double y[maxn];
int vis[maxn];

void init(int n) {
    for (int i = 0; i < n; i++) {
        pa[i] = i;
        ra[i] = 0;
    }
}

int find(int x) {
    if (pa[x] != x)pa[x] = find(pa[x]);
    return pa[x];
}

int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return 0;
    if (ra[x] < ra[y])pa[x] = y;
    else {
        pa[y] = x;
        if (ra[x] == ra[y])ra[x]++;
    }
    return 1;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

struct Edge {
    int u, v;
    double l;

    Edge() { };

    Edge(int _u, int _v, double _len) : u(_u), v(_v), l(_len) { }

    bool operator<(const Edge &e) const {
        return this->l > e.l;
    }
} edge[maxn * maxn];

int e;
stack<Edge> ss;

void addEdge(int u, int v, double len) {
    edge[e++] = Edge(u, v, len);
}

int p;

void Kruskal(int n) {
    init(n);
    priority_queue<Edge> q;
    for (int i = 0; i < e; i++)q.push(edge[i]);
//	int ans=0;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        Edge e = q.top();
        while (same(e.u, e.v) && !q.empty()) {
            q.pop();
            e = q.top();
        }
        unite(e.u, e.v);
        ss.push(e);
        //ans+=e.l;
    }
    //return ans;
}


int main() {
    ios::sync_with_stdio(false);
    int T, s;
    double dis, ans;
    cin >> T;
    while (T--) {
        e = 0;
        ans = 0;
        cin >> s >> p;
        CLR(vis, 0);
        while (!ss.empty())ss.pop();
        for (int i = 0; i < p; i++) {
            cin >> x[i] >> y[i];
        }
        for (int i = 0; i < p; i++) {
            for (int j = i + 1; j < p; j++) {
                dis = sqrt(1.0 * ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
                addEdge(i, j, dis);
                addEdge(j, i, dis);
            }
        }
        Kruskal(p);
        /*while(1)
        {
            Edge e=ss.top();
        //	cout<<e.u<<"   "<<e.v<<"   "<<e.l<<endl;
            if(s&&!vis[e.u])
            {
                vis[e.u]=1;
                s--;
            }
            if(s&&!vis[e.v])
            {
                vis[e.v]=1;
                s--;
            }

            if(vis[e.u]&&vis[e.v])
            {
                e.l=0;
            }
            ans=max(ans,e.l);
            ss.pop();
            if(ans>0.5)break;
        }*/
        while (s) {
            Edge e = ss.top();
            ans = e.l;
            s--;
            ss.pop();
        }
        //ans=Kruskal(p);
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}


