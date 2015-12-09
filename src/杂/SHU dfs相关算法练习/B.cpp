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

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
vector<int> G[10001];
int low[10010], dfn[10010];
int vis[10010];
int point[10010];
int n, m, dclock;
int id[10010];
struct ppp {
    int x;
    int y;
} fuc[10010];

/*
void dfs(int u, int fa){
    int son = 0;
    dfn[u] = low[u] = dclock ++;
    for(int i = 0; i < Map[u].size(); i ++){
        int v = Map[u][i];
        if(dfn[v]<0){
            dfs(v, u);
            son ++;
            low[u] = min(low[u], low[v]);
            if((fa < 0 && son > 1) || (fa >= 0 && low[v] >= dfn[u])) cut[u] = 1; //点u为割点
            //if(low[v] > dfn[u]) bri[nbri][0] = u; bri[nbri++][1] = v;   //边(u,v)是桥。
        }else if(low[u] > low[v] && v != fa) low[u] = min(low[u], dfn[v]);
    }
}*/
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++dclock;
    vis[u] = 1;
    int son = 0;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v]) {
            tarjan(v, u);
            son++;
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                point[u]++;
            }
        }
        else if (low[u] > low[v] && v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (fa < 0 && son == 1)point[u] = 0;
}

bool cmp(ppp a, ppp b) {
    if (a.y == b.y)return a.x < b.x;
    return a.y > b.y;
}


int main() {
    ios::sync_with_stdio(false);

    while (cin >> n >> m && (n || m)) {
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
        memset(low, 0, sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        memset(vis, 0, sizeof(vis));
        memset(point, 0, sizeof(point));
        dclock = 0;
//		point[0]=1;
        for (int i = 0; i < n; i++) {
            //	point[i]=1;
            G[i].clear();
        }
        int u, v;
        while (cin >> u >> v) {
            if (u == -1 && v == -1)break;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        tarjan(0, -1);
        //	for(int i=0;i<=n;i++)
        //	cout<<point[i]<<" ";
        //	cout<<endl;
        for (int i = 0; i < n; i++)
            if (point[i] == 0)point[i] = 1;
            else point[i]++;
        for (int i = 0; i < n; i++) {
            fuc[i].x = id[i];
            fuc[i].y = point[i];
        }
        sort(fuc, fuc + n, cmp);
        for (int i = 0; i < m; i++) {
            cout << fuc[i].x << " " << fuc[i].y << endl;
        }
        cout << endl;
    }

    return 0;
}

