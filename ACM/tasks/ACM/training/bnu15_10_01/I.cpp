//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int MAXN  = 500010;
vector<int>G[MAXN];
int dis[MAXN];
int bfs1(int n){
    queue<int> q;
    q.push(0);
    rep(i,n)dis[i] = INF;
    dis[0] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        rep(i,G[x].size()){
            int y = G[x][i];
            if(dis[y]==INF){
                dis[y] = dis[x] + 1;
                q.push(y);
                if(y==n-1)return dis[n-1];
            }
        }
    }
    return dis[n-1];
}
int vis[MAXN];
bool used[MAXN];
int bfs2(int n){
    queue<int >q;
    q.push(0);
    rep(i,n)dis[i] = INF;
    dis[0] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        rep(i,n)used[i] = 1;
        used[x] = 0;
        rep(i,G[x].size())used[G[x][i]] = 0;
        rep(i,n){
            if(!used[i])continue;
            if(dis[i]==INF){
                dis[i] = dis[x] + 1;
                q.push(i);
                if(i==n-1)return dis[n-1];
            }
        }
    }
    return dis[n-1];
}
int main()
{
	ios::sync_with_stdio(false);
    int n,m,a,b;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF){
        rep(i,n)G[i].clear();
        int u,v;
        rep(i,m){
            scanf("%d%d",&u,&v);
            u--;v--;
            G[u].pb(v);
            G[v].pb(u);
        }
        ll x = bfs1(n);
        if(x==INF)x = LONG_LONG_MAX;
        else x *= a;
        ll y = bfs2(n);
        if(y == INF)x = LONG_LONG_MAX;
        else y *= b;
        cout << min(x,y)<<endl;

    }
	return 0;
}


